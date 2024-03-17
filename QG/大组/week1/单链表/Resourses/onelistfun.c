#include<stdio.h>
#include<stdlib.h>
#include"fun.h"
//初始化链表
Node* initList(){
	Node* list = (Node*)malloc(sizeof(Node));
	list->date = 0;
	list->next = NULL;
	return list;
} 
//头插法
void headInsert(Node* list){
	int date;
	printf("\n输入要插入的数据\n");
	scanf("%d",&date);
	Node* node = (Node*)malloc(sizeof(Node));
	node->date = date;
	node->next = list->next ;
	list->next = node;
} 
//尾插法
void tailInsert(Node* list){
	int date;
	printf("\n输入要插入的数据\n");
	scanf("%d",&date);
	Node* n = (Node*)malloc(sizeof(Node));
	n->date = date;
	Node* node = list;
	while(node->next ){
		node = node->next ;
	}
	n->next = node->next ;
	node->next = n;
} 
//找出中间结点
void findmiddle(Node* list){
	Node* end = list;
	Node* mid = list;
	while(end){
		end = end->next->next;
		mid = mid->next ;  
	}
	printf("\n中间结点所对应的值：%d\n",mid->date );
} 
//非递归反转
void reverse(Node* list){
	Node* beg = list->next ;
	Node* end = list->next->next ;
	while(end){
		beg->next = end->next ;
		end->next = list->next ;
		list->next = end;
		end = beg->next ; 
	} 
} 
//递归反转  (这个有问题，还找不出来)
Node* rereverse(Node* list){
	if(list == NULL || list->next == NULL){
		return list;
	}
	Node* p = rereverse(list->next );
	list->next->next = list;
	list->next = NULL;
	return p ;
} 
//寻找数据所对应的结点，以便于插入和删除 
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
//判断链表是否成环
int circle(Node* list){
	Node* fast = list;   //快慢指针判断是否成环 
	Node* slow = list;
	while(fast->next != NULL){
		slow = slow->next ;
		fast = fast->next ;
		if(fast->next != NULL){
			fast = fast->next ;
		}
		if(fast == slow){
			return 1;
			break;
		}
	}
	return 0;
} 
//奇偶调换 (有问题，还没找出来)
void change(Node* list){
	  if (list == NULL || list->next == NULL){
	  	return ; 
	  }
	  Node* odd = list->next ;
	  Node* even = list->next->next  ;
	  Node* head = list;
	  while(even != NULL && even->next != NULL){
	  	//移动指针
		  odd->next  = even->next ;
		  even->next = odd;
		  head->next = even;
		  if(odd->next != NULL && odd->next->next !=NULL ){
		  	even = odd->next->next ;
		  	head = odd;
		  	odd = odd->next ;  
		  }
	  }
} 
//插入 
void  insert(Node* list,Node* p){
	int date;
	printf("\n输入要插入的数据\n");
	scanf("%d",&date);
	Node* node = (Node*)malloc(sizeof(Node));
	node->date = date;
	node->next = p->next ;
	p->next = node;
}
//删除链表
void delet(Node* list,Node* p){
	Node* node = list;
	while(node->next != p && node != NULL){
		node = node->next ;
	}
	node->next = p->next ;
	free(p);
} 
//销毁链表 
//遍历链表
void koprintList(Node* list){
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
		printf("6.非递归反转\n");
		printf("7.递归反转\n");
		printf("8.中间结点\n");
		printf("9.判断链表是否成环\n");
		printf("10.奇偶换\n");
		printf("11...退出\n");
		printf("请选择：");
		scanf("%d",&choice);
		system("cls");
		switch(choice){
			case 1:
				printf("\n你选择初始化链表\n");
				Node* list = initList();
				break;
			case 2 :
				printf("\n你选择插入数据\n");  //分3种插入 
				int choice2;
				printf("1.头插，2.尾插 3.中间插入（将新的数据插到指定数据之后）") ;
				printf("\n输入方法所代表的序号：\n");
				scanf("%d",&choice2); 
				switch(choice2){
					case 1 :
						headInsert(list);
						break;
					case 2 :
						tailInsert(list);
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
				koprintList(list);
				break;
			case 6 :
				printf("\n你选择非递归反转\n");
				reverse(list);
				break;
			case 7 :   //这个有问题，一时之间找不到问题所在 
				printf("\n你选择递归反转\n");
				list = rereverse(list);
				break;
			case 8 :
				printf("\n数据要为奇数个\n");
				printf("\n找出中间结点对应的数据\n");
				findmiddle(list);
				break;
			case 9 :
				printf("\n判断是否成环\n");
				if (circle(list)){
					printf("成环");
				}
				else{
					printf("不成环");
				}
				break;
			case 10 :
				printf("\n链表奇偶互换\n");
				change(list);
				break;
			case 11 :
				break;			
		}
}while(choice != 11);
}


