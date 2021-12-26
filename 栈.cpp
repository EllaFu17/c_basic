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
		printf("输入第%d只鸡编号:",(n-m+1));
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
	printf("输入取出小鸡数目:");
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
	printf("鸡窝里小鸡的编号：\n");
	struct xiaoji *now=ding;
	if(now==NULL)
	{
		printf("空\n");
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
	printf("第一只小鸡的编号是：%d",num);
}
void zuihou(struct xiaoji *ding)
{
	struct xiaoji *p;
	p=ding->xia;
	while(p->xia!=NULL)
    p=p->xia;
    printf("最后一只小鸡编号为%d\n",p->bianhao);
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
	printf("鸡窝拆除，删除小鸡%d只。\n",n);
}
int main()
{
	int num;
	printf("请输入要放入的小鸡个数：");
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
