#include<stdio.h>
#include<stdlib.h> 
struct line_student{
 int length;
 int front;
 int rear;
};
typedef struct line_student line; 
//构建5个空间的队列 
int *createline(){
 int *student;
 student=(int *)malloc(sizeof(5*sizeof(int)));
 if(student==NULL){
  printf("Error!");
  return 0;
 }
 return student;
}
void put_student(int num,int *student,line *a){
 if(a->rear<4){
  *(student+a->rear)=num;
  a->rear++;
 }
 else
 printf("Full!"); 
}
void out_student(line *a){
 if(a->front<a->rear)
    a->front++;
    else
    printf("Empty！"); 
}
int main(){
 line *m; 
 int *students;
 int i;
 m->length=5;
 m->front=0;
 m->rear=0; 
    students=createline();
    for(i=0;i<4;i++){
        put_student(i,students,m);
 }
 for(i=0;i<4;i++){
  out_student(m);
 }
    printf("front:%d,rear:%d",m->front,m->rear);
    return 0;
} 
