#ifndef DULINKEDLIST_H_INCLUDED
#define DULINKEDLIST_H_INCLUDED
#define OVERFLOW -1
//�ڵ㶨��
typedef struct QNode{
	void* data;
    struct QNode* next;
}QNode, *QueuePtr;
//��ʽ���ж���
typedef struct LinkQueue{    
	QueuePtr   head;  
	QueuePtr   tail;
	int esize;  //Ԫ�ش�С 
	 
}LinkQueue;
//��ʼ���ж� 
LinkQueue* initQueue(int esize );
//���
void enQueue(LinkQueue* q, void* data);
//����
void deQueue(LinkQueue* q);
//���
void clearQueue(LinkQueue* q);
//�鿴��ͷ
void* getheadQueue(LinkQueue* q);
//�п�
void isemptyQueue(LinkQueue* q);
//���г���
int lengthQueue(LinkQueue* q);
//�������� 
void traverseQueue(LinkQueue* q,void(*printFunc)(void*));
//��������
void printInt(void* data);
//�����ַ� 
void printChar(void* data);
//����������
void printDouble(void* data);
//���� 
void DestoryQueue(LinkQueue* q);
//�˵� 
void menu();
#endif
