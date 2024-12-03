#include<stdio.h>
#include<stdlib.h>

int main(){

int arr[5]={0,1,2,3,4}; // Declares an array of 5 integers


//Printing 1D
printf("First element=%d\n",arr[0]);
for(int i=0;i<5;i++){
    printf("a[%d]=%d",i,arr[i]);
}


 // 2 rows and 3 columns
int matrix[2][3]={
    {0,1,2},
    {5,3,4}
};
//printing 2D
printf("First Element=%d\n",matrix[0][0]);
for(int i=0;i<2;i++){
    for(int j=0;j<3;j++){
    printf("a[%d][%d]=%d\t",i,j,matrix[i][j]);
    }
    printf("\n");
}


int *p = arr;         // p points to the first element of arr
printf("%d\n", *p);   // Prints 0
printf("%d\n", *(p+1)); // Prints 1 (next element)


int size = sizeof(arr) / sizeof(arr[0]); // Total size / size of one element

    return 0;
}