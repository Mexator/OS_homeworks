#include <stdio.h>
void bubble_sort(int *arr, int size);
int main()
{
    int arr[10] = {9, 8, 7, 6, 5, 4, 3, 2, 1, 0};
    bubble_sort(arr, sizeof(arr) / sizeof(int));
    for (int i = 0; i < 10; i++)
    {
        printf("%d\n", arr[i]);
    }
    return 0;
}
void bubble_sort(int *arr, int size)
{
    for (int i = 0; i < size; i++)
    {
        for (int j = 1; j < size; j++)
        {
            if (arr[j] < arr[j - 1])
            {
                int tmp = arr[j];
                arr[j] = arr[j - 1];
                arr[j - 1] = tmp;
            }
        }
    }
}