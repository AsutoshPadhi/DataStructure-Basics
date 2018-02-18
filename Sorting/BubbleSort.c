/*
    Bubble Sort

    Algorithm :
    1. For i=0 & (i<n && flag == 1)
    2. Flag = 0
    3. Swap the ith and (i+1)th element if the latter is smaller than the former
    4. If any swapping has been done then set flag = 1

    Here the flag variable is used to break the for loop if all the elements are sorted before the loop has finished
*/

#include<stdio.h>

void bubbleSort(int[], int);
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

    bubbleSort(arr, n);
    display(arr, n);
    
}

void bubbleSort(int arr[], int n)
{
    int flag = 1, i, j, temp;
    for(i=0; i<n && flag==1; i++)
    {
        flag = 0;
        for(j=0; j<n-i; j++)
        {
            if(arr[j]>arr[j+1])
            {
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
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

/*
    Bubble sort is better than Selection Sort when it comes to time complexity
    This is because there are chances that the loop might break in between - when the array is sorted

    It is also better than other sorting algorithms when the array is partially sorted in some random index

    It is however not as good as Insertion Sort in majority of the cases
    Insertion Sort shifts elements to the right instead of swapping which is more economic

    There is another algorithm known as Shake Sort which is an improvisation over Bubble Sort
    In Bubble Sort, after every pass(outer loop's iteration), we get the biggest number in the array to the end of the array
    Shake Sort is a 2 way Bubble Sort where after every pass, we get the biggest number in the end and the smallest number in the beginning of the array
*/