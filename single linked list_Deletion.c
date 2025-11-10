#include<stdio.h>
#include<stdlib.h>
struct Node
{
    int data;
    struct Node *next;
};
struct Node *head=NULL;
struct Node *createNode (int data)
{
    struct Node *newNode=(struct Node*)malloc(sizeof(struct Node));
    if(!newNode)
    {
        printf("Memory Overflow!\n");
        exit(0);
    }
    newNode->data=data;
    newNode->next=NULL;
    return newNode;
};
void insertEnd(int data)
{
    struct Node *newNode=createNode(data);
    if(head==NULL)
    {
        head=newNode;
        return;
    }
    struct Node *temp=head;
    while(temp->next!=NULL)
        temp=temp->next;
    temp->next=newNode;
}
void deleteBeginning()
{
    if(head==NULL)
    {
        printf("List is empty!\n");
        return;
    }
    struct Node *temp=head;
    head=head->next;
    free(temp);
    printf("Node deleted at begin\n");
}
void deleteEnd()
{
    if(head==NULL)
    {
        printf("List is empty!\n");
        return;
    }
    if(head->next==NULL)
    {
        free(head);
        head=NULL;
        printf("Node deleted from end\n");
        return;
    }
    struct Node *temp=head,*prev=NULL;
    while(temp->next!=NULL)
    {
        prev=temp;
        temp=temp->next;
    }
    prev->next=NULL;
    free(temp);
    printf("Node deleted from end\n");
}
void deleteBeforePos(int pos)
{
    if(head==NULL || pos<=1)
    {
        printf("Cannot delete before position %d\n ",pos);
        return;
    }
    if(pos==2)
    {
        deleteBeginning();
        return;
    }
    struct Node *temp=head;
    for(int i=1;i<pos-2 && temp->next!=NULL;i++)
        temp=temp->next;
    if(temp->next==NULL || temp->next->next==NULL)
    {
        printf("Invalid position!\n");
        return;
    }
    struct Node *del=temp->next;
    temp->next=del->next;
    free(del);
    printf("Node deleted before position %d\n",pos);
}
void deleteAfterPosition(int pos)
{
    if(head==NULL)
    {
        printf("List is empty!\n");
        return;
    }
    struct Node *temp=head;
    for(int i=1;i<pos&&temp!=NULL;i++)
        temp=temp->next;
    if(temp==NULL || temp->next==NULL)
    {
        printf("Invalid position!\n");
        return;
    }
    struct Node *del=temp->next;
    temp->next=del->next;
    free(del);
    printf("Node deleted after position %d\n",pos);
}
void display()
{
    if(head==NULL)
    {
        printf("List is empty!\n");
        return;
    }
    struct Node *temp=head;
    printf("List: ");
    while(temp!=NULL)
    {
        printf("%d->",temp->data);
        temp=temp->next;
    }
    printf("NULL\n");
}
int main()
{
    int choice,data,pos;
    while(1)
    {
        printf("\n--Menu--\n");
        printf("1.Insert at End\n2.Delete at Beginning\n3.Delete at End\n4.Delete Before Position\n");
        printf("5.Delete After Position\n6.Display\n7.Exit\nEnter your choice: ");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:
                printf("Enter data: ");
                scanf("%d",&data);
                insertEnd(data);
                break;
            case 2:
                deleteBeginning();break;
            case 3:
                deleteEnd();break;
            case 4:
                printf("Enter position: ");
                scanf("%d",&pos);
                deleteBeforePos(pos);break;
            case 5:
                printf("Enter position: ");
                scanf("%d",&pos);
                deleteAfterPosition(pos);break;
            case 6:
                display();break;
            case 7:
                exit(0);
            default:
                printf("Invalid choice!\n");
        }
    }
    return 0;
}
