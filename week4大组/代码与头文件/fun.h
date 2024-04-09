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
	LinkStackPtr top;	  //ջ��ָ��
	int	count;  //ջ��Ԫ�ظ���
}LinkStack;
//����  
typedef struct QueueNode {  
    Node *data;  
    struct QueueNode *next;  
} QueueNode;  

// �������  
typedef struct {  
    QueueNode *front;  
    QueueNode *rear;  
} Queue; 
// ��ʼ������  
void initQueue(Queue *q) ;
// �ж϶����Ƿ�Ϊ��  
int isQueueEmpty(Queue *q);
// ��Ӳ���  
void enqueue(Queue *q, Node *newnode);
// ���Ӳ���  
Node *dequeue(Queue *q) ;
//������� 
void levelorder(Node *node) ;
//ջ��ʼ�� 
LinkStack* initStack();
//����
void init(Node* node);
//��ջ
void push(LinkStack* s,Node* newnode);
//��ջ 
Node* pop(LinkStack* s);
//�ǵݹ�����
void preorder(Node* node);
//�ǵݹ�����
void Inororder(Node* node);
//�ǵݹ�������
void Postorder(Node* node);
//������� 
void pretraverse(Node* node);
//�������
void Inortraverse(Node* node);
//�������
void Posttraverse(Node* node);
//����
void Insert(Node* node);
//����
void find(Node* node);
//ɾ��
void delet(Node* node);
void menu();
#endif
