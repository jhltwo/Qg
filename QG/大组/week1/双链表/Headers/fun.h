#ifndef DULINKEDLIST_H_INCLUDED
#define DULINKEDLIST_H_INCLUDED
#define OVERFLOW -1
typedef struct Node{
	int date;
	struct Node* next;
	struct Node* pre;
}Node;
//��ʼ��˫����
Node* initList();
//Ѱ�����ݶ��Ӧ���
Node* find(Node* list);
//ͷ�巨
void headinsert(Node* list);
//β��
void tailinsert(Node* L);
//����
void insert(Node* list,Node* p);
//ɾ��
void delet(Node* list,Node* p);
//����������
void koprintlist(Node* list);
//����
void printlist(Node* L);
void menu();
#endif
