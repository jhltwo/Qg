#include<stdio.h>
#include<stdlib.h>
#include<string.h> 
#include"fun.h" 
int main(){	
	LinkStackstr* str = initStackstr(); 
	LinkStacknum* num = initStacknum();
	four(str,num);
	return 0;
}
