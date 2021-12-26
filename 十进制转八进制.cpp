#include<stdio.h>
#include<stdlib.h>
int main()
{
   int i,n,k=1,a[50];  //50个二进制位够大的吧
   printf("enter n:");
   scanf("%d",&n);
   if(n<=0) exit(0); //小于0的不要,等于0也没有必要了
   a[0]=n%2;
   do
  {
    n=n/2;
    i=n%2;
    a[k++]=i;
   }while(n!=0);
   for(i=49;a[i]==0;i--) ;  //找到二进制开始的地方,也就是最后一个余数在数组中的位置
     for(;i>-1;i--)
          printf("%d",a[i]);
}
