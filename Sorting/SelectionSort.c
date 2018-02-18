/*
    Selection Sort
    
    Algorithm - 
        1. For i=0 && i<n
        2. Find the minimum element from the array elements with index > i
        3. Swap the minimum element with array element at index i
        4. Increment i
*/

#include<stdio.h>

void selectionSort(int[], int);
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

    selectionSort(arr, n);
    display(arr, n);
    
}

void selectionSort(int arr[], int n)
{
    int i, j, min_element, min_index;
    for(i=0; i<n-1; i++)
    {
        min_element = arr[i];
        min_index = i;
        for(j=i+1; j<n; j++)
        {
            /*
                Here(line 45) instead of min_element we could have used arr[i] directly
                But using a variable is more efficient as otherwise, the array had to be accessed for every iteration in the loop
                The complexity of accessing an array in loop is more than just using an element
            */
            if(min_element>arr[j])
            {
                min_element = arr[j];
                min_index = j;
            }
        }
        arr[min_index] = arr[i];
        arr[i] = min_element;
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
    Though Selection Sort seems very basic, it is used widely when dealing with bigger numbers
    Other algorithms involve more swapping or shifting which is costly for bigger numbers
    Hence Selection Sort is used in those cases
*/