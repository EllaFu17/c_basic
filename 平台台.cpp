#include<stdio.h>
int main()
{
	int n,i;
	int b[100];
	int start=0,now=1,max=1;
	printf("请输入数组b:");
    scanf("%s",&b);
    n=sizeof(b)/sizeof(b[0]);
    for(i;i<n;i++)
    {
    	if(b[i]==b[start])
    	{
		now=now+1;
		}
    	else{
    		if(max<now)
    		{
    			max=now;
			}
			start=i;
			i=i+1; 
			now=1;
		}
	}
	printf("b中最长平台的长度为%d\n",max);
	return 0;
}
