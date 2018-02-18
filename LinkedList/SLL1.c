/*
    Sorted Linked List with 1 pointer

    This program is used for insertion in a Sorted Linked List using 1 pointer:
        1. curr - points to the current node
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
struct node *head = NULL;

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
                // Insert a node to the Linked List in a sorted manner

                int data;
                printf("\nEnter a number : ");
                scanf("%d",&data);
                
                insertNode(data);

                break;
            }

            case 2:
            {
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
    struct node *curr = head;

    // Create a new node
    struct node *n = (struct node*)malloc(sizeof(struct node));
    n->data = data;

    // For the first element to be inserted to the Linked List
    if(head == NULL)
    {
        head = n;
        n->next = NULL;
        return;
    }

    curr = head;

    // If the new data is smaller than the first element of the linked list
    if(curr->data > n->data)
    {
        n->next = curr;
        head = n;
        return;
    }

    // Traverse the Linked List till it reaches the node's required position
    while(curr->next != NULL && curr->next->data < n->data)
    {
        curr = curr->next;
    }

    // Connecting the new node to the Linked List
    n->next = curr->next;
    curr->next = n;

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