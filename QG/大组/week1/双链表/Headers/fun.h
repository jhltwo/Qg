#ifndef DULINKEDLIST_H_INCLUDED
#define DULINKEDLIST_H_INCLUDED
#define OVERFLOW -1
typedef struct Node{
	int date;
	struct Node* next;
	struct Node* pre;
}Node;
//初始化双链表
Node* initList();
//寻找数据多对应结点
Node* find(Node* list);
//头插法
void headinsert(Node* list);
//尾插
void tailinsert(Node* L);
//插入
void insert(Node* list,Node* p);
//删除
void delet(Node* list,Node* p);
//遍历及销毁
void koprintlist(Node* list);
//遍历
void printlist(Node* L);
void menu();
#endif
