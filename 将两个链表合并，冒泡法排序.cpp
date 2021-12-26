//将两个链表合并，用冒泡法排序打印
#include <stdio.h>
#include <stdlib.h>
#include <string.h>//头文件 
struct  list_node {
//定义一个类，也就是节点的格式 
	int data ;//节点的数据域 
	struct list_node *next ;//指针域  
};

typedef struct list_node list_single;
//用后者代替前者 

list_single *create_list_node(int data) {
	//定义一个创建头结点的“构造函数” 
	list_single *node = NULL ;//节点 初始化 
	node = (list_single *)malloc(sizeof(list_single));
	//给这个节点赋予空间  *）的意思是强制转换空间为指针型 
	if(NULL == node ) {
		printf("malloc fair!\n");
	}//防错机制 
	memset(node,0,sizeof(list_single));
	//给较大的结构体或者指针清零的最快方法，
	//进行这个操作后结果是node里面的值全是0 
	node->data = data ;//把输入的形参传过来的实参付给node->data
	//因为是头结点，所以数据域一般是零 也就是不用存东西，有时也可以存储指针的长度 
	node->next = NULL ;
	//这个头结点还没有用到，所以指针域 不指向任何地方 
	return node ;//返回值是刚创建的头结点；
	//因为没有用 void创建函数，所以可以有有意义的返回值 
}


list_single *add_list_node(list_single *before,int total) { 
//创建一个给头结点接后续结点的函数，这个函数有两个输入参数（形参）
//第一个参数是进行操作的头结点，第二个参数注明后边接多少个结点 
	int i,data;
	
	
	list_single *node = NULL ;
	for(i=0; i<total; i++) {

		node = (list_single *)malloc(sizeof(list_single));
		if(node == NULL) {
			printf("malloc fair!\n");
		}
	
		before->next = node;
		before = node;
		printf("input data:");
		scanf("%d",&data);
		before->data=data;
		before->next=NULL;//循环操作给各个结点赋值并把结点 单向链接 

	}
}
void list_print(list_single *head) {//构造一个打印函数，把节点逐个打印 
	list_single *temp;//输入一个list—single型指针 

	temp = head;//把形参传来的头结点用temp代替 

	printf("list information :\n");

	while(NULL !=temp->next) {//NULL != == 防止输入错误

		temp = temp->next;//把temp下一个节点的值赋给temp
		//实质就是将指针移向下一个节点 
		printf("list\t %d\n", temp->data);//打印当前节点的数据域 

	}
}

list_sort(list_single *head){//构造一个排序函数，对头结点head
//所引导的链表的数据进行降序排序 
	list_single *p,*q,*r;//输入三个list-single型指针用冒泡法对链表进行排序 
for(p=head->next;p!=NULL;p=p->next){
	//从第二个节点开始，没有到头，光标就移向下一个节点 
	for(q=p->next;q!=NULL;q=q->next){//与上一行同理 
		if(p->data<q->data){//降序 
			r->data=q->data;
			q->data=p->data;
			p->data=r->data;//数据交换 
		
		}
	}
}
}

	void merge(list_single *head,list_single *head2) {
		//构造合并头结点head引导的链表和head2引导的链表    
	while(head->next!=NULL)//链表不到头指针就指向下一个节点
	//也就是指针指向head引导的链表的最后一个节点 
	head=head->next;
	head->next=head2->next;
	//把head引导的链表的最后一个节点的指针域指向head2引导的链表的第二个节点 

}


int main(void) {
	int data =0 ;

	list_single *node_ptr = create_list_node(data); //创建一个头节点
	printf("node_ptr->data=%d\n",node_ptr->data);   //打印节点里的数据
	printf("node_ptr->next=%d\n",node_ptr->next);
	add_list_node(node_ptr,5);
	list_print(node_ptr);
	list_single *node_ptr2 = create_list_node(data); //创建一个头节点
	printf("node_ptr2->data=%d\n",node_ptr2->data);   //打印节点里的数据
	printf("node_ptr2->next=%d\n",node_ptr2->next);
	add_list_node(node_ptr2,5);
	list_print(node_ptr2);
	merge(node_ptr,node_ptr2);
	list_print(node_ptr);
	
	list_sort(node_ptr);
	list_print(node_ptr);//排序后       
	return 0 ;//创建主函数并调用上述构造函数 
}
