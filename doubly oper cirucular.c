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
    int choice=1;
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
void display(struct node*p)
{
    int q=p;
    do
    {
        printf("%d ",p->data);
        p=p->next;
    }while(p!=q);
}
void insertbeg()
{
    struct node*newnode;
    newnode=malloc(sizeof(struct node));
    printf("\nenter the data:");
    scanf("%d",&(newnode->data));
    if(head==0)
    {
        head=tail=newnode;
        newnode->next=head;
        newnode->prev=head;
    }
    else
    {
       newnode->next=head;
       head->prev=newnode;
       newnode->prev=tail;
       tail->next=newnode;
       head=newnode;
    }
}
void insertend()
{
    struct node*newnode;
    newnode=malloc(sizeof(struct node));
    printf("\nenter the data:");
    scanf("%d",&(newnode->data));
    if(head==0)
    {
        head=tail=newnode;
        newnode->next=head;
        newnode->prev=head;
    }
    else
    {
        newnode->next=tail->next;
        tail->next=newnode;
        newnode->prev=tail;
        head->prev=newnode;
        tail=newnode;
    }
}
void insertmid()
{
    struct node*newnode,*temp;
    int p,i=1;
    temp=head;
    printf("\nENTER THE POSITION:");
    scanf("%d",&p);
    if(p==1)
    {
        insertbeg();
    }
    else
    {
        newnode=malloc(sizeof(struct node));
        printf("\nenter the data:");
        scanf("%d",&(newnode->data));
        while(i<p-1)
        {
            temp=temp->next;
            i++;
        }
        newnode->prev=temp;
        newnode->next=temp->next;
        tail->prev=newnode;
        temp->next=newnode;
    }

}
void deletebeg()
{
    struct node*temp;
    struct node *t2;
    t2=tail;
    temp=head;
    if(head==0)
    {
        printf("no node");
    }
    else if(head->next==head)
    {
        head=tail=0;
    }
    else
    {
        temp=head->next;
        temp->prev=t2;
        t2->next=head;
        free(temp);
        free(t2);
    }
}
void deleteend()
{
    struct node*temp;
    struct node *t2;
    temp=tail;
    t2=head;
    if(head==0)
    {
        printf("no node");
    }
    else
    {
        temp=tail->prev;
        temp->next=t2;
        t2->prev=temp;
        free(temp);
        free(t2);
         printf("%d %d\n",head->data,tail->data);
    }

}
void deletemid()
{
    struct node*temp;
    int p,i=1;
    temp=head;
    printf("\n ENTER THE POSITION:");
    scanf("%d",&p);
    if(p==1)
    {
        deletebeg();
    }
    else
    {
        while(i<p)
        {
            temp=temp->next;
            i++;
        }
        temp->prev->next=temp->next;
        temp->next->prev=temp->next;
        if(temp->next==head)
        {
            tail=temp->prev;
            free(temp);
        }
        else
        {
            free(temp);
        }
    }
}
int main()
{
    create();
    printf("\nTHE ORIGINAL LIST:");
    display(head);
    insertbeg();
    printf("\nINSERTION AT BEGINNING:");
    display(head);
    insertend();
    printf("\n INSERTION AT END:");
    display(head);
    insertmid();
    printf("\n INSERTION AT MIDDLE:");
    display(head);
    deletebeg();
    printf("\n AFTER DELETING AT BEG:");
    display(head);
    deletemid();
    printf("\n AFTER DELETING AT END:");
    display(head);
    deleteend();
    printf("\n AFTER DELETING AT MID:");
    display(head);


}
