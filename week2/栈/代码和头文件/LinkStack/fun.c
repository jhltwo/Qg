#include<stdio.h>
#include<stdlib.h>
#include<string.h> 
#include"fun.h" 
//�ַ�ջ��ʼ�� 
LinkStackstr* initStackstr(){
	LinkStackstr* s = (LinkStackstr*)malloc(sizeof(LinkStackstr));
	s->count  = 0;
	s->top = NULL;
	return s;
}
//����ջ��ʼ�� 
LinkStacknum* initStacknum(){
	LinkStacknum* s = (LinkStacknum*)malloc(sizeof(LinkStacknum));
	s->count  = 0;
	s->top = NULL;
	return s;
}
//��ջ (�ַ�)
void pushstr(LinkStackstr* s,char data){
	StackNodestr* p = (StackNodestr*)malloc(sizeof(StackNodestr));
	p->data = data;
	p->next = s->top ;
	s->top = p;
	s->count ++;
}
//��ջ (����)
void pushnum(LinkStacknum* s,double n){
	StackNodenum* p = (StackNodenum*)malloc(sizeof(StackNodenum));
	p->n = n;
	p->next = s->top ;
	s->top = p;
	s->count ++;
}
//��ջ ���ַ��� 
void popstr(LinkStackstr* s){
	if(s->top == NULL){
		printf("��ջΪ��\n");
	}
	else{
		StackNodestr* p = s->top ;
		s->top = s->top->next ; 
		free(p);
	}
	s->count --;
}
//��ջ �����֣� 
void popnum(LinkStacknum* s){
	if(s->top == NULL){
		printf("��ջΪ��\n");
	}
	else{
		StackNodenum* p = s->top ;
		s->top = s->top->next ; 
		free(p);
	}
	s->count --;
}
//�Ƚ����ȼ�(ͨ������ֵ���ж�Ӧ������ 
int compare(char a, char b){
	if (a == '('){
		return 1;
	} 
	if((a == '+' || a == '-') && (b == '*' || b == '/' )){
		return 1;
	}
	if ((a != '(') && (b == '+' || b == '-')){
		return 0;
	}
	if ((a == '/' || a == '*') && (b == '*' || b == '/' )){
		return 0;
	}
} 
//��������
void four(LinkStackstr* str, LinkStacknum* num){
	printf("\n��������ʽ\n"); 
	char e[50]; 
	gets(e);
	int i;
	double result,n1,n2;   //һ��ʽ�ӵ������� 
	//һ�������������ʽ�� 
	for( i=0; e[i] != '\0'; i++){ 
		if(e[i] >= '0' && e[i] <= '9'){
			double number = 0,new  ;
			for(i;e[i] >= '0' && e[i] <= '9';i++ )
			{
				new = (double) (e[i] - '0');
				number = number*10 + new;
			}
			i--;
			pushnum(num,number);
		}
		else if(e[i] == '('){             //������ֱ�ӽ�ջ 
			pushstr(str,e[i]);
		}
		else if(e[i] == '+' || e[i] == '-' || e[i] == '*' || e[i] == '/' ){    //�Ӽ��˳�Ҫ�ж� 
			if(str->top == NULL){
				pushstr(str,e[i]);
			}
			else{
				int flag = compare(str->top->data ,e[i] );             //�Ƚ����ȼ� 
				if(flag == 1){ 
					pushstr(str,e[i]);
				}
				else{
					while(flag != 1){                       //��ǰ�������Ž����ж��ٲ��� 
					n2 = num->top->n ;
					popnum(num);
					n1 = num->top->n ;
					popnum(num);    
					if(str->top->data == '+'){
						result = n1 + n2;
					}
					else if(str->top->data == '-'){
						result = n1 - n2;
					}
					else if(str->top->data == '*'){
						result = n1 * n2;
					}
					else if(str->top->data == '/'){
						result = n1 / n2;
					}
					else{
						printf("��������\n");
					}
					pushnum(num,result);
					popstr(str);
					if(str->top != NULL){
						flag = compare(str->top->data ,e[i] );
						if (flag == 1){
							pushstr(str,e[i]);
						}
				}
				    else {
					pushstr(str,e[i]);
					flag = 1;
				}   
				}
			}
			}
		}
		else if(e[i] == ')'){                          //�����ž���ǰִ�� 
			while(str->top->data != '(' ){
					n2 = num->top->n ;
					popnum(num);
					n1 = num->top->n;
					popnum(num);  
					if(str->top->data == '+'){
						result = n1 + n2;
					}
					else if(str->top->data == '-'){
						result = n1 - n2;
					}
					else if(str->top->data == '*'){
						result = n1 * n2;
					}
					else if(str->top->data == '/'){
						result = n1 / n2;
					}
					pushnum(num,result);
					popstr(str);
			}
			popstr(str);
		}
		else printf("�����ʽ����\n");
	}
//���ʣ�µ������Լ��������ִ��	
	while(str->top  != NULL){           
	n2 = num->top->n ;
	popnum(num);
	n1 = num->top->n ;
	popnum(num);  
	if(str->top->data == '+'){
		result = n1 + n2;
	}
	else if(str->top->data == '-'){
		result = n1 - n2;
	}
	else if(str->top->data == '*'){
		result = n1 * n2;
	}
	else if(str->top->data == '/'){
		result = n1 / n2;
	}
	pushnum(num,result);
	popstr(str);
}
	printf("����ǣ�%f\n",result);
	getchar(); 
	getchar();
} 
