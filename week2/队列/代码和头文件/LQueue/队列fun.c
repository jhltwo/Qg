#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<stdbool.h>
#include<memory.h>
#include"fun.h"
//初始化列队 
LinkQueue* initQueue(int esize ){
	LinkQueue* q = (LinkQueue*)malloc(sizeof(LinkQueue));
	q->head = q->tail = NULL;
	q->esize = esize;
	return q;
}
//入队
void enQueue(LinkQueue* q, void* data){
	QNode* p = (QNode*)malloc(sizeof(QNode));
	p->data  = malloc(q->esize );
	memcpy(p->data , data, q->esize );
	p->next = NULL;
	if(q->head == NULL ){
		q->head = q->tail = p;
	}
	else{
		q->tail->next  = p;
		q->tail = p; 
	}
}
//出队
void deQueue(LinkQueue* q){
	 QNode* temp;
	 if(q->head == NULL){
	 	printf("该队列为空\n"); 
	 }
	 else{
	 	temp = q->head ;
	 	q->head = q->head->next ;
		free(temp); 
	 }
} 
//清空
void clearQueue(LinkQueue* q){
		QNode* temp;
	while(q->head != NULL){
		temp = q->head ;
		q->head = q->head->next ;
		free(temp); 
	}
	q->tail  = NULL;
} 
//查看队头
void* getheadQueue(LinkQueue* q){
	if(q->head == NULL){
		printf("该队列为空");
	}
	else{
	return q->head->data ; 
}
} 
//判空
void isemptyQueue(LinkQueue* q){
	if(q->head == NULL){
		printf("\n该队列为空\n");
	}
	else{
		printf("\n该队列不为空\n");
	}
} 
//队列长度
int lengthQueue(LinkQueue* q) {
	int count = 0 ;
	QNode* current = q->head ;
	while(current != NULL){
		count ++ ;
		current = current->next  ; 
	}
	return count;
}
//遍历队列 
void traverseQueue(LinkQueue* q,void(*printFunc)(void*)){
	QNode* current = q->head ;
	while(current != NULL){
		printFunc(current->data );
		current = current->next ;
	}
} 
//遍历整型
void printInt(void* data){
	int* intdata = (int*)data;
	printf("%d",*intdata);
} 
//遍历字符 
void printChar(void* data){
	char* chardata = (char*)data;
	printf("%c",*chardata);
} 
//遍历浮点型
void printDouble(void* data){
	double* doubledata = (double*)data;
	printf("%f",*doubledata);
} 
//销毁 
void DestoryQueue(LinkQueue* q){
	QNode* temp;
	while(q->head != NULL){
		temp = q->head ;
		q->head = q->head->next ;
		free(temp); 
	}
	q->tail  = NULL;
	free(q);
} 
//菜单 
void menu(){
	int choice, select;
	LinkQueue* q = (LinkQueue*)malloc(sizeof(LinkQueue));
	printf("\n---------------------------------------------------\n");
		printf("请选择数据类型\n");
		printf("1.整型\n");
		printf("2.字符\n");
		printf("3.浮点\n");
		scanf("%d",&select); 
		system("pause");
		system("cls");		
	do{
		printf("\n---------------------------------------------------\n");
		printf("请选择功能");
		printf("1.初始化队列\n");
		printf("2.入队\n");
		printf("3.出队\n");
		printf("4.遍历\n");
		printf("5.销毁\n");
		printf("6.列队长度\n");
		printf("7.判空\n");
		printf("8.查看队头\n");
		printf("9.清空\n");
		printf("10.退出\n");
		printf("请选择：");
		scanf("%d",&choice);
		system("pause");
		system("cls");
		switch(choice){
			case 1:
			printf("\n初始化\n");
			if (select == 1){
				q = initQueue(sizeof(int));
			}
			if (select == 2){
				q = initQueue(sizeof(char));
			}
			if (select == 3){
				q = initQueue(sizeof(double));
			}
				break;
			case 2 :
				printf("\n你选择入队\n");  
			if (select == 1){
				int* data = (int*)malloc(sizeof(int)); 
				printf("请输入要传入的整型：");
				scanf("%d",data);
				enQueue(q ,data);
			}
			if (select == 2){
				char* data = (char*)malloc(sizeof(char));
				printf("请输入要传入的字符：");
				scanf(" %c",data);
				enQueue(q ,data);
			}
			if (select == 3){
				double* data = (double*)malloc(sizeof(double)) ; 
				printf("请输入要传入的浮点数：");
				scanf("%lf",data);
				enQueue(q ,data);
			}
				break;
			case 3 :
				printf("\n出队\n");
				deQueue(q);
				break;
			case 4 :
				printf("\n你选择遍历\n"); 
			if (select == 1){
				traverseQueue(q , printInt); 
			}
			if (select == 2){
				traverseQueue(q , printChar) ;
			}
			if (select == 3){
				traverseQueue(q , printDouble) ;
			}
				break;
			case 5 :
				printf("\n销毁链表\n");
				DestoryQueue(q); 
				break;
			case 6 :
				printf("\n你选择列队长度\n");
				int count =lengthQueue( q);
				printf("该队列长度为：%d",count);
				break;
			case 7 :  
				printf("\n判空\n");
				isemptyQueue(q); 
				break;
			case 8 :
				printf("\n查看队头\n");
			if (select == 1){
				int* data = getheadQueue(q);
				printf("队头元素为：%d",*data);
			}
			if (select == 2){
				char* data = getheadQueue(q);
				printf("队头元素为：%c",*data);
			}
			if (select == 3){
				double* data = getheadQueue(q);
				printf("队头元素为：%f",*data);
			}
			break;
			case 9 :
				printf("\n判清空\n");
				clearQueue(q); 
				break;
			case 10 :
				break;			
		}
}while(choice != 10);
}

