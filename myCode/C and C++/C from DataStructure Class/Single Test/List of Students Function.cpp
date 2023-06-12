#include <stdio.h>
#include <stdlib.h>

//结构体定义
struct Student {
	long num;
	float score;
	struct Student *next;
};

//主函数
int main() {
	struct Student *creatStuLink(long int *num, float * score, int n);
	void releaseStuLink(struct Student * pHead);
	void printStuLink(struct Student * Head);
	void inputStuLink(struct Student **Head);
//各种数据的定义
	long int nu[5] = {9220101, 9220102, 9220108, 9220111, 9220115};
	struct Student *Head = NULL;
	char J;
	float sc[5] = {98, 77, 67.5, 88.5, 89};
	int length = sizeof(sc) / sizeof(sc[0]);
//创建链表
	printf("Lording......\n");
	Head = creatStuLink(nu, sc, length);
	printf("Down!!!\n");
//选择
	printf("Print?(Y or N)\n");
	do {
		printf("->");
		J = getchar();
	} while (J != 'Y' && J != 'N');
//打印并FREE
	switch (J) {
		case 'Y':
			printStuLink(Head);
			releaseStuLink(Head);
			break;
		case 'N':
			releaseStuLink(Head);
			break;
	}
	printf("Result after freeing：\n[%d] [%.1f]\n", Head->num, Head->score );
	return 0;
}


//函数1，插入链表
void inputStuLink(struct Student **list, int num, float score) {

	if (*list == NULL) {
		*list = (struct Student *)malloc(sizeof(struct Student));
		if (*list == NULL) {
			printf("Fail!！");
			exit(1);
		}
		(*list)->num = num;
		(*list)->score = score;
		(*list)->next = NULL;

	} else {
		struct Student *temp = (struct Student *)malloc(sizeof(struct Student));
		if (temp == NULL) {
			printf("申请内存失败！");
			exit(1);
		}
		temp->num = num;
		temp->score = score;
		temp->next = (*list);
		(*list) = temp;
	}
}
//函数2，创建所有链表
struct Student *creatStuLink(long int *num, float *score, int n) {
	struct Student *Head = NULL;

	for (int i = 0; i < n; i++) {
		inputStuLink(&Head, num[i], score[i]);
	}

	return Head;
}
//函数3，释放申请的内存
void releaseStuLink(struct Student *pHead) {

	do {
		struct Student *temp = pHead->next ;
		free(pHead);
		pHead = temp;
	} while (pHead != NULL);
}
//打印链表
void printStuLink(struct Student *Head) {

	for (; Head != NULL;) {
		printf("[%d] [%.1f]\n", Head->num, Head->score );
		Head = Head->next ;
	}
}