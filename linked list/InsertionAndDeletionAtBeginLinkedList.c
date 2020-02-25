#include<stdio.h>

struct node
{
    int data;
    struct node *next;
}

*head;

void print()
{
    struct node*temp=head;
    while (temp!=NULL)
    {
        printf("%d\n",temp->data);
        temp=temp->next;
    }
}

void InsertAtBegin(int data)
{
    struct node* A=(struct node*) malloc(sizeof(struct node));
    A->data=data;
    A->next=NULL;
    if (head==NULL)
    head=A;
    else
    {
        A->next=head;
        head=A;
    }    
}

void DeleteAtBegin()
{
    struct node *temp=head;
    head=temp->next;
    free(temp);
}


void main()
{
    head=NULL;
    InsertAtBegin(20);
    InsertAtBegin(30);
    print();
    DeleteAtBegin();
    print();
}
