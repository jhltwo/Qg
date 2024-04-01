#include<stdio.h>
#include<stdlib.h>
#include<time.h> 
//遍历数组
void print(int a[] ,int n){
	int i;
	for (i=0;i<n;i++){
		printf("%5d",a[i]);
	}
	printf("\n");
} 
//找出数组中的最大值
int  max(int a[],int n){
	int i,temp,max;
	max = a[0];
	for(i=0;i<n;i++){
		if(max < a[i]){
			max = a[i];
		}
	}
	return max;
} 
void radixsort(int a[],int n,int exp){
	int i,result[n],bucket[10]  ={0};
	for(i=0;i<n;i++){
		bucket[(a[i]/exp)%10]++; 
	}
		for(i=1;i<10;i++){
		bucket[i] = bucket[i] + bucket[i-1];
	}
	for(i=n-1;i>=0;i--){
		int iexp = (a[i]/exp)%10;
		result[bucket[iexp]-1] = a[i];
		bucket[iexp]--; 
	}
		//弄回原数组 
	for(i=0;i<n;i++){
		a[i] = result[i];
	}
}
//基数计数排序
void Radixcountsort(int a[],int n){
	int imax = max(a,n);
	int iexp;  //位数
	for(iexp=1;imax/iexp>0;iexp*=10){
		radixsort(a,n,iexp);
	} 
} 
//插入排序
Insertsort(int a[], int n){
	int i,j;
	for (i=1;i<n;i++){
		int  key = a[i];
		j = i-1;
		while(j >= 0 && a[j] > key){
			a[j+1] = a[j];
			j--;
		}
		a[j+1] = key;
	}
} 
//计数排序 
void countsort(int a[],int n) {
	if(n < 2){
		return;
	}
	int imax = max(a,n);
	int count[imax+1];
	int i,output[n];
	for(i=0;i<imax+1;i++){
		count[i] = 0;
	}
	//计算每个元素出现的次数 
	for(i=0;i<n;i++){
		count[a[i]]++;
	}
	//修改count，确定元素出现的位置
	for(i=1;i<imax+1;i++){
		count[i] += count[i-1];
	} 
	for(i=n-1;i>=0;i--){
		output[count[a[i]]-1] = a[i];
		count[a[i]]--;
	}
	//弄回原数组 
	for(i=0;i<n;i++){
		a[i] = output[i];
	}
	
}
//合并部分 
void merge(int a[],int tempA[],int left,int mid,int right){
	 //左半第一个
	 int l_sign = left;
	 //右半第一个
	 int r_sign = mid+1;
	 //临时数组的第一个
	 int sign = left;
	 //合并
	 while(l_sign <= mid && r_sign <= right){
	 	if(a[l_sign] < a[r_sign]){
	 		tempA[sign++] = a[l_sign++];
		 }
		 else{
		 	tempA[sign++] = a[r_sign++];
		 }
	 } 
	 //合并剩余的 
	 while(l_sign <= mid)  {
	 	tempA[sign++] = a[l_sign++];
	 }
	 while(r_sign <= right){
	 	tempA[sign++] = a[r_sign++];
	 }
	 while(left <= right){
	 	a[left] = tempA[left];
	 	left++;
	 } 
	  
}
//归并排序
void msort(int a[],int tempA[],int left,int right){
	if (left < right){
		int mid = (left + right)/2;
		//将左边的继续分 
		msort(a,tempA,left,mid);
		//将右边的继续分
		msort(a,tempA,mid+1,right);
		//合并
		merge(a,tempA,left,mid,right); 
}
} 

//归并函数的入口 
void Mergesort(int a[],int n){
	int tempA[n];
	msort(a ,tempA , 0, n-1);
}
//交换两数
void swap(int* a,int* b){
	int temp;
	temp = *a;
	*a = *b;
	*b = temp;
} 
//快速排序
int partition(int a[],int low,int high){
	int pivot = a[high];
	int i = low - 1, j;
	for(j = low; j < high; j++){
		if(a[j] <= pivot){
			swap(&a[j] ,&a[++i]);
		}
	}
	//此时i+1的数必定大于pivot
	swap(&a[high],&a[i+1]); 
	return i+1; 
} 
//快速排序
void Quicksort(int a[], int low,int high){
	if(low < high){
		int mid = partition(a, low, high);
		Quicksort(a,low,mid-1);
		Quicksort(a,mid+1,high);
	}
}
/* 
void menu(){
	int  choice,num,i,size;
	clock_t start,end;
	double usetime;
	printf("\n请输入数据个数\n");
	scanf("%d",&num);
	printf("\n输入数据最大值\n");
	scanf("%d",&size);
	int a[num];
	srand(time(NULL));
	int data = rand() %size;
	for(i=0;i<num;i++){
		a[i] = rand() % size+1;
	}
	do{
		printf("\n-------------------------\n");
		printf("0.退出\n");
		printf("1.插入排序\n");
		printf("2.归并排序\n");
		printf("3.快速排序\n");
		printf("4.计数排序\n");
		printf("5.基数计数排序\n");
		printf("6.遍历\n");
		scanf("%d",&choice);
		switch(choice){
			case 0:
				break;
			case 1:
				printf("\n选择插入排序\n");
				start = clock();
				Insertsort(a,num);
				end = clock();
				usetime = ((double)(end-start))/CLOCKS_PER_SEC;
				printf("\n所用时间为：%.6lf s\n",usetime);
				break;
			case 2:
				printf("\n选择归并排序\n");
				start = clock();
				Mergesort(a,num);
				end = clock();
				usetime = ((double)(end-start))/CLOCKS_PER_SEC;
				printf("\n所用时间为：%.6lf s\n",usetime);
				break;
			case 3:
				printf("\n选择快速排序\n");
				start = clock();
				Quicksort(a,0,num-1);
				end = clock();
				usetime = ((double)(end-start))/CLOCKS_PER_SEC;
				printf("\n所用时间为：%.6lf s\n",usetime);
				break;
			case 4:
				printf("\n选择计数排序\n");
				start = clock();
				countsort(a, num);
				end = clock();
				usetime = ((double)(end-start))/CLOCKS_PER_SEC;
				printf("\n所用时间为：%.6lf s\n",usetime);
				break;
			case 5:
				printf("\n选择基数计数排序\n");
				start = clock();
				Radixcountsort(a,num);
				end = clock();
				usetime = ((double)(end-start))/CLOCKS_PER_SEC;
				printf("\n所用时间为：%.6lf s\n",usetime);
				break;
			case 6:
				printf("\n遍历\n");
				print(a,num);
		}
	}while(choice);
}*/
void perfer(){
	int num,i,size;
	FILE* fp,*f;
	f=fopen("startdata.txt","w"); 
	clock_t start,end;
	double usetime;
	printf("\n请输入数据个数\n");
	scanf("%d",&num);
	printf("\n输入数据最大值\n");
	scanf("%d",&size);
	int a[num];
	srand(time(NULL));
	int data = rand() %size;
	for(i=0;i<num;i++){
		a[i] = rand() % size+1;
		fprintf(f,"%d  ",a[i]);
	}                                   //备份文件 
	fclose(f);
	f=fopen("startdata.txt","r"); 
	if(f==NULL)
	{
		printf("未成功打开文件\n"); 
		exit(0);
	 } 
	 i = 0;
	while(!feof(f))
 	{
 		fscanf(f,"%d ",&a[i]);
 		i++;
 	}
 	fclose(f);
 	fp=fopen("enddata.txt","w"); 
	printf("\n选择快速排序\n");
	start = clock();
	Quicksort(a,0,num-1);
	end = clock();
	usetime = ((double)(end-start))/CLOCKS_PER_SEC;
	printf("\n所用时间为：%.6lf s\n",usetime);
	for(i=0;i<num;i++){
		fprintf(fp,"%d  ",a[i]);
	} 
	fclose(f);
	
	f=fopen("startdata.txt","r");
	i = 0;
	while(!feof(f))
 	{
 		fscanf(f,"%d ",&a[i]);
 		i++;
 	}
	printf("\n选择计数排序\n");
	start = clock();
	countsort(a, num);
	end = clock();
	usetime = ((double)(end-start))/CLOCKS_PER_SEC;
	printf("\n所用时间为：%.6lf s\n",usetime);
	for(i=0;i<num;i++){
		fprintf(fp,"%d  ",a[i]);
	} 
	fclose(f);
	
	f=fopen("startdata.txt","r");
	i = 0;
	while(!feof(f))
 	{
 		fscanf(f,"%d ",&a[i]);
 		i++;
 	}
	printf("\n选择插入排序\n");
	start = clock();
	Insertsort(a,num);
	end = clock();
	usetime = ((double)(end-start))/CLOCKS_PER_SEC;
	printf("\n所用时间为：%.6lf s\n",usetime);
	for(i=0;i<num;i++){
		fprintf(fp,"%d  ",a[i]);
	} 
	fclose(f);
	
	f=fopen("startdata.txt","r"); 
	i = 0; 
	while(!feof(f))
 	{
 		fscanf(f,"%d ",&a[i]);
 		i++;
 	}
	printf("\n选择归并排序\n");
	start = clock();
	Mergesort(a,num);
	end = clock();
	usetime = ((double)(end-start))/CLOCKS_PER_SEC;
	printf("\n所用时间为：%.6lf s\n",usetime);
	for(i=0;i<num;i++){
		fprintf(fp,"%d  ",a[i]);
	} 
	fclose(f);
	
	f=fopen("startdata.txt","r");
	i = 0;
	while(!feof(f))
 	{
 		fscanf(f,"%d ",&a[i]);
 		i++;
 	}
	printf("\n选择基数计数排序\n");
	start = clock();
	Radixcountsort(a,num);
	end = clock();
	usetime = ((double)(end-start))/CLOCKS_PER_SEC;
	printf("\n所用时间为：%.6lf s\n",usetime);
	fclose(f);
 	fclose(fp);
}
int main(){
	//menu();
	perfer();
	system("pause"); 
	return 0;
}
