#ifndef DULINKEDLIST_H_INCLUDED
#define DULINKEDLIST_H_INCLUDED
#define OVERFLOW -1
typedef struct Node{
	int data;
	struct Node* left;
	struct Node* right;
}Node,Nodepre;
typedef struct StackNode{
	int data;
	Node* newnode;
	struct StackNode* next;
}StackNode, *LinkStackPtr;
typedef struct LinkStack
{
	LinkStackPtr top;	  //栈顶指针
	int	count;  //栈中元素个数
}LinkStack;
//队列  
typedef struct QueueNode {  
    Node *data;  
    struct QueueNode *next;  
} QueueNode;  

// 定义队列  
typedef struct {  
    QueueNode *front;  
    QueueNode *rear;  
} Queue; 
// 初始化队列  
void initQueue(Queue *q) ;
// 判断队列是否为空  
int isQueueEmpty(Queue *q);
// 入队操作  
void enqueue(Queue *q, Node *newnode);
// 出队操作  
Node *dequeue(Queue *q) ;
//层次排序 
void levelorder(Node *node) ;
//栈初始化 
LinkStack* initStack();
//创建
void init(Node* node);
//进栈
void push(LinkStack* s,Node* newnode);
//出栈 
Node* pop(LinkStack* s);
//非递归先序
void preorder(Node* node);
//非递归中序
void Inororder(Node* node);
//非递归后序遍历
void Postorder(Node* node);
//先序遍历 
void pretraverse(Node* node);
//中序遍历
void Inortraverse(Node* node);
//后序遍历
void Posttraverse(Node* node);
//插入
void Insert(Node* node);
//查找
void find(Node* node);
//删除
void delet(Node* node);
void menu();
#endif
