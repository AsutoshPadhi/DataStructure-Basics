/*
    Heap Sort

    A heap is a tree in which the nodes have elements which are always greater than their children(Max Heap), or less than them(Min Heap)
    Heap Sort Algorithm is divided into 2 parts:
        1. Heapify - Which will make sure that parent is always greater than child(Max Heapify) or vice versa
                   - After Heapify, the max/min element will be the root element
        2. Sorting - Since we have the max/min element, we take it out and place it
                   - This is repeatedly done to sort all the elements

*/

#include<stdio.h>

void MaxHeapify(int[], int);
void HeapSort(int[], int);
void Heapify(int[], int);
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

    MaxHeapify(arr, n);
    HeapSort(arr,n);
    display(arr, n);
    
}

void MaxHeapify(int arr[], int n)
{
    int i, j, parent, current, temp, k;
    for(int i=1; i<n; i++)
    {
        current = arr[i];
        parent = i;
        j = i;
        while(parent!=0)
        {
            parent = (j-1)/2;
            if(current>arr[parent])
            {
                arr[j] = arr[parent];
                arr[parent] = current;
            }
            j = (j-1)/2;
        }
    }
}

void HeapSort(int arr[], int n)
{
    int i, j, temp;
    for(i=n-1; i>=0; i--)
    {
        // Swap the root with last element
        temp = arr[0];
        arr[0] = arr[i];
        arr[i] = temp;

        Heapify(arr, i);
    }
}

void Heapify(int arr[], int n)
{
    int i, j, max, temp;
    for(i=0; i<n && (2*i+1)<n;)
    {
        if((2*i)+2 < n)
            max = arr[(2*i)+1]>arr[(2*i)+2]?((2*i)+1):((2*i)+2);
        else
            max = (2*i+1);
        if(arr[i]<arr[max])
        {
            temp = arr[i];
            arr[i] = arr[max];
            arr[max] = temp;
        }
        else
            return;
        i = max;
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
    Complexity:
        Heap Sort has one of the best sorting complexities - O(nlog n)
        In order to place an element properly in the heap, it takes log(n) time as the element has to be checked only with its parent
        And this is done for n elements, complexity = O(n log(n))
*/
