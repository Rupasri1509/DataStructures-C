#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *next;
}*top=NULL,*top1=NULL;
struct queue
{
    int data1;
    struct queue *next1;
}*front=-1,*front1=-1,*rear=-1,*rear1=-1;
int main()
{
int n;
printf("ENTER THE ELEMENTS:");
scanf("%d",&n);
for(int i=0;i<n;i++)
{
    struct queue *newq;
    newq=malloc(sizeof(struct queue));
    printf("ENTER THE DATA:");
    scanf("%d",&(newq->data1));
    if(front==-1)
    {
        front=rear=newq;
        newq->next1=NULL;
    }
    else
    {
        newq->next1=rear->next1;
        rear->next1=newq;
        rear=newq;
    }
}
while(front!=NULL)
{
    struct node *newnode;
    newnode=malloc(sizeof(struct node));
    if(top==NULL)
    {
        //printf("d");
        newnode->data=front->data1;
        newnode->next=NULL;
        top=newnode;
        //printf("%d",top->data);
    }
    else if((front->data1)<(top->data))
    {
        newnode->data=front->data1;
        newnode->next=top;
        top=newnode;
    //printf("\n%d",top->data);
    }
    else if((front->data1)>(top->data))
    {
            do
            {
                //printf("t:%d\n",top->data);
                if((front->data1)<(top->data))
                {
                    //printf("t:%d\n",top->data);
                    break;
                }
                else
                {
                //printf("t:%d\n",top->data);
                int f;
                struct node *newnode1;
                newnode1=malloc(sizeof(struct node));
                if(top1==NULL)
                {
                newnode1->data=top->data;
                newnode1->next=NULL;
                top1=newnode1;
                }
                else
                {
                /*if(top1==NULL)
                {
                newnode1->data=top->data;
                newnode1->next=NULL;
                top1=newnode1;
                }
                else
                {*/
                if((top->data)>(top1->data))
                {
                newnode1->data=top->data;
                newnode1->next=top1;
                top1=newnode1;
                }
                else
                {
                f=top1->data;
                top1->data=top->data;
                newnode1->data=f;
                newnode1->next=top1;
                top1=newnode1;
                }
                }
                }
                //printf("%d\n",top1->data);
                        top=top->next;
            }while(top!=NULL);
            struct node *newnode;
            newnode=malloc(sizeof(struct node ));
            newnode->data=front->data1;
            if(top==NULL)
            {
            newnode->next=NULL;
            top=newnode;
            }
            else
            {
            newnode->next=top;
            top=newnode;
            }
            }
            front=front->next1;
}
while(top!=NULL)
{
    int g;
    struct node *newnode1;
    newnode1=malloc(sizeof(struct node));
    if(top1==NULL)
    {
        newnode1->data=top->data;
        newnode1->next=NULL;
        top1=newnode1;
    }
    else
    {
        struct node *temp;
        temp=top;
        do
        {
        printf("d");
        if((top->data)>(top1->data))
        {
            newnode1->data=top->data;
            newnode1->next=top1;
            top1=newnode1;
        }
        else
        {
            g=top1->data;
            top1->data=top->data;
            newnode1->data=g;
            newnode1->next=top1;
            top1=newnode1;
        }
        top-top->next;
    }while(top!=NULL);
    top=temp;
}
top=top->next;
}
do
{
    printf("%d\n",top1->data);
    top1=top1->next;
}while(top1!=NULL);
}
