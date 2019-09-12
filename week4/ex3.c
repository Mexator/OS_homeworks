#include <stdio.h>
#include <string.h>
int main()
{
    char user_input[255] = {0};
    printf("Welcome to My Simplistic Shell.\nEnter exit to exit\n");
    while (strcmp(user_input, "exit"))
    {
        printf("Please, enter command:\n");
        scanf("%s", user_input);
        system(user_input);
    }
}