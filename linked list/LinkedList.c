#include<stdio.h>
struct node
{
    int data;
    struct node *next;
}
*head;

void print()
{
    struct node* temp = head;
    while(temp!=NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
}

void insertAtBegin(int data)
{
    struct node* A = (struct node*) malloc(sizeof(struct node));
    A->data = data;
    A->next = NULL;
    if(head == NULL)
        head = A;
    else
    {
        A->next = head;
        head = A;
    }
}

void insertAtEnd(int data)
{
    struct node* A = (struct node*) malloc(sizeof(struct node));
    A->data = data;
    A->next = NULL;

    struct node* temp =head;
    if(temp == NULL)
    {
        head = A;
        return;
    }
        
    while(temp->next!=NULL)
    {
        temp = temp->next;
    }
    temp->next = A;
}

void insertonmiddle(int data,int pos)
{
    struct node *temp;
    struct node *A=(struct node*)malloc(sizeof(struct node));
        A->next = NULL;
        A->data = data;
    
    if(pos == 1)
    {  
        if(head == NULL)
            head = A;
        else
        {
            A->next = head;
            head = A;
        }
        return;
    }
    
    int i=1; 
    temp=head;
    
    while (i<pos-1 && temp!=NULL)
    {
        temp=temp->next;
        i++;
    }
    
    if(i<=pos && temp==NULL)
    {
        printf("position doesnt exist\n");
        return;
    }
    else
    {
        A->next=temp->next;
        temp->next=A;
    }
}
void main()
{
    head=NULL;
    print();
    insertonmiddle(10,1);
    print();
    printf("\n");
    insertonmiddle(20,1);
    print();
    printf("\n");
    insertonmiddle(30,1);
    print();
    printf("\n");
    insertonmiddle(40,2);
    print();
    printf("\n");
    insertonmiddle(50,10);
    print();
    printf("\n");
    insertAtBegin(15);
    print();
    printf("\n");
    insertAtEnd(100);
    print();
}
