#ifndef DULINKEDLIST_H_INCLUDED
#define DULINKEDLIST_H_INCLUDED
#define OVERFLOW -1
typedef struct Node{
	int date;
	struct Node* next;
}Node;
//��ʼ������
Node* initList();
//ͷ�巨
void headInsert(Node* list);
//β�巨
void tailInsert(Node* list);
//�ҳ��м���
void findmiddle(Node* list);
//�ǵݹ鷴ת
void reverse(Node* list);
//Ѱ����������Ӧ�Ľ�㣬�Ա��ڲ����ɾ��
Node* find(Node* list); 
//�ж������Ƿ�ɻ�
int circle(Node* list);
//��ż����
void change(Node* list);
//���� 
void  insert(Node* list,Node* p);
//ɾ������
void delet(Node* list,Node* p);
//�������� 
//��������
void koprintList(Node* list);
//����
void printlist(Node* L);
void menu();
#endif
