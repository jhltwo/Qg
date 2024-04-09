#include<stdio.h>
#include<stdlib.h>
#include"fun.h"
  
// ��ʼ������  
void initQueue(Queue *q) {  
    q->front = q->rear = NULL;  
}  
// �ж϶����Ƿ�Ϊ��  
int isQueueEmpty(Queue *q) {  
    return q->front == NULL;  
}  
// ��Ӳ���  
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
  
// ���Ӳ���  
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
//������� 
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
//ջ��ʼ�� 
LinkStack* initStack(){
	LinkStack* s = (LinkStack*)malloc(sizeof(LinkStack));
	s->count  = 0;
	s->top = NULL;
	return s;
}
//����
void init(Node* node){
	int data;
	printf("\n���������\n");
	scanf("%d",&data);
	node->data = data;
	node->left = NULL;
	node->right = NULL;
} 
//��ջ
void push(LinkStack* s,Node* newnode){
	StackNode* p = (StackNode*)malloc(sizeof(StackNode));
	p->newnode  = newnode;
	p->next = s->top ;
	s->top = p;
	s->count ++;
} 
//��ջ 
Node* pop(LinkStack* s){
	if(s->top == NULL){
		printf("��ջΪ��\n");
	}
	StackNode* p = s->top ;
	Node* newnode = p->newnode   ; 
	s->top = s->top->next ; 
	free(p);
	s->count --;
	return newnode;
}
//�ǵݹ�����
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
//�ǵݹ�����
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
//�ǵݹ�������
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
//������� 
void pretraverse(Node* node){
	if(node == NULL) return ;
	printf("%d",node->data );
	pretraverse(node->left );
	pretraverse(node->right ); 
}
//�������
void Inortraverse(Node* node){
	if(node == NULL) return ;
	Inortraverse(node->left );	
	printf("%d",node->data );
	Inortraverse(node->right );
} 
//�������
void Posttraverse(Node* node){
	if(node == NULL) return ;
	Posttraverse(node->left );
	Posttraverse(node->right );
	printf("%d",node->data );
} 
//����
void Insert(Node* node){
	int data;
	printf("\n����Ҫ���������\n");
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
			printf("������\n");
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
//����
void find(Node* node){
	int data;
	printf("\n����Ҫ���ҵ�����\n");
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
			printf("\n����\n");
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
		printf("������\n");
	}
} 
//ɾ��
void delet(Node* node){
	int data;
	printf("\n����Ҫɾ��������\n");
	scanf("%d",&data);
	Node *L,*LL;
	Node* p = node;
	Node* parent = node;
	int child = 0;
	if(node == NULL) return;
	while(p){
		//�ҵ���� 
		if(p->data == data){
			if(p->left == NULL && p->right ==NULL){
				//ֻ�и�����ʱ�� 
				if(p == node){
					free(p);
				}
				//p�������߶���û���ӽ�� 
				else if(child == 0 ){
					parent->left =NULL;
					free(p);
				}
				//p������ұ߶���û���ӽ�� 
				else{
					parent->right = NULL;
					free(p);
				}
			}
			//���ҵ��Ľ��ֻ���Һ� 
			else if(p->left == NULL){
				//�������� 
				if(child == 0){
					parent->left = p->right  ;
				}
				//������Ұ� 
				else{
					parent->right = p->right  ;
				}
				free(p);
			}
			//���ҵ����ֻ���� 
			else if(p->right == NULL){
				//����� 
				if(child == 0){
					parent->left = p->left  ;
				}
				//���Ұ� 
				else{
					parent->right = p->left  ;
				}
				free(p);
			}
			//���ҵ��Ľ�������Һ� 
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
		//���ҽ��С�ڸ�֮ʱ�������� 
		else if(data < p->data ){
			child = 0;
			parent = p;
			p = p->left ;
		}
		//���ҽ����ڸ�֮ʱ�������Һ�
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
		printf("1.��ʼ����\n");
		printf("2.����Ԫ��\n");
		printf("3.�������\n");
		printf("4.�������\n");
		printf("5.�������\n");
		printf("6.��α���\n");
		printf("7.ɾ��\n");
		printf("8.����\n");
		printf("9.�˳�\n");
		printf("-----------------------------\n");
		printf("\n�����������\n");
		scanf("%d",&choice);
		getchar();
		switch(choice){
			case 1 :
				printf("\n��ѡ���ʼ\n");
				init(node);
				break;
			case 2 :
				printf("\n��ѡ�����\n");
				Insert(node);
				break;
			case 3 :
				printf("\n��ѡ���������\n");
				printf("\n�ݹ�\n");
				pretraverse(node);
				printf("\n�ǵݹ�\n");
				preorder(node);
				break;
			case 4 :
				printf("\n��ѡ���������\n");
				printf("\n�ݹ�\n");
				Inortraverse(node);
				printf("\n�ǵݹ�\n");
				Inororder(node);
				break;
			case 5 :
				printf("\n��ѡ��������\n");
				printf("\n�ݹ�\n");
				Posttraverse(node);
				printf("\n�ǵݹ�\n");
				Postorder(node);
				break;
			case 6 :
				printf("\n��ѡ���α���\n");
				levelorder(node); 
				break;	
			case 7 :
				printf("\n��ѡ��ɾ��\n");
				delet(node);
				break;
			case 8 :
				printf("\n��ѡ�����\n"); 
				find(node); 
				break;	
			case 9 :
				break;
		}
		system("pause");
	} while(choice != 9);
}

