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
    //int choice=1;
    printf("\nENTER 0 TO STOP");
    do
    {
        newnode=malloc(sizeof(struct node));
        printf("\nenter the data:");
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
        //printf("\nENTER THE CHOICE:");
        //scanf("%d",&choice);
    } while(newnode->data!=0);

}
void display(struct node*p)
{
    while(p!=tail)
    {
        printf("%d",p->data);
        p=p->next;
    }
    printf("%d",tail->data);
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
        newnode->prev=temp;
        newnode->next=temp->next;
        tail->prev=newnode;
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
        head->prev=tail;
        free(temp);
    }
}
void deleteend(struct node*temp)
{
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
        head->prev=temp->prev;
        tail=head->prev;
        tail->next=head;
        free(temp);
    }
}
void deletemid()
{
    struct node*temp;
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
    printf("\n\n *MAIN MENU *");
    printf("\n 1: Create a list");
    printf("\n 2: Add a node at the beginning");
    printf("\n 3: Add a node in the middle");
    printf("\n 4: Add a node at the end");
    printf("\n 5: Delete a node at the beginning");
    printf("\n 6: Delete a node in the middle");
    printf("\n 7: Delete a node at the end");
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
