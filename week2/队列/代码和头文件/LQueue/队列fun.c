#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<stdbool.h>
#include<memory.h>
#include"fun.h"
//��ʼ���ж� 
LinkQueue* initQueue(int esize ){
	LinkQueue* q = (LinkQueue*)malloc(sizeof(LinkQueue));
	q->head = q->tail = NULL;
	q->esize = esize;
	return q;
}
//���
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
//����
void deQueue(LinkQueue* q){
	 QNode* temp;
	 if(q->head == NULL){
	 	printf("�ö���Ϊ��\n"); 
	 }
	 else{
	 	temp = q->head ;
	 	q->head = q->head->next ;
		free(temp); 
	 }
} 
//���
void clearQueue(LinkQueue* q){
		QNode* temp;
	while(q->head != NULL){
		temp = q->head ;
		q->head = q->head->next ;
		free(temp); 
	}
	q->tail  = NULL;
} 
//�鿴��ͷ
void* getheadQueue(LinkQueue* q){
	if(q->head == NULL){
		printf("�ö���Ϊ��");
	}
	else{
	return q->head->data ; 
}
} 
//�п�
void isemptyQueue(LinkQueue* q){
	if(q->head == NULL){
		printf("\n�ö���Ϊ��\n");
	}
	else{
		printf("\n�ö��в�Ϊ��\n");
	}
} 
//���г���
int lengthQueue(LinkQueue* q) {
	int count = 0 ;
	QNode* current = q->head ;
	while(current != NULL){
		count ++ ;
		current = current->next  ; 
	}
	return count;
}
//�������� 
void traverseQueue(LinkQueue* q,void(*printFunc)(void*)){
	QNode* current = q->head ;
	while(current != NULL){
		printFunc(current->data );
		current = current->next ;
	}
} 
//��������
void printInt(void* data){
	int* intdata = (int*)data;
	printf("%d",*intdata);
} 
//�����ַ� 
void printChar(void* data){
	char* chardata = (char*)data;
	printf("%c",*chardata);
} 
//����������
void printDouble(void* data){
	double* doubledata = (double*)data;
	printf("%f",*doubledata);
} 
//���� 
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
//�˵� 
void menu(){
	int choice, select;
	LinkQueue* q = (LinkQueue*)malloc(sizeof(LinkQueue));
	printf("\n---------------------------------------------------\n");
		printf("��ѡ����������\n");
		printf("1.����\n");
		printf("2.�ַ�\n");
		printf("3.����\n");
		scanf("%d",&select); 
		system("pause");
		system("cls");		
	do{
		printf("\n---------------------------------------------------\n");
		printf("��ѡ����");
		printf("1.��ʼ������\n");
		printf("2.���\n");
		printf("3.����\n");
		printf("4.����\n");
		printf("5.����\n");
		printf("6.�жӳ���\n");
		printf("7.�п�\n");
		printf("8.�鿴��ͷ\n");
		printf("9.���\n");
		printf("10.�˳�\n");
		printf("��ѡ��");
		scanf("%d",&choice);
		system("pause");
		system("cls");
		switch(choice){
			case 1:
			printf("\n��ʼ��\n");
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
				printf("\n��ѡ�����\n");  
			if (select == 1){
				int* data = (int*)malloc(sizeof(int)); 
				printf("������Ҫ��������ͣ�");
				scanf("%d",data);
				enQueue(q ,data);
			}
			if (select == 2){
				char* data = (char*)malloc(sizeof(char));
				printf("������Ҫ������ַ���");
				scanf(" %c",data);
				enQueue(q ,data);
			}
			if (select == 3){
				double* data = (double*)malloc(sizeof(double)) ; 
				printf("������Ҫ����ĸ�������");
				scanf("%lf",data);
				enQueue(q ,data);
			}
				break;
			case 3 :
				printf("\n����\n");
				deQueue(q);
				break;
			case 4 :
				printf("\n��ѡ�����\n"); 
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
				printf("\n��������\n");
				DestoryQueue(q); 
				break;
			case 6 :
				printf("\n��ѡ���жӳ���\n");
				int count =lengthQueue( q);
				printf("�ö��г���Ϊ��%d",count);
				break;
			case 7 :  
				printf("\n�п�\n");
				isemptyQueue(q); 
				break;
			case 8 :
				printf("\n�鿴��ͷ\n");
			if (select == 1){
				int* data = getheadQueue(q);
				printf("��ͷԪ��Ϊ��%d",*data);
			}
			if (select == 2){
				char* data = getheadQueue(q);
				printf("��ͷԪ��Ϊ��%c",*data);
			}
			if (select == 3){
				double* data = getheadQueue(q);
				printf("��ͷԪ��Ϊ��%f",*data);
			}
			break;
			case 9 :
				printf("\n�����\n");
				clearQueue(q); 
				break;
			case 10 :
				break;			
		}
}while(choice != 10);
}

