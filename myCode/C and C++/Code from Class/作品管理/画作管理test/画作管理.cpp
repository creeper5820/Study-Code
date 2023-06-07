//�ļ�����
//��������ϵͳ
//ʱ�䣬��ע������ѯ���ܣ�tag
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <dirent.h>

struct message {
	char name[50];
	char tag[100];
	char more[100];
	struct message *next;
};

int main() {
	void DirentToMessage(DIR * dir_p, struct message **head);
	void FileToMessage(struct message **head, FILE * fp);
	void MessageToFile(struct message * head, FILE * fp);
	void WriteMessage(struct message * file);
	void ReadMessage(struct message * head);
	void Add(struct message **head, struct dirent * address_p);
	void input(struct message * MES, struct dirent * address_p);
	void file_scan(void);

	struct message *head = NULL;
	FILE *fp;
	fp = fopen("�ļ���Ϣ.txt", "r+");
	fclose(fp);
	return 0;

}

//dirָ�����룬�ļ�ɨ�裬�ж�tag��more�Ƿ�Ϊ�գ��Զ���ӱ��
void file_scan(void) {

	char c;
	FILE *fp;
	DIR *dir_p = opendir("./");

	fp = fopen("�ļ���Ϣ.txt", "w+");
	struct dirent *address_p;
	while ((address_p = readdir(dir_p)) != NULL) {

	}
}

//dirent���룬�����������λ����
void input(struct message *MES, struct dirent *address_p) {
	strcpy(MES->name, address_p->d_name);
	strcpy(MES->tag, "000");
	strcpy(MES->more, "000");
}

//�������ӡ����
void ReadMessage(struct message *head) {
	struct message *read;
	read = head;

	while (read != NULL) {
		printf("[name]%s\n", read->name );
		printf("[tag ]%s\n", read->tag );
		printf("[more]%s\n", read->more );
		printf("-------\n");
		read = read->next;
	}
}
//dirent�ṹ�����룬��ӵ������У����ļ���
void Add(struct message **head, struct dirent *address_p) {
	struct message *MES = (struct message *)malloc(sizeof(message));
	struct message *temp;

	input(MES, address_p);

	if (*head == NULL) {
		*head = MES;
		(*head)->next = NULL;

	} else {
		temp = *head;
		*head = MES;
		MES->next = temp;
	}
}


//�������룬�޸�������Ϣ
void WriteMessage(struct message *file) {

}
//�������룬�����������txt
void MessageToFile(struct message *head, FILE *fp) {
	struct message *MES = head;

	while (MES != NULL) {
		fprintf(fp, "|[name]%s[tag]%s[more]%s", MES->name, MES->tag, MES->more);
		MES = MES->next;
	}
}
//txt���룬������䲢����������ʼ����
void FileToMessage(struct message **head, FILE *fp) {
	char c = getc(fp);
	int i;
	struct message *MES = (struct message *)malloc(sizeof(message));
	MES->next = NULL;
	while (1) {
		for (; c != '|'; c = fgetc(fp));
		for (; c != ']'; c = fgetc(fp));
		c = fgetc(fp);
		i = 0;

		while (c != '[') {

			MES->name[i] = c;
			c = fgetc(fp);
			i++;
		}
		MES->name[i] = '\0';
		for (; c != ']'; c = fgetc(fp));
		c = fgetc(fp);
		i = 0;

		while (c != '[') {
			MES->tag[i] = c;
			c = fgetc(fp);
			i++;
		}
		MES->tag[i] = '\0';
		for (; c != ']'; c = fgetc(fp));
		c = fgetc(fp);
		i = 0;

		while (c != EOF && c != '[' && c != '|') {

			MES->more[i] = c;
			c = fgetc(fp);
			i++;
		}
		MES->more[i] = '\0';
		if (c == EOF)
			break;
		struct message *temp = (struct message *)malloc(sizeof(message));
		temp->next = MES;
		MES = temp;
	}
	*head = MES;
}
//dirָ�����룬������������ɨ���ļ���
void DirentToMessage(DIR *dir_p, struct message **head) {
	struct dirent *mes;
	while ((mes = readdir(dir_p)) != NULL) {
		if (mes->d_name[0] != '.')
			Add(head, mes);
	}
}