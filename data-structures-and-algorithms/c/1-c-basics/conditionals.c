#include<stdio.h>
int main(){
int number;
printf("Enter Number:\t");
scanf("%d",&number);

//if-elseif-else
if(number<10){
    printf("Number is less than 10\n");
}else if(number==10){
    printf("Number is 10\n");
}else{
    printf("Number is greater than 10\n");
}

//switch
switch(number){
    case 1:
    printf("Number is 1\n");
    break;
     case 10:
     printf("Number is 10\n");
     break;
    default :
    printf("Number is neither 1 nor 10\n");
    break;
}
    return 0;
}