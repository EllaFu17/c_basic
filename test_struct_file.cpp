#include <stdio.h>
#include <stdlib.h>

typedef struct students {
	char name;
	char num;
} students;
/*
д�ļ�
*/
void writeExcel() {
	char ch[4][2]= { 'x' ,'a' ,'h','w','x' ,'a' ,'h','w' } ;

	int i ;
	FILE *fp = NULL ;
	fp = fopen("E:\\test4.xls","w") ;
	for (i=0 ; i<4 ; i++) {
		fprintf(fp,"%c\t%c\n",ch[i][0],ch[i][1] );
	}
	long fh= ftell(fp);//ָ��λ��
	printf("%ld\n",fh) ;
	rewind(fp);//ͷλ��
	fh= ftell(fp);
	printf("%ld\n",fh) ;
	int result = fseek( fp, 0L, SEEK_END);//y�ƶ���ĩβ
	printf("%ld\n",ftell(fp));
	printf("pianyi%d\n",result);
	fclose(fp);
}
/*
    ���ļ�

	*/
void readExcel() {
	FILE *fp;
	fp=fopen("D:\\test3.xls","r");
	if(fp==NULL) {
		printf("error!");
		exit(0);
	}// �����˳� ����ͷ�ļ�#include <stdlib.h>

	students stu[100];
	int i;
	char a,b;
	for(i = 0 ; i < 6; i++) {
    //	while(!feof(fp)) {//Ϊʲô������У� 

		fscanf(fp,"%c",&(stu[i].name));
		fseek(fp, 1L, SEEK_CUR);   //fpָ��ӵ�ǰλ������ƶ�
		fscanf(fp,"%c",&(stu[i].num));
		fseek(fp, 2L, SEEK_CUR);
	}
	for(i = 0 ; i < 4 ; i++) { // \t�Ʊ��
//		if (stu[i].name==0) {
//			printf("end of file");
//			break;
//		}
		printf("%c\t%c\t\n",stu[i].name,stu[i].num);


	}
	fclose(fp);

	/*
	ע�͵�����汾
	FILE *fp;
	//char filename[40]  ;
	int i,j ;
	char da[4][2] = {} ;

	//printf(" �����ļ���: ");
	//gets(filename);//�Ѿ������ĺ������ǡ���������
	fp=fopen("E:\\test3.xls","r");
	if(fp==NULL){
		printf("error!");
		exit(0);// �����˳� ����ͷ�ļ�#include <stdlib.h>
	}
	//fseek(fp, 0L, SEEK_SET);   // ���ļ���1�п�ʼ��ȡ
	for(i = 0 ; i < 4 ; i++){

		for(j = 0 ; j < 2 ; j++) {
			fscanf(fp,"%c",&da[i][j]);
			fseek(fp, 1L, SEEK_CUR);   //fpָ��ӵ�ǰλ������ƶ�����\t�Ʊ����
		}
		fseek(fp, 1L, SEEK_CUR);//����\n���з���
	}

	for(i = 0 ; i < 4 ; i++){
		printf("%c\t%c\t\n",da[i][0],da[i][1]);
	}
	fclose(fp);
	//ע������汾����
	*/

}

int main() {
	//writeExcel();
	readExcel();
	getchar() ;

	return 0;
}
