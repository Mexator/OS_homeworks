#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#define LONGEST_STRING 1000
int main()
{
    char input_str[LONGEST_STRING]={0};
    printf("Input string:");
    scanf("%s",input_str);
    for(int i = strlen(input_str);i>=0;i--)
    {
        printf("%c",input_str[i]);
    }
    printf("\n");
}