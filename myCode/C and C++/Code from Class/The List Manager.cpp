#include <stdio.h>
#include <stdlib.h>

//暗杀名单格式
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
		printf("是否输入死者信息（Y/N）\n");
		do {
			c = getchar();
		} while (c != 'Y' && c != 'N');

		if (c == 'Y')
			add(&list);
		else
			break;
	}

	system("cls");

	printf("是否输出死者名单（Y/N）\n");
	do {
		c = getchar();
	} while (c != 'Y' && c != 'N');
	if (c  == 'Y')
		print_death(&list);

	realse(list);
	system("pause");
	return 0;
}


//名单输入
void input(struct death *people) {
	printf("请输入死者名字：\n");
	scanf("%s", people->name);
	printf("请输入死亡时间：\n");
	scanf("%s", people->time);
	printf("该死者输入完毕。\n");
}
//名单添加
void add(struct death **list) {
	struct death *people;
	struct death *temp;
	people = (struct death *)malloc(sizeof(struct death));

	if (people == NULL) {
		printf("内存不足，无法申请储存空间。\n");
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
//名单打印
void print_death(struct death **p) {
	struct death *people;
	people = *p;
	int count = 0;
	while (people != NULL) {
		printf("—第%d个死者信息\n", count + 1);
		printf("Name:%s\n", people->name);
		printf("Time:%s\n", people->time);
		people = people->next;
		count++;
	}
}
//内存释放
void realse(struct death *p) {
	while (p != NULL) {
		free(p);
		p = p->next;
	}
}