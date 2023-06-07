#include <stdio.h>
#include <stdlib.h>

//��ɱ������ʽ
struct death {
	char name[40];
	char time[20];
	struct death *next;
};

int main() {
	void input(struct death * people);
	void add(struct death **list);
	void print_death(struct death **p);
	void realse(struct death * p);

	struct death *list;
	list = NULL;
	char c;

	while (1) {
		printf("�Ƿ�����������Ϣ��Y/N��\n");
		do {
			c = getchar();
		} while (c != 'Y' && c != 'N');

		if (c == 'Y')
			add(&list);
		else
			break;
	}

	system("cls");

	printf("�Ƿ��������������Y/N��\n");
	do {
		c = getchar();
	} while (c != 'Y' && c != 'N');
	if (c  == 'Y')
		print_death(&list);

	realse(list);
	system("pause");
	return 0;
}


//��������
void input(struct death *people) {
	printf("�������������֣�\n");
	scanf("%s", people->name);
	printf("����������ʱ�䣺\n");
	scanf("%s", people->time);
	printf("������������ϡ�\n");
}
//�������
void add(struct death **list) {
	struct death *people;
	struct death *temp;
	people = (struct death *)malloc(sizeof(struct death));

	if (people == NULL) {
		printf("�ڴ治�㣬�޷����봢��ռ䡣\n");
		exit(1);
	}
	input(people);

	if (*list != NULL) {
		temp = *list;
		*list = people;
		people->next = temp;

	} else {
		*list = people;
		people->next = NULL;
	}
}
//������ӡ
void print_death(struct death **p) {
	struct death *people;
	people = *p;
	int count = 0;
	while (people != NULL) {
		printf("����%d��������Ϣ\n", count + 1);
		printf("Name:%s\n", people->name);
		printf("Time:%s\n", people->time);
		people = people->next;
		count++;
	}
}
//�ڴ��ͷ�
void realse(struct death *p) {
	while (p != NULL) {
		free(p);
		p = p->next;
	}
}