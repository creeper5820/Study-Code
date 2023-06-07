/*list.h*/
#include <stdbool.h>
#include <stdio.h>
#include <dirent.h>
#ifndef _LIST_H_
#define _LIST_H_
#define MAX 50

//һ��Ŀ¼��Ϣ�ṹ��Ķ���
typedef struct dirent Dir;

//������Ϣ����
struct draw {
	char name[MAX];
	char time[MAX];
	char tag[MAX];
	char more[MAX];
};
typedef struct draw Item;

//�ڵ㶨��
struct node {
	Item item;
	struct node *next;
};
typedef struct node Node;
typedef Node *List;




/*--------------------������Ĳ�������--------------------*/


//�������ж������Ƿ�Ϊ��
//ǰ��������plistָ��һ������
//��������������Ϊ�գ�����true����֮false
bool EmptyJudge(const List *plist);

//�ж������Ƿ�Ϊ��
//ǰ��������plistָ��һ������
//��������������Ϊ��������true����֮false
bool FullJudge(const List *plist);

//��ʼ������
//ǰ��������plistָ��һ������
//���������������ʼ��Ϊ��
void ListInitiallize(List *plist);

//�������
//ǰ��������plistָ��һ������
//����������������ĩ������һ��Node
void AddNode1(List *plist);

//�������
//ǰ��������plistָ��һ������,һ��node������
//����������������ĩ������һ��Node
void AddNode2(List *plist,Node temp);

//�ͷ�����
//ǰ��������plistָ��һ������
//�����������������
void DeleteList(const List *plist);

//ͳ�ƽڵ�
//ǰ������:plistָ��һ������
//�����������ú������ؽڵ������
int CountNode(const List *plist);

//��ӡ����
//ǰ��������plistָ��һ������
//������������ӡ������
void PrintList(const List *plist);

//�ڵ㽻��
//ǰ������������ָ��ڵ��ָ��
//���������������ڵ��λ�ý���
void ExchangeNode(Node *pnode_1,Node *pnode_2);

//�ڵ�ɾ��
//ǰ��������һ��ָ��ָ��ڵ��ָ���ָ��
//�����������ýڵ�ɾ����ǰ��ڵ�����
void DeleteNode(Node **pnode);

//�ڵ���������
//ǰ��������һ��ָ��ڵ��ָ��
//�����������޸ĸýڵ���Item������
void InputItem(Node *node);

//���ҽڵ�(�����Ϣ����)
//ǰ��������һ��ָ�������ָ�룬һ��ָ���ַ�����ָ��,һ��int����
//�������������ղ�ͬ��Item��Ŀ����Node������ָ���Node��ָ��
Node *NodeFind(const List *plist, const char *string,int n);

//�ڵ���Ϣ��ʾ
//ǰ��������һ��ָ��Node��ָ��
//��������������Ļ�ϴ�ӡ��Node�µ�Item��Ϣ
void PrintNode(Node *pnode);





/*--------------------��Dirent��Ϣ������Ĳ�������--------------------*/


//�ļ����ƿ������ڵ���
//ǰ��������һ��ָ��ڵ��ָ�룬ָ��һ���ļ���ַ�ַ�����ָ��
//����������dirent����Ϣ�е��ļ����ƿ�����Item�е�name
void DirentToNode(const Node *node, const char *address);

//ɨ��Ŀ¼
//ǰ��������ָ��һ���ļ���ַ�ַ�����ָ��
//����������Ѱ�Ҳ��������е�dirent���ļ����ƣ����Զ����������
bool DirentFind(const char *address);




/*--------------------���ļ�������Ĳ�������--------------------*/



//�����ʼ��
//ǰ��������һ��ָ�������ָ�룬һ��ָ���ļ���ָ��
//�����������ļ��е���Ϣ�������ڴ����γ�����,�ɹ�����true����֮false
bool AllFileToList(const FILE *fp, const List *plist);

//������Ϣ����
//ǰ��������һ��ָ�������ָ�룬һ��ָ���ļ���ָ��
//���������������е���Ϣ���浽�ļ��У��ɹ��򷵻�true����֮false
bool AllListToFile(const FILE *fp,const  List *PList);

//�½��ļ�
//ǰ��������һ��ָ�������ָ�룬�û�ѡ��ѡ�������Ϣ����ͬ����
//������������ģ���и���һ��ѡ�й����ļ������������д�����ӦNode
void FileCreate(const List *plist);

//ɾ���ļ�
//ǰ��������һ��ָ��ڵ��ָ��
//����������ѡ���ļ�ɾ�����ڵ�ɾ����ǰ��ڵ���ӣ���������վ��
void DeleteFile(const Node *node);

//�ļ����
//ǰ��������ָ���ļ������ַ�����ָ���飬ָ���ַ�ַ�����ָ��
//������������ָ���ļ����Ƶ�ָ��λ��
void FileSave(const char *name[], const char *address);



#endif