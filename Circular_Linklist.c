#include<stdio.h>
#include<stdlib.h>

struct Node
{
    int data;
    struct Node*next;
};

void linklistTraversal(struct Node * head)
{
    struct Node *ptr = head;
    do
    {
        printf("Element is %d\n",ptr->data);
        ptr= ptr->next;
    }
    while (ptr!=head);
}

struct Node *insertAtFirst(struct Node * head,int data)
{
    struct Node * ptr = (struct Node *)malloc(sizeof(struct Node));
    ptr->data = data;
    struct Node * p = head->next ;
}

int main()
{
    struct Node*head;
    struct Node*second;
    struct Node*third;
    struct Node*fourth;

    head =(struct Node*)malloc(sizeof(struct Node));
    second =(struct Node*)malloc(sizeof(struct Node));
    third =(struct Node*)malloc(sizeof(struct Node));
    fourth =(struct Node*)malloc(sizeof(struct Node));

    head->data =4;
    head->next = second;

    second->data =5;
    second->next = third;

    third->data =6;
    third->next = fourth;

    fourth->data =8;
    fourth->next = head;

    printf("Link List after Circular Link List \n");

    linklistTraversal(head);


    return 0;
    
    
}