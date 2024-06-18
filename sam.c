#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node*next;
}*head,*tail;
void create()
{
    struct node*newnode;
    int choice=1;
    while(choice)
    {
        newnode=malloc(sizeof(struct node));
        printf("\nenter the data:");
        scanf("%d",&(newnode->data));


        if(head==0)
        {
            head=tail=newnode;
            head->next=head;
        }
        else
        {
            newnode->next=tail->next;
            tail->next=newnode;
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
        printf("%d",p->data);
        p=p->next;
    }while(p!=q);
}
//recursive function to find length
int  length(struct node *p)
{
struct node*q=p;
int n=0;
do
{
n+=1;
p=p->next;
}while(p!=q);
return n;
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
    }
    else
    {
       newnode->next=head;
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
    }
    else
    {
        newnode->next=tail->next;
        tail->next=newnode;
        tail=newnode;
    }
}
void insertmid()
{
    struct node*newnode,*temp;
    int p,i=1;
    int l=length(head);
    temp=head;
    printf("\nENTER THE POSITION:");
    scanf("%d",&p);
    if(p<1 || p>l )
    {
        printf("inavlid position");
    }
    else if(p==1)
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
        newnode->next=temp->next;
        temp->next=newnode;
    }

}
void deletebeg()
{
    struct node*temp;
    temp=head;
    if(head==0)
    {
        printf("no node");
    }
    else if(head->next==head)
    {
        head=tail=0;
        free(temp);
    }
    else
    {
        head=temp->next;
        tail->next=head;
        free(temp);
    }
}
void deleteend(    struct node*temp)
{
    struct node*current;
    temp=head;
    if(head==0)
    {
        printf("no node");
    }
    else if(head->next==head)
    {
        tail=0;
        free(temp);
    }
    else
    {
        while(temp->next!=tail->next)
        {
            current=temp;
            temp=temp->next;
        }
        current->next=tail->next;
        tail=current;
        free(temp);
    }
}
void deletemid()
{
    struct node*temp,*current;
    int p,i=1;
    int l=length(head);
    temp=head;
    printf("\n ENTER THE POSITION:");
    scanf("%d",&p);
    if(p<1 || p>l)
    {
        printf("\n invalid");
    }
    else if(p==1)
    {
        deletebeg();
    }
    else
    {
        while(i<p-1)
        {
            temp=temp->next;
            i++;
        }
        current=temp->next;
        temp->next=current->next;
        free(current);

    }
}
int main()
{
    printf("\n\n *MAIN MENU *");
    printf("\n 1: Create a list");
    printf("\n 2: Add a node at the beginning");
    printf("\n 3: Add a node in the end");
    printf("\n 4: Add a node at the Middle");
    printf("\n 5: Delete a node at the beginning");
    printf("\n 6: Delete a node in the end");
    printf("\n 7: Delete a node at the Middle");
    printf("\n 8: EXIT");
    int option;
    do
    {
        printf("\n\n Enter your option : ");
        scanf("%d", &option);
        switch(option)
        {
            case 1:create();
                    printf("\nTHE ORIGINAL LIST:");
                    display(head);
                    break;
            case 2: insertbeg();
                   printf("\nINSERTION AT BEGINNING:");
                   display(head);
                   break;
            case 3: insertend();
                    printf("\n INSERTION AT END:");
                    display(head);
                    break;
            case 4: insertmid();
                    printf("\n INSERTION AT MIDDLE:");
                    display(head);
                    break;
            case 5: deletebeg();
                    printf("\n AFTER DELETING AT BEG:");
                    display(head);
                    break;
            case 6:deleteend(tail);
                   printf("\n AFTER DELETING AT END:");
                   display(head);
                   break;
            case 7:deletemid();
                   printf("\n AFTER DELETING AT MID:");
                   display(head);
                   break;

        }
    }while(option!=8);
}
