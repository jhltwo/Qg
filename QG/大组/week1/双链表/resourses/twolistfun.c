#include<stdio.h>
#include<stdlib.h>
#include"fun.h"
//初始化双链表
Node* initList(){
	Node* list = (Node*)malloc(sizeof(Node));
	list->date = 0;
	list->next = NULL;
	list->pre = NULL;
	return list;
} 
//寻找数据多对应结点
Node* find(Node* list){
	int date;
	printf("输入要找位置的数据:\n");
	scanf("%d",&date);
	Node* p = list;
	while(p->date != date && p){
		p = p->next ;
	}if(p == NULL)
	{
		printf("没找到\n");
		return NULL;
	}
	else{
	return p;
}
} 
//头插法
void headinsert(Node* list){
	int date;
	printf("\n输入要插入的数据\n");
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
//尾插
void tailinsert(Node* L){
	int date;
	printf("\n输入要插入的数据\n");
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
//插入
void insert(Node* list,Node* p){
	int date;
	printf("\n输入要插入的数据\n");
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
//删除
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
//遍历及销毁
void koprintlist(Node* list){
	Node* node = list->next;
	while(node){
		printf("%d",node->date );
		free(list);
		list = node;
		node = node->next ;
	}
} 
//遍历
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
		printf("请选择功能");
		printf("1.初始化链表\n");
		printf("2.插入数据\n");
		printf("3.删除数据\n");
		printf("4.遍历\n");
		printf("5.遍历并销毁链表\n");
		printf("6.退出\n");
		printf("请选择：");
		scanf("%d",&choice);
		system("cls");
		switch(choice){
			case 1:
				printf("\n你选择初始化链表\n");
				Node* list = initList();
				break;
			case 2 :
				printf("\n你选择插入数据\n");
				int choice2;
				printf("1.头插，2.尾插 3.中间插入（将新的数据插到指定数据之后）") ;
				printf("\n输入方法所代表的序号：\n");
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
				printf("\n你选择删除数据\n");
				delet(list,find(list));
				break;
			case 4 :
				printf("\n你选择遍历链表\n");
				printlist(list);
				break;
			case 5 :
				printf("\n遍历并销毁链表\n");
				koprintlist(list);
				break;
			case 6 :
				break;		
		}
}while(choice != 6);
}

