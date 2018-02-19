/*
    Insertion Sort

    Algorithm:
    1. For every element i in the array, check if the current element is smaller than their previous elements
    2. If yes, then shift the elements towards the right
    3. If no, then set the element at that index

*/
#include<stdio.h>

void InsertionSort(int[], int);
void display(int [], int);

void main()
{
    int n, i;
    fflush(stdin);
    printf("\nEnter the number of elements : ");
    scanf("%d",&n);
    int arr[n];
    printf("\nEnter the elements : ");
    for(i=0; i<n; i++)
    {
        scanf("%d",&arr[i]);
    }

    InsertionSort(arr, n);
    display(arr, n);
    
}

void InsertionSort(int arr[], int n)
{
    int flag = 1, i, j, k, current;
    for(i=1; i<n; i++)
    {
        current = arr[i];
        for(j=i; j>0 && current<arr[j-1]; j--)
        {
            arr[j] = arr[j-1];
        }
        arr[j] = current;
    }
}

void display(int arr[], int n)
{
    int i;
    printf("\nThe Sorted Array is : ");
    for(i=0; i<n; i++)
    {
        printf("%d ",arr[i]);
    }
    printf("\n\n");
}

/*
    Insertion Sort is better than Bubble Sort because it involves shifting numbers instead of swapping which has a better space complexity
    It is generally preffered over Bubble Sort or Selection Sort because it is faster
*/