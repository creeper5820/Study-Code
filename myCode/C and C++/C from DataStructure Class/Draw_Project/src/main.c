#include"list.h"
#include<stdio.h>
#include<stdlib.h>
int main()
{
	List list;
	ListInitiallize(&list);


	Node n1;
	strcpy(n1.item.name,"ԭ��");
	strcpy(n1.item.time,"2019.1.1");
	strcpy(n1.item.tag,"�����أ��軪");
    strcpy(n1.item.more,"2253");
    Node n2;
	strcpy(n2.item.name,"������");
	strcpy(n2.item.time,"2015.1.1");
	strcpy(n2.item.tag,"����ϣ�ǣ��������ǣ��߶��ء���");
    strcpy(n2.item.more,"23423253");
    Node n3;
	strcpy(n3.item.name,"�������������");
	strcpy(n3.item.time,"2023.2.1");
	strcpy(n3.item.tag,"�������߶��ء���");
    strcpy(n3.item.more,"54564645");   


	AddNode2(&list,n1);
	AddNode2(&list,n2);
	AddNode2(&list,n3);


	PrintList(&list);

	List list2=NodeFind(&list,"�߶��ء���",3);


    printf("\n\n\n\n");

	PrintList(&list2);

	DeleteList(&list);
    DeleteList(&list2);


	return 0;
}
