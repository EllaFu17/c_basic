#include<stdio.h> 
int a[11]={5,13,19,21,37,56,64,75,80,88,92};
int z(int low,int high,int n)
{
	int m;
	if(low==high&&a[low]!=n) 
	return -1;
	m=(high+low)/2;
	if(a[m]==n) return m;
	if(a[m]>n) return (z(low,m-1,n));
	if(a[m]<n) return (z(m+1,high,n));
}
int main()
{
	int x=19,a;
	a=z(0,10,x);
	if(a==-1) printf("нч");
	else
	printf("%d",a);
	return 0;
}
