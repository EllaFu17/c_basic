#include<stdio.h>
#include<math.h> 
int main(){
	int x =0;
	double n = 1e-3;
	double max = x + 10*sin(10*x)+5*cos(5*x) ;
	double min = x + 10*sin(10*x)+5*cos(5*x) ;
	for(x=0;x<100;x=x+n){
	 double sum = x + 10*sin(10*x)+5*cos(5*x) ;
	 if(sum>max){
	 	max=sum;
	 }
	 if(sum<min){
	 	min =sum ;
	 }
		
	}
	printf("max:%lf\n",max);
	printf("min:%lf\n",min);
	return 0;
}
