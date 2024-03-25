#ifndef DULINKEDLIST_H_INCLUDED
#define DULINKEDLIST_H_INCLUDED
#define OVERFLOW -1
//节点定义
typedef struct QNode{
	void* data;
    struct QNode* next;
}QNode, *QueuePtr;
//链式队列定义
typedef struct LinkQueue{    
	QueuePtr   head;  
	QueuePtr   tail;
	int esize;  //元素大小 
	 
}LinkQueue;
//初始化列队 
LinkQueue* initQueue(int esize );
//入队
void enQueue(LinkQueue* q, void* data);
//出队
void deQueue(LinkQueue* q);
//清空
void clearQueue(LinkQueue* q);
//查看队头
void* getheadQueue(LinkQueue* q);
//判空
void isemptyQueue(LinkQueue* q);
//队列长度
int lengthQueue(LinkQueue* q);
//遍历队列 
void traverseQueue(LinkQueue* q,void(*printFunc)(void*));
//遍历整型
void printInt(void* data);
//遍历字符 
void printChar(void* data);
//遍历浮点型
void printDouble(void* data);
//销毁 
void DestoryQueue(LinkQueue* q);
//菜单 
void menu();
#endif
