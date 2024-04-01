#include<stdio.h>
#include<stdlib.h>
#include<time.h> 
//��������
void print(int a[] ,int n){
	int i;
	for (i=0;i<n;i++){
		printf("%5d",a[i]);
	}
	printf("\n");
} 
//�ҳ������е����ֵ
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
		//Ū��ԭ���� 
	for(i=0;i<n;i++){
		a[i] = result[i];
	}
}
//������������
void Radixcountsort(int a[],int n){
	int imax = max(a,n);
	int iexp;  //λ��
	for(iexp=1;imax/iexp>0;iexp*=10){
		radixsort(a,n,iexp);
	} 
} 
//��������
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
//�������� 
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
	//����ÿ��Ԫ�س��ֵĴ��� 
	for(i=0;i<n;i++){
		count[a[i]]++;
	}
	//�޸�count��ȷ��Ԫ�س��ֵ�λ��
	for(i=1;i<imax+1;i++){
		count[i] += count[i-1];
	} 
	for(i=n-1;i>=0;i--){
		output[count[a[i]]-1] = a[i];
		count[a[i]]--;
	}
	//Ū��ԭ���� 
	for(i=0;i<n;i++){
		a[i] = output[i];
	}
	
}
//�ϲ����� 
void merge(int a[],int tempA[],int left,int mid,int right){
	 //����һ��
	 int l_sign = left;
	 //�Ұ��һ��
	 int r_sign = mid+1;
	 //��ʱ����ĵ�һ��
	 int sign = left;
	 //�ϲ�
	 while(l_sign <= mid && r_sign <= right){
	 	if(a[l_sign] < a[r_sign]){
	 		tempA[sign++] = a[l_sign++];
		 }
		 else{
		 	tempA[sign++] = a[r_sign++];
		 }
	 } 
	 //�ϲ�ʣ��� 
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
//�鲢����
void msort(int a[],int tempA[],int left,int right){
	if (left < right){
		int mid = (left + right)/2;
		//����ߵļ����� 
		msort(a,tempA,left,mid);
		//���ұߵļ�����
		msort(a,tempA,mid+1,right);
		//�ϲ�
		merge(a,tempA,left,mid,right); 
}
} 

//�鲢��������� 
void Mergesort(int a[],int n){
	int tempA[n];
	msort(a ,tempA , 0, n-1);
}
//��������
void swap(int* a,int* b){
	int temp;
	temp = *a;
	*a = *b;
	*b = temp;
} 
//��������
int partition(int a[],int low,int high){
	int pivot = a[high];
	int i = low - 1, j;
	for(j = low; j < high; j++){
		if(a[j] <= pivot){
			swap(&a[j] ,&a[++i]);
		}
	}
	//��ʱi+1�����ض�����pivot
	swap(&a[high],&a[i+1]); 
	return i+1; 
} 
//��������
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
	printf("\n���������ݸ���\n");
	scanf("%d",&num);
	printf("\n�����������ֵ\n");
	scanf("%d",&size);
	int a[num];
	srand(time(NULL));
	int data = rand() %size;
	for(i=0;i<num;i++){
		a[i] = rand() % size+1;
	}
	do{
		printf("\n-------------------------\n");
		printf("0.�˳�\n");
		printf("1.��������\n");
		printf("2.�鲢����\n");
		printf("3.��������\n");
		printf("4.��������\n");
		printf("5.������������\n");
		printf("6.����\n");
		scanf("%d",&choice);
		switch(choice){
			case 0:
				break;
			case 1:
				printf("\nѡ���������\n");
				start = clock();
				Insertsort(a,num);
				end = clock();
				usetime = ((double)(end-start))/CLOCKS_PER_SEC;
				printf("\n����ʱ��Ϊ��%.6lf s\n",usetime);
				break;
			case 2:
				printf("\nѡ��鲢����\n");
				start = clock();
				Mergesort(a,num);
				end = clock();
				usetime = ((double)(end-start))/CLOCKS_PER_SEC;
				printf("\n����ʱ��Ϊ��%.6lf s\n",usetime);
				break;
			case 3:
				printf("\nѡ���������\n");
				start = clock();
				Quicksort(a,0,num-1);
				end = clock();
				usetime = ((double)(end-start))/CLOCKS_PER_SEC;
				printf("\n����ʱ��Ϊ��%.6lf s\n",usetime);
				break;
			case 4:
				printf("\nѡ���������\n");
				start = clock();
				countsort(a, num);
				end = clock();
				usetime = ((double)(end-start))/CLOCKS_PER_SEC;
				printf("\n����ʱ��Ϊ��%.6lf s\n",usetime);
				break;
			case 5:
				printf("\nѡ�������������\n");
				start = clock();
				Radixcountsort(a,num);
				end = clock();
				usetime = ((double)(end-start))/CLOCKS_PER_SEC;
				printf("\n����ʱ��Ϊ��%.6lf s\n",usetime);
				break;
			case 6:
				printf("\n����\n");
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
	printf("\n���������ݸ���\n");
	scanf("%d",&num);
	printf("\n�����������ֵ\n");
	scanf("%d",&size);
	int a[num];
	srand(time(NULL));
	int data = rand() %size;
	for(i=0;i<num;i++){
		a[i] = rand() % size+1;
		fprintf(f,"%d  ",a[i]);
	}                                   //�����ļ� 
	fclose(f);
	f=fopen("startdata.txt","r"); 
	if(f==NULL)
	{
		printf("δ�ɹ����ļ�\n"); 
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
	printf("\nѡ���������\n");
	start = clock();
	Quicksort(a,0,num-1);
	end = clock();
	usetime = ((double)(end-start))/CLOCKS_PER_SEC;
	printf("\n����ʱ��Ϊ��%.6lf s\n",usetime);
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
	printf("\nѡ���������\n");
	start = clock();
	countsort(a, num);
	end = clock();
	usetime = ((double)(end-start))/CLOCKS_PER_SEC;
	printf("\n����ʱ��Ϊ��%.6lf s\n",usetime);
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
	printf("\nѡ���������\n");
	start = clock();
	Insertsort(a,num);
	end = clock();
	usetime = ((double)(end-start))/CLOCKS_PER_SEC;
	printf("\n����ʱ��Ϊ��%.6lf s\n",usetime);
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
	printf("\nѡ��鲢����\n");
	start = clock();
	Mergesort(a,num);
	end = clock();
	usetime = ((double)(end-start))/CLOCKS_PER_SEC;
	printf("\n����ʱ��Ϊ��%.6lf s\n",usetime);
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
	printf("\nѡ�������������\n");
	start = clock();
	Radixcountsort(a,num);
	end = clock();
	usetime = ((double)(end-start))/CLOCKS_PER_SEC;
	printf("\n����ʱ��Ϊ��%.6lf s\n",usetime);
	fclose(f);
 	fclose(fp);
}
int main(){
	//menu();
	perfer();
	system("pause"); 
	return 0;
}
