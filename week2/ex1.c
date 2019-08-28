#include <stdlib.h>
#include <stdio.h>
int main()
{
    int int_var = __INT_MAX__;
    float float_var = __FLT_MAX__;
    double double_var = __DBL_MAX__;
    printf("Integer: size %u value %d \n",sizeof(int_var), int_var);
    printf("Float  : size %u value %e \n",sizeof(float_var), float_var);
    printf("Double : size %u value %e \n",sizeof(int_var), double_var);
}