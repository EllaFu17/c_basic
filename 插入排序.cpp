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
//ð������
//ѡ������ 
//�������� 
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
//ϣ������ 

int main()
{
	int data[10]={10,9,8,7,6,5,4,3,2,1};
	insertsort(data,10);
	return 0;
}
