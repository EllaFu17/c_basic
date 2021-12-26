//����������ϲ�����ð�ݷ������ӡ
#include <stdio.h>
#include <stdlib.h>
#include <string.h>//ͷ�ļ� 
struct  list_node {
//����һ���࣬Ҳ���ǽڵ�ĸ�ʽ 
	int data ;//�ڵ�������� 
	struct list_node *next ;//ָ����  
};

typedef struct list_node list_single;
//�ú��ߴ���ǰ�� 

list_single *create_list_node(int data) {
	//����һ������ͷ���ġ����캯���� 
	list_single *node = NULL ;//�ڵ� ��ʼ�� 
	node = (list_single *)malloc(sizeof(list_single));
	//������ڵ㸳��ռ�  *������˼��ǿ��ת���ռ�Ϊָ���� 
	if(NULL == node ) {
		printf("malloc fair!\n");
	}//������� 
	memset(node,0,sizeof(list_single));
	//���ϴ�Ľṹ�����ָ���������췽����
	//�����������������node�����ֵȫ��0 
	node->data = data ;//��������βδ�������ʵ�θ���node->data
	//��Ϊ��ͷ��㣬����������һ������ Ҳ���ǲ��ô涫������ʱҲ���Դ洢ָ��ĳ��� 
	node->next = NULL ;
	//���ͷ��㻹û���õ�������ָ���� ��ָ���κεط� 
	return node ;//����ֵ�Ǹմ�����ͷ��㣻
	//��Ϊû���� void�������������Կ�����������ķ���ֵ 
}


list_single *add_list_node(list_single *before,int total) { 
//����һ����ͷ���Ӻ������ĺ����������������������������βΣ�
//��һ�������ǽ��в�����ͷ��㣬�ڶ�������ע����߽Ӷ��ٸ���� 
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
		before->next=NULL;//ѭ��������������㸳ֵ���ѽ�� �������� 

	}
}
void list_print(list_single *head) {//����һ����ӡ�������ѽڵ������ӡ 
	list_single *temp;//����һ��list��single��ָ�� 

	temp = head;//���βδ�����ͷ�����temp���� 

	printf("list information :\n");

	while(NULL !=temp->next) {//NULL != == ��ֹ�������

		temp = temp->next;//��temp��һ���ڵ��ֵ����temp
		//ʵ�ʾ��ǽ�ָ��������һ���ڵ� 
		printf("list\t %d\n", temp->data);//��ӡ��ǰ�ڵ�������� 

	}
}

list_sort(list_single *head){//����һ������������ͷ���head
//����������������ݽ��н������� 
	list_single *p,*q,*r;//��������list-single��ָ����ð�ݷ�������������� 
for(p=head->next;p!=NULL;p=p->next){
	//�ӵڶ����ڵ㿪ʼ��û�е�ͷ������������һ���ڵ� 
	for(q=p->next;q!=NULL;q=q->next){//����һ��ͬ�� 
		if(p->data<q->data){//���� 
			r->data=q->data;
			q->data=p->data;
			p->data=r->data;//���ݽ��� 
		
		}
	}
}
}

	void merge(list_single *head,list_single *head2) {
		//����ϲ�ͷ���head�����������head2����������    
	while(head->next!=NULL)//������ͷָ���ָ����һ���ڵ�
	//Ҳ����ָ��ָ��head��������������һ���ڵ� 
	head=head->next;
	head->next=head2->next;
	//��head��������������һ���ڵ��ָ����ָ��head2����������ĵڶ����ڵ� 

}


int main(void) {
	int data =0 ;

	list_single *node_ptr = create_list_node(data); //����һ��ͷ�ڵ�
	printf("node_ptr->data=%d\n",node_ptr->data);   //��ӡ�ڵ��������
	printf("node_ptr->next=%d\n",node_ptr->next);
	add_list_node(node_ptr,5);
	list_print(node_ptr);
	list_single *node_ptr2 = create_list_node(data); //����һ��ͷ�ڵ�
	printf("node_ptr2->data=%d\n",node_ptr2->data);   //��ӡ�ڵ��������
	printf("node_ptr2->next=%d\n",node_ptr2->next);
	add_list_node(node_ptr2,5);
	list_print(node_ptr2);
	merge(node_ptr,node_ptr2);
	list_print(node_ptr);
	
	list_sort(node_ptr);
	list_print(node_ptr);//�����       
	return 0 ;//�����������������������캯�� 
}
