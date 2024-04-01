#include<stdio.h>
void swap(int* a,int* b){
	int temp;
	temp = *a;
	*a = *b;
	*b = temp;
} 
void print(int a[] ,int n){
	int i;
	for (i=0;i<n;i++){
		printf("%5d",a[i]);
	}
} 
void colorsort(int a[],int n){
	int p0 ,i, p1 ,p2 = n -1;
	p0=p1=0;
	for(p1= 0; p1 < n; p1++){
		if(a[p1] == 2 && p1 <= p2){
			swap(&a[p2],&a[p1]);
			p2--;
		}
	}
	for(p1= 0; p1 < n; p1++){
		if (a[p1] == 0 ){
			swap(&a[p1],&a[p0]);
			p0++;
		}
	}
}
int main(){
	int a[] = {1,2,1,0,2,0,0},n = 7;
	printf("ÅÅÐòÇ°£º\n");
	print(a,n);
	printf("\n");
	colorsort(a,n);
	printf("ÅÅÐòºó£º\n");
	print(a,n);
	printf("\n"); 
	getchar();
	system("pause"); 
	return 0;
	 
}
