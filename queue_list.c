#include<stdio.h>
struct queue{
int data;
struct queue *next;
}*front=NULL,*rear=NULL;
void enqueue()
{
struct queue *newnode;
newnode=malloc(sizeof(struct queue));
printf("enter the element:");
scanf("%d",&(newnode->data));
if(front==NULL)
{
    newnode->next=NULL;
    front=newnode;
    rear=newnode;

}
else
{
newnode->next=rear->next;
rear->next=newnode;
rear=newnode;
}
}
void dequeue()
{
if(front==NULL)
    printf("QUEUE UNDERFLOW");
else
{
struct queue *temp;
temp=front;
if(front==rear)
{
free(front);
front=NULL;
rear=NULL;
}
else
{
front=temp->next;
free(temp);
}
}
}
void display(struct queue *p)
{
while(p!=NULL)
{
printf("%d ",p->data);
p=p->next;
}
}
int main()
{
int c=1,n;
while(c)
{
printf("\nenter:\n1.enqueue\n2.dequeue\n3.exit\n");
scanf("%d",&n);
switch(n)
{
case 1:
enqueue();
printf("\nthe elements:");
display(front);
break;
case 2:
dequeue();
printf("\nthe elements:");
display(front);
break;
case 3:
c=0;
break;
}
}
}
