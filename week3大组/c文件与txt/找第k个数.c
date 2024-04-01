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
	printf("\n");
} 
int partition(int a[],int low,int high){
	int pivot = a[high];
	int i = low - 1, j;
	for(j = low; j <= high -1; j++){
		if(a[j] <= pivot){
			i++;
			swap(&a[j] ,&a[i]);
		}
	}
	//��ʱi+1�����ض�����pivot
	swap(&a[high],&a[i+1]); 
	return i+1; 
} 
int qsort(int a[],int left,int right, int k){
	int dex; 
	if( k > 0 && k <= right - left + 1){
		 dex = partition(a,left,right);
		 //printf("%d",dex);
	
	if(dex -left == k-1){
		return a[dex];
	}
	else if(dex -left> k-1){
		return qsort(a,left,dex-1,k);
	}
	else
		return qsort(a,dex+1,right,k - dex + left -1);
}
}
int main(){
	int a[7] = {5,2,8,4,3,7,6};
	int  n = 7;
	int k;
	printf("\nԭ����Ϊ��\n");
	print(a,n);
	printf("\n�����ҵ�kС����\n");
	scanf("%d",&k);
	int result = qsort(a,0,n-1,k);
	printf("����Ϊ��\n"); 
	printf("%d",result);
	getchar();
	getchar(); 
}
