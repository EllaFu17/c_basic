#include<stdio.h>
#include<stdlib.h>
int main()
{
   int i,n,k=1,a[50];  //50��������λ����İ�
   printf("enter n:");
   scanf("%d",&n);
   if(n<=0) exit(0); //С��0�Ĳ�Ҫ,����0Ҳû�б�Ҫ��
   a[0]=n%2;
   do
  {
    n=n/2;
    i=n%2;
    a[k++]=i;
   }while(n!=0);
   for(i=49;a[i]==0;i--) ;  //�ҵ������ƿ�ʼ�ĵط�,Ҳ�������һ�������������е�λ��
     for(;i>-1;i--)
          printf("%d",a[i]);
}
