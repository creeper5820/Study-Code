#include"list.h"
#include<stdio.h>
#include<stdlib.h>
int main()
{
	List list;
	ListInitiallize(&list);
	Node n1;
	strcpy(n1.item.name,"����һ���Ի���");
	strcpy(n1.item.time,"2022.3.8");
	strcpy(n1.item.tag,"���ͣ�ԭ���ҵ�����");
    strcpy(n1.item.more,"2253");
    Node n2;
	strcpy(n2.item.name,"��˼Ң���Ի���");
	strcpy(n2.item.time,"2022.2.5");
	strcpy(n2.item.tag,"ԭ���ҵ����磬����");
    strcpy(n2.item.more,"23423253");
    Node n3;
	strcpy(n3.item.name,"����۵��Ի���");
	strcpy(n3.item.time,"2023.2.1");
	strcpy(n3.item.tag,"ԭ���ҵ����磬�ߵ���ѧ");
    strcpy(n3.item.more,"54564645");   
	AddNode2(&list,n1);
	AddNode2(&list,n2);
	AddNode2(&list,n3);
//	PrintList(&list);
//	List list2=NodeFind(&list,"253",4);
    List list2;
    List temp=list;
    PrintList(&list);
    while(temp!=NULL)
    {
    	AddNode2(&list2,*temp);
    	temp=temp->next;
	}
	PrintList(&list2);
	DeleteList(&list);

	return 0;
}
