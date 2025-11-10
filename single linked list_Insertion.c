#include<stdio.h>
#include<stdlib.h>
struct Node
{
    int data;
    struct Node *next;
};
struct Node *head=NULL;
void insertAtBeginning(int value)
{
    struct Node *newNode=(struct Node*) malloc(sizeof(struct Node));
    if (newNode==NULL)
    {
        printf("Memory overflow!\n");
        return;
    }
    newNode->data=value;
    newNode->next=head;
    head=newNode;
}
void insertAtEnd(int value)
{
    struct Node *newNode=(struct Node*) malloc(sizeof(struct Node));
    if (newNode==NULL)
    {
        printf("Memory overflow!\n");
        return;
    }
    if(head==NULL)
    {
        printf("Empty list! Can't insert at end\n");
        return;
    }
    newNode->data=value;
    newNode->next=NULL;
    struct Node *temp=head;
    while(temp->next!=NULL)
    temp=temp->next;
    temp->next=newNode;
}
void insertAtPosition(int value, int position)
{
    struct Node *newNode=(struct Node*) malloc(sizeof(struct Node));
    if (newNode==NULL)
    {
        printf("Memory overflow!\n");
        return;
    }
    newNode->data=value;
    if(position==1)
    {
        newNode->next=head;
        head=newNode;
        return;
    }
    struct Node *temp=head;
    for(int i=1;i<position-1 && temp!=NULL; i++)
    temp=temp->next;
    if(temp==NULL)
    {
        printf("Position out of range\n");
        return;
    }
    newNode->next=temp->next;
    temp->next=newNode;
}
void display()
{
    struct Node *temp=head;
    if(temp==NULL)
    {
        printf("List is empty\n");
        return;
    }
    printf("Linked List:");
    while(temp!=NULL)
    {
        printf("%d->",temp->data);
        temp=temp->next;
    }
    printf("NULL\n");
}
int main()
{
    int ch,val,pos;
    while(1)
    {
        printf("\n1.Insert at Start\n2.Insert at End\n3.Insert at Position\n4.Display\n5.Exit\n");
        printf("Enter choice");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:
                printf("Enter value:");
                scanf("%d",&val);
                insertAtBeginning(val);break;
            case 2:
                printf("Enter value:");
                scanf("%d",&val);
                insertAtEnd(val);break;
            case 3:
                printf("Enter value:");
                scanf("%d",&val);
                printf("Enter position:");
                scanf("%d",&pos);
                insertAtPosition(val,pos);break;
            case 4:
                display();break;
            case 5:
                exit(0);
            default:printf("Invalid choice\n");
        }
    }
    return 0;
}
