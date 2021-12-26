#include<stdio.h>
#include<stdlib.h>
void print(int data[], int length)
{
	for(int n=0;n<length;n++)
	{
		printf("%d",data[n]);
	}
	printf("\n");
}
//冒泡排序
//选择排序 
//插入排序 
void insertsort(int data[],int length)
{
	int j;
	for(int i=1;i<length;i++)
	{
		if(data[i]<data[i-1]) 
	{
			int temp=data[i];
			for(j=i-1; temp<data[j]&&j>=0;j--)//向前移动
			{
				
				data[j+1]=data[j];//每轮一个数向前插入
			 } 
			data[j]=temp;//temp放到移动后的位置 
	}
	}
	print(data, length);
}
//希尔排序 

int main()
{
	int data[10]={10,9,8,7,6,5,4,3,2,1};
	insertsort(data,10);
	return 0;
}
