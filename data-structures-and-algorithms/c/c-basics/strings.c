#include<stdio.h>
#include<string.h>
#include<stdlib.h>

/* 1. Write a program that takes a string input from the user, copies it to another 
 string, and then prints the copied string*/

void copy(const char*from,char* to){
   printf("str1=%s\t str2=%s\t copied=%s \n",from,to,strcpy(to,from));
} 

// Write a program that takes two string inputs from the user and concatenates them into a single string. Print the concatenated string.

void concat(const char*from,char*to){
   printf("str1=%s\t str2=%s\t concatenated=%s \n",from,to,strcat(to,from));
}

// Write a program that takes two strings from the user and checks whether they are equal. Print "Equal" if they match, and "Not Equal" otherwise.
void compare(char*str1,char*str2){

  switch(strcmp(str1,str2)){
      case 0:
      printf("Strings are thesame\n");
      break;
    default :
    printf("Strings do not match\n");
  }
}

// Write a program that takes a string input from the user and reverses it. Store the reversed string in a new string and print it.
void reverse(char *str){
unsigned  int last=(int)(strlen(str))-1;
unsigned  int first=0;
  while(first<last){
    char temp=str[first];
    str[first]=str[last];
    str[last]=temp;
     first++;
     last--;
  }
    printf("reversed=%s",str);
}

int main(){
  char str1[100], str2[100];
  printf("Enter first string:\t");
  scanf("%s", str1);
  printf("Enter second string:\t");
  scanf("%s",str2);
// copy(str1,str2);
// concat(str1,str2);
// compare(str1,str2);
reverse(str1);
// reverse(str2);
 return 0;
}

