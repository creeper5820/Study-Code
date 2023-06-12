#include <stdio.h>
#include <stdlib.h>

//�ṹ�嶨��
struct Student {
	long num;
	float score;
	struct Student *next;
};

//������
int main() {
	struct Student *creatStuLink(long int *num, float * score, int n);
	void releaseStuLink(struct Student * pHead);
	void printStuLink(struct Student * Head);
	void inputStuLink(struct Student **Head);
//�������ݵĶ���
	long int nu[5] = {9220101, 9220102, 9220108, 9220111, 9220115};
	struct Student *Head = NULL;
	char J;
	float sc[5] = {98, 77, 67.5, 88.5, 89};
	int length = sizeof(sc) / sizeof(sc[0]);
//��������
	printf("Lording......\n");
	Head = creatStuLink(nu, sc, length);
	printf("Down!!!\n");
//ѡ��
	printf("Print?(Y or N)\n");
	do {
		printf("->");
		J = getchar();
	} while (J != 'Y' && J != 'N');
//��ӡ��FREE
	switch (J) {
		case 'Y':
			printStuLink(Head);
			releaseStuLink(Head);
			break;
		case 'N':
			releaseStuLink(Head);
			break;
	}
	printf("Result after freeing��\n[%d] [%.1f]\n", Head->num, Head->score );
	return 0;
}


//����1����������
void inputStuLink(struct Student **list, int num, float score) {

	if (*list == NULL) {
		*list = (struct Student *)malloc(sizeof(struct Student));
		if (*list == NULL) {
			printf("Fail!��");
			exit(1);
		}
		(*list)->num = num;
		(*list)->score = score;
		(*list)->next = NULL;

	} else {
		struct Student *temp = (struct Student *)malloc(sizeof(struct Student));
		if (temp == NULL) {
			printf("�����ڴ�ʧ�ܣ�");
			exit(1);
		}
		temp->num = num;
		temp->score = score;
		temp->next = (*list);
		(*list) = temp;
	}
}
//����2��������������
struct Student *creatStuLink(long int *num, float *score, int n) {
	struct Student *Head = NULL;

	for (int i = 0; i < n; i++) {
		inputStuLink(&Head, num[i], score[i]);
	}

	return Head;
}
//����3���ͷ�������ڴ�
void releaseStuLink(struct Student *pHead) {

	do {
		struct Student *temp = pHead->next ;
		free(pHead);
		pHead = temp;
	} while (pHead != NULL);
}
//��ӡ����
void printStuLink(struct Student *Head) {

	for (; Head != NULL;) {
		printf("[%d] [%.1f]\n", Head->num, Head->score );
		Head = Head->next ;
	}
}