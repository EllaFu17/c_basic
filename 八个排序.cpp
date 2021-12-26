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
//冒泡排序——对相邻的元素进行两两比较，顺序相反则进行交换，
//每一趟会将最小或最大的元素“浮”到顶端，最终达到完全有序 
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
//选择排序——每一趟从待排序的数据元素中选择最大（或最小）的一个元素作为首元素，
//直到所有元素排完为止。
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
//插入排序 ——每一步将一个待排序的记录，插入到前面已经排好序的有序序列中去，直到插完所有元素为止。 
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
//希尔排序 10,9,8,7,6, 5,4,3,2,1
//10 5;9 4;8 3;7 2;6 1;第一次分组
//5,4,3,2,1,10,9,8,7,6;第一次换之后
//gap=1->插入排序 
void shellsort(int data[],int length)
{
	int gap,i,j,k; //
	for(gap=length/2;gap>0;gap=gap/2) //将数组按照gap分组，不断二分到每组只剩下一个元素
	{
		for(i=gap;i<length;i++)//每轮排一组，将每组中的元素排序，小的在前
		{
			k=data[i];
			for(j=i-gap;j>=0&&data[i]<data[j];j=j-gap)
			{
				data[j+gap]=data[j];
			}//和上面的for循环一起，每组内将小的元素换到前面
			data[j+gap] = k;
		}
	}
	print(data, length);
 }
//归并排序 
//将有二个有序数列a[first...mid]和a[mid...last]合并
void mergearray(int a[], int first,int mid,int last,int temp[]) 
{ 
 int i=first,j=mid+1;//左右两段的起始
 int k=0;
 while(i<=mid&&j<=last)
 {
 if(a[i]<=a[j])
 temp[k++]=a[i++];
 else
 temp[k++]=a[j++];
 } 
 while(i<=mid)//防止还有元素未比较 
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
 mergesort(a,first,mid,temp);//左边有序
 mergesort(a,mid+1,last,temp);//右边有序
 mergearray(a,first,mid,last,temp);//再将二个有序数列合并
 } 
} 
//快速排序 
//计数排序——非比较
//5 6 2 1 4 4 5 9
//a:0 1 2 3 4 5 6 7 8 9
//    1 1   2 2 1     1      
void countsort(int a[],int length)//需要先得到待排列数组中最大元素 
{
	int i,j;
	int counted_a[10];//{0,0,0,0,0,0,0,0,0}
	int counted[10]={1,2,3,4,5,6,7,8,9,10} ;
	for(i=0;i<11;i++)//初始化开始计数之前，个数都为零 
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
	printf("冒泡排序:");
	bubblesort(data,10);
    printf("选择排序:");
	selectionsort(data,10);
    printf("插入排序:");
	insertsort(data,10);
    printf("希尔排序:");
	shellsort(data,10);
	printf("归并排序:");
	mergesort(data,0,9,temp);
	print(temp,10);
    printf("计数排序:");
	countsort(data,10);
	return 0;
}
