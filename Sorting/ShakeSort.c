/*
    Shake Sort
    This algorithm is an improvisation over Bubble Sort

    Algorithm:
    1. For i=0 & (i<n && flag == 1)
    2. Flag = 0
    3. For j=i & j<n-i-1
    4. Swap the jth and (j+1)th element if the latter is smaller than the former
    5. If any swapping has been done then set flag = 1
    6. Run a second loop from n-i-2 to i (k loop)
    7. Swap the kth and the (k-1)th element if the former is smaller than the latter
    8. If any swapping has been done then set flag = 1    

    In other words, for every outer i loop
        the j loop will bring the largest element towards the end of the array
        and
        the k loop will bring the smallest element towards the front of the array
*/

#include<stdio.h>

void ShakeSort(int[], int);
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

    ShakeSort(arr, n);
    display(arr, n);
    
}

void ShakeSort(int arr[], int n)
{
    int flag = 1, i, j, k, temp;
    for(i=0; i<n && flag==1; i++)
    {
        flag = 0;
        
        for(j=0; j<n-i-1; j++)
        {
            if(arr[j]>arr[j+1])
            {
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
                flag = 1;
            }
        }

        for(k=n-i-2; k>i; k--)
        {
            if(arr[k]<arr[k-1])
            {
                temp = arr[k];
                arr[k] = arr[k-1];
                arr[k-1] = temp;
                flag = 1;
            }
        }
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