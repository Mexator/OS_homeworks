#include <stdlib.h>
#include <stdio.h>


void swap(int *a,int *b)
{
    int tmp = *a;
    *a=*b;
    *b= tmp;
}

int main()
{
    int a,b;
    printf("Enter first number:\n");
    scanf("%d",&a);
    printf("Enter second number:\n");
    scanf("%d",&b);
    swap(&a,&b);
    printf("first= %d\nsecond= %d\n",a,b);
}