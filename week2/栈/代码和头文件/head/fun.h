#ifndef DULINKEDLIST_H_INCLUDED
#define DULINKEDLIST_H_INCLUDED
#define OVERFLOW -1
//链式结构
//字符栈结点 
typedef struct StackNodestr{
	char data;
	struct StackNodestr* next;	
}StackNodestr, *LinkStackstrPtr;
//数字栈结点
typedef struct StackNodenum{
	double n;
	struct StackNodenum* next;
}StackNodenum, *LinkStacknumPtr;
//数字栈头 
typedef struct LinkStacknum
{
	LinkStacknumPtr top;	  //栈顶指针
	int	count;  //栈中元素个数
}LinkStacknum;
//字符栈头  
typedef struct LinkStackstr 
{
	LinkStackstrPtr top;	  //栈顶指针
	int	count;  //栈中元素个数
}LinkStackstr;
//字符栈初始化 
LinkStackstr* initStackstr(); 
//数字栈初始化 
LinkStacknum* initStacknum();
//进栈 (字符)
void pushstr(LinkStackstr* s,char data);
//进栈 (数字)
void pushnum(LinkStacknum* s,double n);
//出栈 （字符） 
void popstr(LinkStackstr* s);
//出栈 （数字） 
void popnum(LinkStacknum* s);
//比较优先级(通过返回值进行对应操作） 
int compare(char a, char b);
//四则运算 
void four(LinkStackstr* str, LinkStacknum* num);
#endif
