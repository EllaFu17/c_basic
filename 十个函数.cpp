#include <stdio.h>
#include <string.h>
//输出相同的字符串
char *StrAssign(char string[],char chars[])
{if(strlen(chars)>100)
 return 0;
 else
 { int i;
 	string[0]=strlen(chars);
 	for(i=1;i<=string[0];i++)
	 {
 		string[i]=chars[i-1];
	 }
	 string[i]='\0';
	 return string;
 }
} 
//计算长度
int Strlength(char *string)
{
	int n=0,i=0;
	while(string[i]!='\0')
	{
	  n++;
	  i++;
	}
	return n;
} 
//比较字符串
int StrCompare(char *String1,char *String2)
{int i;
for(i=1;i<=String1[0]&&i<=String2[0];i++){
if(String1[i]!=String2[i])
return String1[i]-String2[i];}
return String1[0]-String2[0]; 
} 
//连接字符串 
char StrConnect(char *string1,char *string2)
{int n,m,i;
n=strlen(string1);
m=strlen(string2);
for(i=n;i<n+m;i++)
string1[i]=string2[i-n+1];
}
//取子串 n-m
char Substr(char string1[],char string2[],int n,int m)
{
	int i,r=0;
	for(i=n;i<m;i++)
	{
	string1[r]=string2[i];
	r++;
	}
string1[i]='\0';
}
//串拷贝，2->1 
char Strcopy(char string1[],char string2[])
{
	int i,m;
	m=strlen(string2);
	for(i=0;i<m;i++)
	string1[i]=string2[i];
}
//串判空
int StrEmpty(char string1[])
{
	if (string1[0]=0)
	printf("string is empty\n");
	else
	printf("string isn't empty\n");
} 
//清空串
char ClearString(char stringm[100])
{if (stringm[0]=0)
return 0;
else{
	int i;
	for(i=0;i<100;i++);
	stringm[i]='\0';
}
} 
//找子串1在字符串2中的位置
int Index(char string1[],char string2[],int x)
{int m,i,n,j;
m=strlen(string2);
n=strlen(string1);
for(i=0;i<m;i++);
if (string2[i]=string1[1])
{for(j=1;j<i+n;j++)
if (string2[i+j]=string1[1+j])
x=i;
else break;
}
else x=0 ;
return x;
} 

char Replace(char *S,char *T,char *V)
{
int a,b,i,j,t;
a=strlen(S);
b=strlen(T);	
for(i=1;i<=a-b;i++) 
{
	for(j=1;j<=b;j++)
	{
	  if(S[i+j-2]!=T[j])
	  break;
	}
	}
	if(j!=b)
	{
		for(t=b;t>=1;t--)
	 {
	  S[i+t-2]=V[t]; 
	}	
	}	
return *S;
} 
int main()
{char String_Mark[100];
 StrAssign(String_Mark,"My name is Mark");
 printf("%d",String_Mark[0]);
 printf("%s\n",String_Mark+1);
 char String_Tom[100];
 StrAssign(String_Tom,"My name is Tom");
 printf("%d",String_Tom[0]);
 printf("%s\n",String_Tom+1);
 
 int Mark_Length=Strlength(String_Mark);
 printf("Mark_Length=%d\n",Mark_Length);
 
 int compare=StrCompare(String_Mark,String_Tom);
 printf("%d\n",compare);
 
 StrConnect(String_Mark,String_Tom);
 printf("%s\n",String_Mark+1);
 
 char Sub_String[100];
 Substr(Sub_String,String_Mark,1,7);
 printf("%s\n",Sub_String);
 
 char String_Cop[100];
 Strcopy(String_Cop,String_Tom);
 printf("%s\n",String_Cop);
 
 StrEmpty(String_Mark);
 
 ClearString(String_Tom);
 printf("%s\n",String_Tom);
 
 int x;
 Index(String_Mark,String_Tom,x);
 printf("%d\n",x);
 
 char p[]={"My name is A"};
 Replace(p,String_Tom,wojiaomark;
 printf("%s\n",p);
 return 0;
 
}



