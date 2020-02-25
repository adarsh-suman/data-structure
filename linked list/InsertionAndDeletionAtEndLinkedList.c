#include<stdio.h>

struct node
{
    int data;
    struct node *next;
}

*head;

void print()
{
    if(head==NULL) 
    {
        printf("no element");
        return;
    }
    struct node*temp=head;
    while (temp!=NULL)
    {
        printf("%d\n",temp->data);
        temp=temp->next;
    }
}

void InsertAtEnd(int data)
{
    struct node* A=(struct node*) malloc(sizeof(struct node));
    A->data=data;
    A->next=NULL;
    struct node *temp=head;
    if (temp==NULL)
    {
        head=A;
        return;
    }
    while (temp->next!=NULL)
    {
        temp=temp->next;
    } 
    temp->next=A;
}

void DeleteAtEnd()
{
    struct node *temp=head;
    
    if(head == NULL)
        return;
    struct node *B;
    while(temp->next!=NULL && temp->next->next!=NULL)
        temp=temp->next;
    
    if(temp->next == NULL)
    {    
        free(head);
        head=NULL;
        return;
    }
    B=temp->next;
    temp->next=NULL;
    free(B);
    
}


void main()
{
    head=NULL;
    InsertAtEnd(20);
    InsertAtEnd(30);
    print();
    DeleteAtEnd();
    print();
}
