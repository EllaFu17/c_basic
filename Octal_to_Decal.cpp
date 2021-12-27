#include<math.h>
#include<cstdio>
#include<string.h>
#include<iostream>
using namespace std;
int BToO(char s[])
{
    int j=1,sum=0;
    int l=strlen(s);
    for(int i=l-1; i>=0; i--)
    {
        sum+=j*(s[i]-'0');
        j*=8;
    }
    return sum;
}
int main()
{
    char s[100];
    while(scanf("%s",s)!=EOF)
    printf("%d\n",BToO(s));
    return 0;
}

