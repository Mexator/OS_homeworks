#include <stdlib.h>
#include <stdio.h>

int main(int argc, char* argv[])
{
    int n;
    sscanf(argv[1],"%d",&n);
    int width = 2*n - 1;
    for(int i=0;i<n;i++)
    {
        for (int j = 0; j < (width-(2*i-1))/2; j++)
        {
            printf(" ");
        }
        for (int j = 0; j < (2*i-1); j++)
        {
            printf("*");
        }
        printf("\n");
    }
}
