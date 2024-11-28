//Include C standard library for usue of built-in functions like printf and scanf
#include<stdio.h>

//global variable accessible everywhere
int  max=5;

//Entry point of  C progran
int main(){
//Local variable accessible only within the main function
int min=1;
//floating point numbers
float avg=2.0;
 avg=(float)((max-min)/2);//cast to float else integer division is performed 
//Characters
char a='A';
char b=a+1 ;//returns B
/*
\n	Newline
\t	Tab
\'	Single Quote
\"	Double Quote
\\	Backslash
*/
//built-in output function
printf("max=%d,min=%d,avg=%f,a=%c,b=%c\n",min,max,avg,a,b);
//built-in input function
printf("Enter new max:\t");
scanf("%d",&max);
printf("new max is %d",max);

return 0;//end of program execution
}