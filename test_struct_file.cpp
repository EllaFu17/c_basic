#include <stdio.h>
#include <stdlib.h>

typedef struct students {
	char name;
	char num;
} students;
/*
write
*/
void writeExcel() {
	char ch[4][2]= { 'x' ,'a' ,'h','w','x' ,'a' ,'h','w' } ;

	int i ;
	FILE *fp = NULL ;
	fp = fopen("E:\\test4.xls","w") ;
	for (i=0 ; i<4 ; i++) {
		fprintf(fp,"%c\t%c\n",ch[i][0],ch[i][1] );
	}
	long fh= ftell(fp);//point
	printf("%ld\n",fh) ;
	rewind(fp);//head
	fh= ftell(fp);
	printf("%ld\n",fh) ;
	int result = fseek( fp, 0L, SEEK_END);//y to the end
	printf("%ld\n",ftell(fp));
	printf("pianyi%d\n",result);
	fclose(fp);
}
/*
    read

	*/
void readExcel() {
	FILE *fp;
	fp=fopen("D:\\test3.xls","r");
	if(fp==NULL) {
		printf("error!");
		exit(0);
	}

	students stu[100];
	int i;
	char a,b;
	for(i = 0 ; i < 6; i++) {
    //	while(!feof(fp)) {//为什么这个不行？ 

		fscanf(fp,"%c",&(stu[i].name));
		fseek(fp, 1L, SEEK_CUR);   //fp moves towards
		fscanf(fp,"%c",&(stu[i].num));
		fseek(fp, 2L, SEEK_CUR);
	}
	for(i = 0 ; i < 4 ; i++) { // \t制表符
//		if (stu[i].name==0) {
//			printf("end of file");
//			break;
//		}
		printf("%c\t%c\t\n",stu[i].name,stu[i].num);


	}
	fclose(fp);

	/*
	FILE *fp;
	//char filename[40]  ;
	int i,j ;
	char da[4][2] = {} ;

	//printf("File Name: ");
	//gets(filename);
	fp=fopen("E:\\test3.xls","r");
	if(fp==NULL){
		printf("error!");
		exit(0);
	}
	//fseek(fp, 0L, SEEK_SET);   // read from the first line
	for(i = 0 ; i < 4 ; i++){

		for(j = 0 ; j < 2 ; j++) {
			fscanf(fp,"%c",&da[i][j]);
			fseek(fp, 1L, SEEK_CUR);   
		}
		fseek(fp, 1L, SEEK_CUR);
	}

	for(i = 0 ; i < 4 ; i++){
		printf("%c\t%c\t\n",da[i][0],da[i][1]);
	}
	fclose(fp);
	//array
	*/

}

int main() {
	//writeExcel();
	readExcel();
	getchar() ;

	return 0;
}
