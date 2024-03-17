#include<stdio.h>
#include<stdlib.h>
#include"fun.h"
//��ʼ������
Node* initList(){
	Node* list = (Node*)malloc(sizeof(Node));
	list->date = 0;
	list->next = NULL;
	return list;
} 
//ͷ�巨
void headInsert(Node* list){
	int date;
	printf("\n����Ҫ���������\n");
	scanf("%d",&date);
	Node* node = (Node*)malloc(sizeof(Node));
	node->date = date;
	node->next = list->next ;
	list->next = node;
} 
//β�巨
void tailInsert(Node* list){
	int date;
	printf("\n����Ҫ���������\n");
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
//�ҳ��м���
void findmiddle(Node* list){
	Node* end = list;
	Node* mid = list;
	while(end){
		end = end->next->next;
		mid = mid->next ;  
	}
	printf("\n�м�������Ӧ��ֵ��%d\n",mid->date );
} 
//�ǵݹ鷴ת
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
//�ݹ鷴ת  (��������⣬���Ҳ�����)
Node* rereverse(Node* list){
	if(list == NULL || list->next == NULL){
		return list;
	}
	Node* p = rereverse(list->next );
	list->next->next = list;
	list->next = NULL;
	return p ;
} 
//Ѱ����������Ӧ�Ľ�㣬�Ա��ڲ����ɾ�� 
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
//�ж������Ƿ�ɻ�
int circle(Node* list){
	Node* fast = list;   //����ָ���ж��Ƿ�ɻ� 
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
//��ż���� (�����⣬��û�ҳ���)
void change(Node* list){
	  if (list == NULL || list->next == NULL){
	  	return ; 
	  }
	  Node* odd = list->next ;
	  Node* even = list->next->next  ;
	  Node* head = list;
	  while(even != NULL && even->next != NULL){
	  	//�ƶ�ָ��
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
//���� 
void  insert(Node* list,Node* p){
	int date;
	printf("\n����Ҫ���������\n");
	scanf("%d",&date);
	Node* node = (Node*)malloc(sizeof(Node));
	node->date = date;
	node->next = p->next ;
	p->next = node;
}
//ɾ������
void delet(Node* list,Node* p){
	Node* node = list;
	while(node->next != p && node != NULL){
		node = node->next ;
	}
	node->next = p->next ;
	free(p);
} 
//�������� 
//��������
void koprintList(Node* list){
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
		printf("6.�ǵݹ鷴ת\n");
		printf("7.�ݹ鷴ת\n");
		printf("8.�м���\n");
		printf("9.�ж������Ƿ�ɻ�\n");
		printf("10.��ż��\n");
		printf("11...�˳�\n");
		printf("��ѡ��");
		scanf("%d",&choice);
		system("cls");
		switch(choice){
			case 1:
				printf("\n��ѡ���ʼ������\n");
				Node* list = initList();
				break;
			case 2 :
				printf("\n��ѡ���������\n");  //��3�ֲ��� 
				int choice2;
				printf("1.ͷ�壬2.β�� 3.�м���루���µ����ݲ嵽ָ������֮��") ;
				printf("\n���뷽�����������ţ�\n");
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
				printf("\n��ѡ��ɾ������\n");
				delet(list,find(list));
				break;
			case 4 :
				printf("\n��ѡ���������\n");
				printlist(list);
				break;
			case 5 :
				printf("\n��������������\n");
				koprintList(list);
				break;
			case 6 :
				printf("\n��ѡ��ǵݹ鷴ת\n");
				reverse(list);
				break;
			case 7 :   //��������⣬һʱ֮���Ҳ����������� 
				printf("\n��ѡ��ݹ鷴ת\n");
				list = rereverse(list);
				break;
			case 8 :
				printf("\n����ҪΪ������\n");
				printf("\n�ҳ��м����Ӧ������\n");
				findmiddle(list);
				break;
			case 9 :
				printf("\n�ж��Ƿ�ɻ�\n");
				if (circle(list)){
					printf("�ɻ�");
				}
				else{
					printf("���ɻ�");
				}
				break;
			case 10 :
				printf("\n������ż����\n");
				change(list);
				break;
			case 11 :
				break;			
		}
}while(choice != 11);
}


