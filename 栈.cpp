#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct  xiaoji
{
	int bianhao;
	struct xiaoji *shang;
	struct xiaoji *xia;
};
struct jiwo
{
	struct xiaoji *di;
	struct xiaoji *ding;
};
struct xiaoji *putxiaoji(int n)
{
	struct xiaoji *ding;
	struct xiaoji *xin;
	xin= (xiaoji *)malloc(sizeof(xiaoji));
	ding=(xiaoji *)malloc(sizeof(xiaoji));
	int m;
	xin->shang=NULL;
	xin->xia=NULL;
	ding->shang=NULL;
	ding->xia=xin;
	for(m=n;m>0;m--)
	{
		printf("�����%dֻ�����:",(n-m+1));
		scanf("%d",	xin->bianhao);
	    xin->shang = ding;
	    ding->shang=NULL;
	    ding->bianhao=xin->bianhao;
	}
	return ding;
}
void getxiaoji(struct xiaoji *ding)
{
	struct xiaoji *qu;
	int i,j;
	printf("����ȡ��С����Ŀ:");
	scanf("%d",&i);
	for(j=0;j<i;j++)
	{
	qu=ding;
	if((qu->xia)!=NULL)
	ding=qu->xia;	
	free(qu);
	}
}
void kanxiaoji(struct xiaoji *ding)
{
	printf("������С���ı�ţ�\n");
	struct xiaoji *now=ding;
	if(now==NULL)
	{
		printf("��\n");
	}
	while(now!=NULL)
	{
		printf("%d\n",now->bianhao);
		now=now->xia;
	}
	if(now!=NULL)
	free(now);
 } 
void diyi(struct xiaoji *ding)
{
	int num;
	num=ding->xia->bianhao;
	printf("��һֻС���ı���ǣ�%d",num);
}
void zuihou(struct xiaoji *ding)
{
	struct xiaoji *p;
	p=ding->xia;
	while(p->xia!=NULL)
    p=p->xia;
    printf("���һֻС�����Ϊ%d\n",p->bianhao);
}
void chaijiwo(struct xiaoji *ding)
{
	struct xiaoji *chai;
	int n=0;
	while(ding->xia!=NULL)
	{
		chai=ding;
		ding=ding->xia;
		n++;
	}
	free(ding);
	printf("���Ѳ����ɾ��С��%dֻ��\n",n);
}
int main()
{
	int num;
	printf("������Ҫ�����С��������");
	scanf("%d",&num);
	struct xiaoji *chicken=putxiaoji(num);
	kanxiaoji(chicken);
	getxiaoji(chicken);
	kanxiaoji(chicken);
	diyi(chicken);
	zuihou(chicken);
	chaijiwo(chicken);
	kanxiaoji(chicken);
}
