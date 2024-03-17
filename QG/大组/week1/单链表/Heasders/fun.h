#ifndef DULINKEDLIST_H_INCLUDED
#define DULINKEDLIST_H_INCLUDED
#define OVERFLOW -1
typedef struct Node{
	int date;
	struct Node* next;
}Node;
//初始化链表
Node* initList();
//头插法
void headInsert(Node* list);
//尾插法
void tailInsert(Node* list);
//找出中间结点
void findmiddle(Node* list);
//非递归反转
void reverse(Node* list);
//寻找数据所对应的结点，以便于插入和删除
Node* find(Node* list); 
//判断链表是否成环
int circle(Node* list);
//奇偶调换
void change(Node* list);
//插入 
void  insert(Node* list,Node* p);
//删除链表
void delet(Node* list,Node* p);
//销毁链表 
//遍历链表
void koprintList(Node* list);
//遍历
void printlist(Node* L);
void menu();
#endif
