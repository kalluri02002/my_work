#include <stdio.h>

void print_sort(int[], int n);

int main()
{
    int size, iter;

    scanf("%d", &size);

    int arr[size];

    for (iter = 0; iter < size; iter++)
    {
        scanf("%d", &arr[iter]);
    }

    print_sort(arr, size);
}
// printsort function
void print_sort(int arr[], int n)
{
    int num = arr[0];
    int min = arr[0];
    int max = arr[0];
    printf("After sorting ");
    for (int j = 0; j < n; j++)
    {

        if (arr[j] < min)
        {

            min = arr[j];
        }
        if (arr[j] > max)
        {

            max = arr[j];
        }
    }
    printf("%d ", min);
    
    num = max;

    for (int i = 1; i < n; i++)
    {

        for (int j = 0; j < n; j++)
        {

            if (arr[j] < num && arr[j] > min)
            {

                num = arr[j];
            }
        }

        printf("%d ", num);
        min = num;
        num = max;
    }
    printf("\n");
    // after printing
    printf(" Original array values ");
    for (int j = 0; j < n; j++)
    {
        printf("%d ", arr[j]);
    }
}