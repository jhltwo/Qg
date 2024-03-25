#include<stdio.h>
#include<stdlib.h>
#include<string.h> 
#include"fun.h" 
//字符栈初始化 
LinkStackstr* initStackstr(){
	LinkStackstr* s = (LinkStackstr*)malloc(sizeof(LinkStackstr));
	s->count  = 0;
	s->top = NULL;
	return s;
}
//数字栈初始化 
LinkStacknum* initStacknum(){
	LinkStacknum* s = (LinkStacknum*)malloc(sizeof(LinkStacknum));
	s->count  = 0;
	s->top = NULL;
	return s;
}
//进栈 (字符)
void pushstr(LinkStackstr* s,char data){
	StackNodestr* p = (StackNodestr*)malloc(sizeof(StackNodestr));
	p->data = data;
	p->next = s->top ;
	s->top = p;
	s->count ++;
}
//进栈 (数字)
void pushnum(LinkStacknum* s,double n){
	StackNodenum* p = (StackNodenum*)malloc(sizeof(StackNodenum));
	p->n = n;
	p->next = s->top ;
	s->top = p;
	s->count ++;
}
//出栈 （字符） 
void popstr(LinkStackstr* s){
	if(s->top == NULL){
		printf("该栈为空\n");
	}
	else{
		StackNodestr* p = s->top ;
		s->top = s->top->next ; 
		free(p);
	}
	s->count --;
}
//出栈 （数字） 
void popnum(LinkStacknum* s){
	if(s->top == NULL){
		printf("该栈为空\n");
	}
	else{
		StackNodenum* p = s->top ;
		s->top = s->top->next ; 
		free(p);
	}
	s->count --;
}
//比较优先级(通过返回值进行对应操作） 
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
//四则运算
void four(LinkStackstr* str, LinkStacknum* num){
	printf("\n请输入表达式\n"); 
	char e[50]; 
	gets(e);
	int i;
	double result,n1,n2;   //一条式子的三个数 
	//一个个遍历输入的式子 
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
		else if(e[i] == '('){             //左括号直接进栈 
			pushstr(str,e[i]);
		}
		else if(e[i] == '+' || e[i] == '-' || e[i] == '*' || e[i] == '/' ){    //加减乘除要判断 
			if(str->top == NULL){
				pushstr(str,e[i]);
			}
			else{
				int flag = compare(str->top->data ,e[i] );             //比较优先级 
				if(flag == 1){ 
					pushstr(str,e[i]);
				}
				else{
					while(flag != 1){                       //往前遍历符号进行判断再操作 
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
						printf("输入有误\n");
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
		else if(e[i] == ')'){                          //右括号就往前执行 
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
		else printf("输入格式出错\n");
	}
//最后剩下的数字以及运算符的执行	
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
	printf("结果是：%f\n",result);
	getchar(); 
	getchar();
} 
