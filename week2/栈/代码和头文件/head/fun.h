#ifndef DULINKEDLIST_H_INCLUDED
#define DULINKEDLIST_H_INCLUDED
#define OVERFLOW -1
//��ʽ�ṹ
//�ַ�ջ��� 
typedef struct StackNodestr{
	char data;
	struct StackNodestr* next;	
}StackNodestr, *LinkStackstrPtr;
//����ջ���
typedef struct StackNodenum{
	double n;
	struct StackNodenum* next;
}StackNodenum, *LinkStacknumPtr;
//����ջͷ 
typedef struct LinkStacknum
{
	LinkStacknumPtr top;	  //ջ��ָ��
	int	count;  //ջ��Ԫ�ظ���
}LinkStacknum;
//�ַ�ջͷ  
typedef struct LinkStackstr 
{
	LinkStackstrPtr top;	  //ջ��ָ��
	int	count;  //ջ��Ԫ�ظ���
}LinkStackstr;
//�ַ�ջ��ʼ�� 
LinkStackstr* initStackstr(); 
//����ջ��ʼ�� 
LinkStacknum* initStacknum();
//��ջ (�ַ�)
void pushstr(LinkStackstr* s,char data);
//��ջ (����)
void pushnum(LinkStacknum* s,double n);
//��ջ ���ַ��� 
void popstr(LinkStackstr* s);
//��ջ �����֣� 
void popnum(LinkStacknum* s);
//�Ƚ����ȼ�(ͨ������ֵ���ж�Ӧ������ 
int compare(char a, char b);
//�������� 
void four(LinkStackstr* str, LinkStacknum* num);
#endif
