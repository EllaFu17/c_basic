#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct  list_node 
{
	int data ;//������Ϣ�������� 
	struct list_node *next ;//ָ����һ�ڵ��ָ�� 
	struct list_node *syg;//ָ����һ�ڵ��ָ�� 
};
//����ͷ��㲢��ʼ�� 
typedef struct list_node list_single;
list_single *create_list_node(int data) 
{
	list_single *node = NULL ; //ͷ��� 
	node = (list_single *)malloc(sizeof(list_single));//����ռ� 
	if(NULL == node ) 
	{
		printf("malloc fair!\n");
	}
	else{
	node->data = data ;//��ͷ��㸳ֵ 
	node->next = NULL ;//ͷ���ָ������� ����Ϊ��������û�н�� 
	}
	return node ;
}
list_single *add_list_node(list_single *tail,int total) //β�ڵ㣬�ٴ���total����� 
{
	int i,data;
	list_single *node = NULL; 
	list_single *node1=NULL;//���洴���½��ĵ�ַ
	for(i=0; i<total; i++) 
	{
	    node = (list_single *)malloc(sizeof(list_single));
		if(node == NULL) 
		{
			printf("malloc fair!\n");
		}
	    node1 =tail;
		tail->next = node;
		tail = node;
		printf("input data:");
		scanf("%d",&data);
		tail->data=data;
		tail->next=NULL;
        tail->syg=node1;
	}
}
void list_print(list_single *head) 
{
	list_single *temp;
    temp = head;
    printf("list information :\n");
    while(NULL !=temp->next) 
	{
		temp = temp->next;
		printf("list\t %d\n", temp->data);

	}
}
void merge(list_single *head,list_single *head2) 
{
	while(head->next!=NULL)
	head=head->next;
	head->next=head2->next;
}
int main(void) 
{
	int data =0;
	list_single *node_ptr = create_list_node(data);
	printf("node_ptr->data=%d\n",node_ptr->data);
	printf("node_ptr->next=%d\n",node_ptr->next);
	add_list_node(node_ptr,5);
	list_print(node_ptr);
	list_single *node_ptr1 = create_list_node(data);
	printf("node_ptr1->data=%d\n",node_ptr1->data);
	printf("node_ptr1->next=%d\n",node_ptr1->next);
	add_list_node(node_ptr1,4);
	list_print(node_ptr1);
	merge(node_ptr,node_ptr1);
	list_print(node_ptr);
	return 0 ;
}
