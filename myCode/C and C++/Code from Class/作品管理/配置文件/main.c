#include"list.h"
#include<stdio.h>
#include<stdlib.h>
int main()
{
	List list;
	ListInitiallize(&list);
	Node n1;
	strcpy(n1.item.name,"霍博一的自画像");
	strcpy(n1.item.time,"2022.3.8");
	strcpy(n1.item.tag,"黄油，原神，我的世界");
    strcpy(n1.item.more,"2252");
    Node n2;
	strcpy(n2.item.name,"李思尧的自画像");
	strcpy(n2.item.time,"2022.2.5");
	strcpy(n2.item.tag,"原神，我的世界，数码");
    strcpy(n2.item.more,"114514");
     Node n3;
	strcpy(n3.item.name,"马天驰的自画像");
	strcpy(n3.item.time,"2023.2.1");
	strcpy(n3.item.tag,"原神，我的世界，高等数学");
    strcpy(n3.item.more,"54564645");   
	AddNode2(&list,n1);
	AddNode2(&list,n2);
	AddNode2(&list,n3);
//	PrintList(&list);
	List list2=NodeFind(&list,"霍博一",1);
	PrintList(&list2);
	DeleteList(&list);

	return 0;
}