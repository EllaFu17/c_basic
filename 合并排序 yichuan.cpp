#include<stdio.h>
#include<stdlib.h>
//将有二个有序数列a[first...mid]和a[mid...last]合并
//void mergearray(int a[], int first, int mid, int last, int cur[]) 
//{ 
// int i=first,j=mid+1;
// int m=mid,n=last;
// int k=0;
// int temp[5];
// while(i<=m&&j<=n)
// {
// if(a[i]<=a[j])
// temp[k++]=a[i++];
// else
// temp[k++]=a[j++];
// } 
// while(i<=m)
// temp[k++]=a[i++];
// while(j<=n)
// temp[k++]=a[j++]; 
// for(i=0;i<k;i++)
// a[first+i]=temp[i];
// for(k=0;k<2;k++)
// {
// 	cur[k]=temp[k];
// }
//}
void merge(int a[],int b[],int cur[])
{
	int alen=5,blen=4;
	int c[9];
	int i=0,j=0,n=0;
	for(i,j;i<alen&&j<blen&&n<(alen+blen)/2;){
		if(a[i]<b[j]){
			c[n]=a[i];
			i++;
			n++;
		}
		else if(a[i]==b[j]){
			c[n]=a[i];
			c[n+1]=b[j];
			i++;
			j++;
			n=n+2;
		}
		else{
			c[n]=b[j];
			j++;
			n++;
		}
	}
	for(int k=0;k<n/2;k++)
	cur[k]=c[k];
}
int main()
{
	int a[5]={1,3,5,7,9};
	int b[4]={2,4,6,8};
	int c[9];
//	int d[5]={1,3,4,7,9};
//	int e[5];
	int i;
	merge(a,b,c);
//    mergearray(d,0,2,4,e);
	for(i=0;i<5;i++){
	printf("%d  ",c[i]);}
	return 0;
}
