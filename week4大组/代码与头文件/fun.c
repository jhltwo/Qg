#include<stdio.h>
#include<stdlib.h>
#include"fun.h"
  
// 初始化队列  
void initQueue(Queue *q) {  
    q->front = q->rear = NULL;  
}  
// 判断队列是否为空  
int isQueueEmpty(Queue *q) {  
    return q->front == NULL;  
}  
// 入队操作  
void enqueue(Queue *q, Node *newnode) {  
    QueueNode *current = (QueueNode *)malloc(sizeof(QueueNode));  
    current->data = newnode;  
    current->next = NULL;  
    if (q->rear == NULL) {  
        q->front = q->rear = current;  
    } else {  
        q->rear->next = current;  
        q->rear = current;  
    }  
}  
  
// 出队操作  
Node *dequeue(Queue *q) {  
    if (isQueueEmpty(q)) {  
        return NULL;  
    }  
    QueueNode *temp = q->front;  
    Node *data = temp->data;  
    q->front = q->front->next;  
    if (q->front == NULL) {  
        q->rear = NULL;  
    }  
    free(temp);  
    return data;  
}
//层次排序 
void levelorder(Node *node) {  
    if (node == NULL) {  
        return;  
    }  
    Queue q;  
    initQueue(&q);  
    enqueue(&q, node);  
    while (!isQueueEmpty(&q)) {  
        Node *newnode = dequeue(&q);  
        printf("%d ", newnode->data );  
        if (newnode->left) {  
            enqueue(&q, newnode->left);  
        }  
        if (newnode->right) {  
            enqueue(&q, newnode->right);  
        }  
    }  
}
//栈初始化 
LinkStack* initStack(){
	LinkStack* s = (LinkStack*)malloc(sizeof(LinkStack));
	s->count  = 0;
	s->top = NULL;
	return s;
}
//创建
void init(Node* node){
	int data;
	printf("\n输入根数据\n");
	scanf("%d",&data);
	node->data = data;
	node->left = NULL;
	node->right = NULL;
} 
//进栈
void push(LinkStack* s,Node* newnode){
	StackNode* p = (StackNode*)malloc(sizeof(StackNode));
	p->newnode  = newnode;
	p->next = s->top ;
	s->top = p;
	s->count ++;
} 
//出栈 
Node* pop(LinkStack* s){
	if(s->top == NULL){
		printf("该栈为空\n");
	}
	StackNode* p = s->top ;
	Node* newnode = p->newnode   ; 
	s->top = s->top->next ; 
	free(p);
	s->count --;
	return newnode;
}
//非递归先序
void preorder(Node* node){
	if(node == NULL) return;
	LinkStack* s;
	s = initStack();
	push(s,node );
	while(s->count != 0){
		Node* newnode = pop(s);
		printf("%d",newnode->data );
		if(newnode->right != NULL){
			push(s,newnode->right );
		} 
		if(newnode->left != NULL){
			push(s,newnode->left );
		}
	}
} 
//非递归中序
void Inororder(Node* node){
	if(node == NULL) return ;
	LinkStack* s;
	s = initStack();
	Node* current = node;
	while(current != NULL || s->count != 0){
		while(current != NULL){
			push(s,current);
			current = current->left ;
		}
		current = pop(s);
		printf("%d",current->data );
		current = current->right ;
	}
} 
//非递归后序遍历
void Postorder(Node* node){
	if(node == NULL) return;
	LinkStack *s1,*s2 ;
	s1 = initStack();
	s2 = initStack();
	push(s1,node);
	Node* newnode = (Node*)malloc(sizeof(Node));
	while(s1->count != 0){
		newnode = pop(s1);
		push(s2,newnode);
		if(newnode->left  != NULL ){
			push(s1,newnode->left );
		}
		if(newnode->right != NULL ){
			push(s1,newnode->right );
		}
	}
	while(s2->count != 0){
		Node* newnode = pop(s2);
		printf("%d",newnode->data ); 
	}
} 
//先序遍历 
void pretraverse(Node* node){
	if(node == NULL) return ;
	printf("%d",node->data );
	pretraverse(node->left );
	pretraverse(node->right ); 
}
//中序遍历
void Inortraverse(Node* node){
	if(node == NULL) return ;
	Inortraverse(node->left );	
	printf("%d",node->data );
	Inortraverse(node->right );
} 
//后序遍历
void Posttraverse(Node* node){
	if(node == NULL) return ;
	Posttraverse(node->left );
	Posttraverse(node->right );
	printf("%d",node->data );
} 
//插入
void Insert(Node* node){
	int data;
	printf("\n输入要插入的数据\n");
	scanf("%d",&data);
	getchar();
	Node* parent;
	Node* head = node;
	Node* p = (Node*)malloc(sizeof(Node));
	p->data = data;
	p->left = NULL;
	p->right = NULL;
	while(head){
		parent = head;
		if(head->data > data){
			head = head->left ;
		}
		else if (head->data < data){
			head = head->right ;
		}
		else {
			printf("结点存在\n");
			free(p);
			return ;
		}
	} 
	if(data > parent->data ){
		parent->right = p;
	}
	else{
		parent->left = p;
	}
} 
//查找
void find(Node* node){
	int data;
	printf("\n输入要查找的数据\n");
	scanf("%d",&data);
	Node* head = node;
	Node* p = (Node*)malloc(sizeof(Node));
	p->data = data;
	p->left = NULL;
	p->right = NULL;
	int flag = 0;
	while(head){
		if(head->data == data){
			flag = 1;
			printf("\n存在\n");
			break;
		}
		else if(head->data > data){
			head = head->left ;
		}
		else{
			head = head->right ; 
		}
	} 
	if(flag == 0){
		printf("不存在\n");
	}
} 
//删除
void delet(Node* node){
	int data;
	printf("\n输入要删除的数据\n");
	scanf("%d",&data);
	Node *L,*LL;
	Node* p = node;
	Node* parent = node;
	int child = 0;
	if(node == NULL) return;
	while(p){
		//找到结点 
		if(p->data == data){
			if(p->left == NULL && p->right ==NULL){
				//只有根结点的时候 
				if(p == node){
					free(p);
				}
				//p结点在左边而且没有子结点 
				else if(child == 0 ){
					parent->left =NULL;
					free(p);
				}
				//p结点在右边而且没有子结点 
				else{
					parent->right = NULL;
					free(p);
				}
			}
			//所找到的结点只有右孩 
			else if(p->left == NULL){
				//结点在左半 
				if(child == 0){
					parent->left = p->right  ;
				}
				//结点在右半 
				else{
					parent->right = p->right  ;
				}
				free(p);
			}
			//所找到结点只有左孩 
			else if(p->right == NULL){
				//在左半 
				if(child == 0){
					parent->left = p->left  ;
				}
				//在右半 
				else{
					parent->right = p->left  ;
				}
				free(p);
			}
			//所找到的结点有左右孩 
			else{
				LL = p;
				L = p->right ;
				if(L->left != NULL){
				
					for(;L->left != NULL ;L = L->left ){
						LL = L ;
					}
					p->data = L->data ;
					LL->left = L->left ;	
				} 
				else{
					p->data = L->data ;
					p->right = L->right ;
					
				}
			}
			p = NULL;
		}
		//所找结点小于父之时，移向左孩 
		else if(data < p->data ){
			child = 0;
			parent = p;
			p = p->left ;
		}
		//所找结点大于父之时，移向右孩
		else{
			child = 1;
			parent = p;
			p = p->right ;
		}
	} 
} 
void menu(){
	Node* node = (Node*)malloc(sizeof(Node));
	int choice,select;
	do{
		system("cls");
		printf("\n-------------------------\n");
		printf("1.初始化树\n");
		printf("2.插入元素\n");
		printf("3.先序遍历\n");
		printf("4.中序遍历\n");
		printf("5.后序遍历\n");
		printf("6.层次遍历\n");
		printf("7.删除\n");
		printf("8.查找\n");
		printf("9.退出\n");
		printf("-----------------------------\n");
		printf("\n输入你操作数\n");
		scanf("%d",&choice);
		getchar();
		switch(choice){
			case 1 :
				printf("\n你选择初始\n");
				init(node);
				break;
			case 2 :
				printf("\n你选择插入\n");
				Insert(node);
				break;
			case 3 :
				printf("\n你选择先序遍历\n");
				printf("\n递归\n");
				pretraverse(node);
				printf("\n非递归\n");
				preorder(node);
				break;
			case 4 :
				printf("\n你选择中序遍历\n");
				printf("\n递归\n");
				Inortraverse(node);
				printf("\n非递归\n");
				Inororder(node);
				break;
			case 5 :
				printf("\n你选择后序遍历\n");
				printf("\n递归\n");
				Posttraverse(node);
				printf("\n非递归\n");
				Postorder(node);
				break;
			case 6 :
				printf("\n你选择层次遍历\n");
				levelorder(node); 
				break;	
			case 7 :
				printf("\n你选择删除\n");
				delet(node);
				break;
			case 8 :
				printf("\n你选择查找\n"); 
				find(node); 
				break;	
			case 9 :
				break;
		}
		system("pause");
	} while(choice != 9);
}

