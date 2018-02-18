/*
    Sorted Linked List using 2 pointers

    This program is used for insertion in a Sorted Linked List using 2 pointers:
        1. curr - points to the current node
        2. prev - points to the node previous to curr
*/

#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>

void insertNode(int);
void display();

struct node
{
    int data;
    struct node *next;
};
struct node *head;

void main()
{
    int ch;
    do
    {
        printf("\n*************MENU*************\n");
        printf("\n1. Add a Node");
        printf("\n2. Display the Linked List");
        printf("\n3. Exit");
        printf("\nEnter your choice : ");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:
            {
                // Insert a node in the Linked List in a sorted manner

                int data;
                fflush(stdin);
                printf("\nEnter a number : ");
                scanf("%d",&data);
                
                insertNode(data);

                break;
            }

            case 2:
            {
                // Display the Linked List
                display();
                break;
            }

            case 3:
            {
                exit(0);
            }

            default:
            {
                printf("\nEnter valid choice");
            }
        }
    }while(1);
}

void insertNode(int data)
{
    struct node *prev = NULL, *curr = head;

    // Create a new Node
    struct node *n = (struct node*)malloc(sizeof(struct node));
    n->data = data;

    // If the current data is the first element to be inserted
    if(head == NULL)
    {
        head = n;
        n->next = NULL;
        return;
    }
    
    // Traverse the Linked List till it reaches the node's required position
    while(curr!=NULL && curr->data<data)
    {
        prev = curr;
        curr = curr->next;
    }

    // If the new data is smaller than head
    if(prev == NULL)
    {
        prev = n;
        head = prev;
    }

    // Connecting the new node to the Linked List
    prev->next = n;
    n->next = curr;

    return;
}

void display()
{
    struct node *ptr = head;
    printf("\n---------------------------\n");
    while(ptr->next != NULL)
    {
        printf("%d -> ",ptr->data);
        ptr = ptr->next;
    }
    printf("%d",ptr->data);
    printf("\n---------------------------\n");

    return;
}