/*list.h*/
#include <stdbool.h>
#include <stdio.h>
#include <dirent.h>
#ifndef _LIST_H_
#define _LIST_H_
#define MAX 50

//一个目录信息结构体的定义
typedef struct dirent Dir;

//画作信息定义
struct draw {
	char name[MAX];
	char time[MAX];
	char tag[MAX];
	char more[MAX];
};
typedef struct draw Item;

//节点定义
struct node {
	Item item;
	struct node *next;
};
typedef struct node Node;
typedef Node *List;




/*--------------------对链表的操作函数--------------------*/


//操作：判断链表是否为空
//前置条件：plist指向一个链表
//后置条件：链表为空，返回true，反之false
bool EmptyJudge(const List *plist);

//判断链表是否为满
//前置条件：plist指向一个链表
//后置条件：链表为满，返回true，反之false
bool FullJudge(const List *plist);

//初始化链表
//前置条件：plist指向一个链表
//后置条件：链表初始化为空
void ListInitiallize(List *plist);

//添加链表
//前置条件：plist指向一个链表
//后置条件：在链表末端增加一个Node
void AddNode1(List *plist);

//添加链表
//前置条件：plist指向一个链表,一个node型数据
//后置条件：在链表末端增加一个Node
void AddNode2(List *plist,Node temp);

//释放链表
//前置条件：plist指向一个链表
//后置条件：链表清空
void DeleteList(const List *plist);

//统计节点
//前置条件:plist指向一个链表
//后置条件：该函数返回节点的数量
int CountNode(const List *plist);

//打印链表
//前置条件：plist指向一个链表
//后置条件：打印该链表
void PrintList(const List *plist);

//节点交换
//前置条件：两个指向节点的指针
//后置条件：两个节点的位置交换
void ExchangeNode(Node *pnode_1,Node *pnode_2);

//节点删除
//前置条件：一个指向指向节点的指针的指针
//后置条件：该节点删除，前后节点连接
void DeleteNode(Node **pnode);

//节点数据输入
//前置条件：一个指向节点的指针
//后置条件：修改该节点中Item的数据
void InputItem(Node *node);

//查找节点(亦空信息查找)
//前置条件：一个指向链表的指针，一个指向字符串的指针,一个int型数
//后置条件：按照不同的Item项目查找Node，返回指向该Node的指针
Node *NodeFind(const List *plist, const char *string,int n);

//节点信息显示
//前置条件：一个指向Node的指针
//后置条件：在屏幕上打印该Node下的Item信息
void PrintNode(Node *pnode);





/*--------------------对Dirent信息和链表的操作函数--------------------*/


//文件名称拷贝到节点中
//前置条件：一个指向节点的指针，指向一个文件地址字符串的指针
//后置条件：dirent类信息中的文件名称拷贝到Item中的name
void DirentToNode(const Node *node, const char *address);

//扫描目录
//前置条件：指向一个文件地址字符串的指针
//后置条件：寻找不在链表中的dirent类文件名称，并自动添加至链表
bool DirentFind(const char *address);




/*--------------------对文件和链表的操作函数--------------------*/



//链表初始化
//前置条件：一个指向链表的指针，一个指向文件的指针
//后置条件：文件中的信息拷贝到内存中形成链表,成功返回true，反之false
bool AllFileToList(const FILE *fp, const List *plist);

//链表信息储存
//前置条件：一个指向链表的指针，一个指向文件的指针
//后置条件：链表中的信息储存到文件中，成功则返回true，反之false
bool AllListToFile(const FILE *fp,const  List *PList);

//新建文件
//前置条件：一个指向链表的指针，用户选择选项，输入信息（非同名）
//后置条件：从模版中复制一份选中规格的文件，并在链表中创建相应Node
void FileCreate(const List *plist);

//删除文件
//前置条件：一个指向节点的指针
//后置条件：选中文件删除，节点删除，前后节点相接（移至回收站）
void DeleteFile(const Node *node);

//文件另存
//前置条件：指向文件名称字符串的指针组，指向地址字符串的指针
//后置条件：将指定文件复制到指定位置
void FileSave(const char *name[], const char *address);



#endif