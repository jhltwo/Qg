#include<stdio.h>
#include<stdlib.h>
#include"fun.h"
//��ʼ��˫����
Node* initList(){
	Node* list = (Node*)malloc(sizeof(Node));
	list->date = 0;
	list->next = NULL;
	list->pre = NULL;
	return list;
} 
//Ѱ�����ݶ��Ӧ���
Node* find(Node* list){
	int date;
	printf("����Ҫ��λ�õ�����:\n");
	scanf("%d",&date);
	Node* p = list;
	while(p->date != date && p){
		p = p->next ;
	}if(p == NULL)
	{
		printf("û�ҵ�\n");
		return NULL;
	}
	else{
	return p;
}
} 
//ͷ�巨
void headinsert(Node* list){
	int date;
	printf("\n����Ҫ���������\n");
	scanf("%d",&date);
	Node* node = (Node*)malloc(sizeof(Node));
	node->date = date;
	if(list->date == 0 ){
		node->next = list->next ;
		list->next = node;
		node->pre = list;
	}
	else{
		node->next = list->next ;
		list->next->pre = node;
		list->next = node;
		node->pre = list;
	}
	list->date ++;
} 
//β��
void tailinsert(Node* L){
	int date;
	printf("\n����Ҫ���������\n");
	scanf("%d",&date);
	Node* node = (Node*)malloc(sizeof(Node));
	node->date = date;
	Node* n = L;
	while(n->next ){
		n = n->next ;
	}
	node->next = n->next ;
	n->next = node;
	node->pre = L;
	L->date ++;
}  
//����
void insert(Node* list,Node* p){
	int date;
	printf("\n����Ҫ���������\n");
	scanf("%d",&date);
	Node* node = (Node*)malloc(sizeof(Node));
	node->date = date;
	if (p->next == NULL){
		node->next = p->next ;
		p->next = node;
		node->pre = p;
	}
	else{
	node->next = p->next ;
	p->next->pre = node; 
	node->pre = p;
	p->next = node;
}
	list->date ++;
} 
//ɾ��
void delet(Node* list,Node* p){
	if(p->next == NULL){
		p->pre->next = p->next ; 
		free(p);
	}
	else{
	p->pre->next = p->next ;
	p->next->pre = p->pre ;
	free(p);
}
	list->date --;
} 
//����������
void koprintlist(Node* list){
	Node* node = list->next;
	while(node){
		printf("%d",node->date );
		free(list);
		list = node;
		node = node->next ;
	}
} 
//����
void printlist(Node* L){
	Node* node = L->next ;
	while(node){
		printf("%d->",node->date );
		node = node->next ;
	}
	printf("NULL\n");
} 
void menu(){
	int choice;
	do{
		printf("\n---------------------------------------------------\n");
		printf("��ѡ����");
		printf("1.��ʼ������\n");
		printf("2.��������\n");
		printf("3.ɾ������\n");
		printf("4.����\n");
		printf("5.��������������\n");
		printf("6.�˳�\n");
		printf("��ѡ��");
		scanf("%d",&choice);
		system("cls");
		switch(choice){
			case 1:
				printf("\n��ѡ���ʼ������\n");
				Node* list = initList();
				break;
			case 2 :
				printf("\n��ѡ���������\n");
				int choice2;
				printf("1.ͷ�壬2.β�� 3.�м���루���µ����ݲ嵽ָ������֮��") ;
				printf("\n���뷽�����������ţ�\n");
				scanf("%d",&choice2); 
				switch(choice2){
					case 1 :
						headinsert(list);
						break;
					case 2 :
						tailinsert(list);
						break;
					case 3 :
						insert(list,find(list));
						break;		
				}
				break;
			case 3 :
				printf("\n��ѡ��ɾ������\n");
				delet(list,find(list));
				break;
			case 4 :
				printf("\n��ѡ���������\n");
				printlist(list);
				break;
			case 5 :
				printf("\n��������������\n");
				koprintlist(list);
				break;
			case 6 :
				break;		
		}
}while(choice != 6);
}

