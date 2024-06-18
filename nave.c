#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node*next;
    struct node*prev;
}*head,*tail;
void create()
{
    struct node*newnode;
    int choice;
    while(choice)
    {
        newnode=malloc(sizeof(struct node));
        printf("enter the data:");
        scanf("%d",&(newnode->data));

        if(head==0)
        {
            head=tail=newnode;
            head->next=head;
            head->prev=head;
        }
        else
        {
            tail->next=newnode;
            newnode->prev=tail;
            newnode->next=head;
            head->prev=newnode;
            tail=newnode;
        }
        printf("\nENTER THE CHOICE:");
        scanf("%d",&choice);
    }
}
int main()
{
    create();
}
