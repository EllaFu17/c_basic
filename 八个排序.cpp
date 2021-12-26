#include<stdio.h>
#include<stdlib.h>
void print(int data[], int length)
{
	for(int n=0;n<length;n++)
	{
		printf("%d ",data[n]);
	}
	printf("\n");
}
//ð�����򡪡������ڵ�Ԫ�ؽ��������Ƚϣ�˳���෴����н�����
//ÿһ�˻Ὣ��С������Ԫ�ء����������ˣ����մﵽ��ȫ���� 
void bubblesort(int data[],int length)
{
	int i ,j;
	int t;
	for(i=0;i<length-1;i++)
	{
		for(j=0;j<length-i-1;j++){
			if(data[j]>data[j+1]){
				t=data[j+1];
				data[j+1]=data[j];
				data[j]=t;
			}
		}
	}
    print(data, length);
} 
//ѡ�����򡪡�ÿһ�˴Ӵ����������Ԫ����ѡ����󣨻���С����һ��Ԫ����Ϊ��Ԫ�أ�
//ֱ������Ԫ������Ϊֹ��
void selectionsort(int data[],int length)
{
	int i,j,max;
	int temp;
	for(j=length;j>1;j--)
	{
		max=0;
		for(i=0;i<j;i++)
		if(data[i]>data[max])
		max=i;
		if(max!=j-1)
		{
			temp=data[max];
			data[max]=data[j-1];
			data[j-1]=temp;
		}
	}
	print(data, length);
 } 
//�������� ����ÿһ����һ��������ļ�¼�����뵽ǰ���Ѿ��ź��������������ȥ��ֱ����������Ԫ��Ϊֹ�� 
void insertsort(int data[],int length)
{
	int j;
	for(int i=1;i<length;i++)
	{
		if(data[i]<data[i-1]) 
	{
			int temp=data[i];
			for(j=i-1; temp<data[j]&&j>=0;j--)//��ǰ�ƶ�
			{
				
				data[j+1]=data[j];//ÿ��һ������ǰ����
			 } 
			data[j]=temp;//temp�ŵ��ƶ����λ�� 
	}
	}
	print(data, length);
}
//ϣ������ 10,9,8,7,6, 5,4,3,2,1
//10 5;9 4;8 3;7 2;6 1;��һ�η���
//5,4,3,2,1,10,9,8,7,6;��һ�λ�֮��
//gap=1->�������� 
void shellsort(int data[],int length)
{
	int gap,i,j,k; //
	for(gap=length/2;gap>0;gap=gap/2) //�����鰴��gap���飬���϶��ֵ�ÿ��ֻʣ��һ��Ԫ��
	{
		for(i=gap;i<length;i++)//ÿ����һ�飬��ÿ���е�Ԫ������С����ǰ
		{
			k=data[i];
			for(j=i-gap;j>=0&&data[i]<data[j];j=j-gap)
			{
				data[j+gap]=data[j];
			}//�������forѭ��һ��ÿ���ڽ�С��Ԫ�ػ���ǰ��
			data[j+gap] = k;
		}
	}
	print(data, length);
 }
//�鲢���� 
//���ж�����������a[first...mid]��a[mid...last]�ϲ�
void mergearray(int a[], int first,int mid,int last,int temp[]) 
{ 
 int i=first,j=mid+1;//�������ε���ʼ
 int k=0;
 while(i<=mid&&j<=last)
 {
 if(a[i]<=a[j])
 temp[k++]=a[i++];
 else
 temp[k++]=a[j++];
 } 
 while(i<=mid)//��ֹ����Ԫ��δ�Ƚ� 
 temp[k++]=a[i++];
 while(j<=last)
 temp[k++]=a[j++]; 
 for(i=0;i<k;i++)
 a[first+i]=temp[i];
}
void mergesort(int a[],int first,int last,int temp[])
{
 if(first<last)
 {
 int mid=(first+last)/2;
 mergesort(a,first,mid,temp);//�������
 mergesort(a,mid+1,last,temp);//�ұ�����
 mergearray(a,first,mid,last,temp);//�ٽ������������кϲ�
 } 
} 
//�������� 
//�������򡪡��ǱȽ�
//5 6 2 1 4 4 5 9
//a:0 1 2 3 4 5 6 7 8 9
//    1 1   2 2 1     1      
void countsort(int a[],int length)//��Ҫ�ȵõ����������������Ԫ�� 
{
	int i,j;
	int counted_a[10];//{0,0,0,0,0,0,0,0,0}
	int counted[10]={1,2,3,4,5,6,7,8,9,10} ;
	for(i=0;i<11;i++)//��ʼ����ʼ����֮ǰ��������Ϊ�� 
	{
		counted_a[i]=0;
	}
	for(j=0;j<10;j++)
	{
		counted_a[a[j]]++;
	}
	for(j=0;j<10;)
	{
		if(counted_a[a[j]]==0)
		{
			j++;
		}
		else
		{
			while(counted_a[a[j]]!=0)
			{
				printf("%d ",counted[j]);
				counted_a[a[j]]--;
			}
			j++;
		}
	}
}
int main()
{
	int data[10]={10,9,8,7,6,5,4,3,2,1};
	int temp[10];
	printf("ð������:");
	bubblesort(data,10);
    printf("ѡ������:");
	selectionsort(data,10);
    printf("��������:");
	insertsort(data,10);
    printf("ϣ������:");
	shellsort(data,10);
	printf("�鲢����:");
	mergesort(data,0,9,temp);
	print(temp,10);
    printf("��������:");
	countsort(data,10);
	return 0;
}
