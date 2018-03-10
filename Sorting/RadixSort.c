/*
    Radix Sort
    
    Algorithm:
    1. Find the biggest number in the array
    2. Find the number of digits in the max number, say max_digit
    3. Create 10 buckets (one for each digit(0-9))
    4. Put the numbers in buckets according to their digits(from right to left)
    5. After each iteration, take out the elements from the buckets into the array
    6. Repeat step 4 and 5 for max_digit times
*/


#include <stdio.h>
#include <malloc.h>

int base = 10;

/*Create a array of Linked List*/
struct node
{
    int data;
    struct node* next;
};
struct node* head[10];
struct node* rear[10];

int findNumOfDigits(int, int);

void main()
{
    int n, i;
    printf("\nEnter the number of elements : ");
    scanf("%d",&n);
    int arr[n], max=0, max_digits;
    printf("\nEnter the elements : \n");
    for(i=0; i<n; i++)
    {
        scanf("%d",&arr[i]);
        if(arr[i]>max)
            max = arr[i];
    }

    max_digits = findNumOfDigits(max,0);
    
    int r = 1, index, j, k;
    for(i=0; i<max_digits; i++)
    {
        r = r*base;
        
        for(j=0; j<n; j++)
        {
            index = (arr[j]%r)/(r/base);
            struct node *n = (struct node*)malloc(sizeof(struct node));
            n->data = arr[j];
            n->next = NULL;
            
            /*Put the elements into the buckets - Linked List*/
            if(head[index] == NULL)
            {
                head[index] = n;
                rear[index] = n;
            }
            else
            {
                rear[index]->next = n;
            }
        }

        for(j=0; j<base; j++)
        {
            struct node* ptr = head[j];
            printf("\n Bucket : %d",j);
            while(ptr!=NULL)
            {
                printf("\t%d",ptr->data);
                ptr = ptr->next;
            }
        }

        /*Read elements from the bucket serially and write it into the array*/
        k = 0;
        for(j=0; j<base; j++)
        {
            struct node* ptr = head[j];
            while(ptr != NULL)
            {
                arr[k] = ptr->data;
                ptr = ptr->next;
                k++;
            }
        }
        printf("\nAfter pass %d ",i);
        for(j=0; j<n; j++)
            printf(" %d",arr[j]);
        printf("\n\n");

        for(j=0; j<base; j++)
            head[j] = NULL;
    }
}

int findNumOfDigits(int n, int cnt)
{
    if(n == 0)
        return cnt;
    else
        findNumOfDigits(n/base, cnt+1);
}