#include<stdio.h>
struct node{
int data;
struct node *prev;
struct node *next;
};
int print(struct node *p)
{
    int head,c=0;
    head=p;
    while(c!=1)
    {
        if(c!=1)
            printf("%d ",p->data);
        p=p->next;
        if(head==p)
            c++;
    }
}
int main()
{
int n;
int head=NULL;
printf("ENTER THE NODES:");
scanf("%d",&n);
struct node *a[n];
for(int i=0;i<n;i++)
{
a[i]=malloc(sizeof(struct node ));
printf("ENTER THE VALUE:");
scanf("%d",&(a[i]->data));
if(head==NULL)
{
a[i]->next=NULL;
a[i]->prev=a[n];
head=a[i];
}
else if(i==(n-1))
{
a[i]->prev=a[i-1];
a[i]->next=a[0];
a[i-1]->next=a[i];
}
else
{
a[i]->next=a[i-1]->next;
a[i]->prev=a[i-1];
a[i-1]->next=a[i];
}
}
printf("ORGINAL LIST:\n");
print(head);
int p;
for(int i=0;i<1;i++)
{
printf("\nENTER THE POSITION:");
scanf("%d",&p);
struct node *newb;
newb=malloc(sizeof(struct node));
printf("\nENTER THE DATA:");
scanf("%d",&(newb->data));
for(int i=0;i<p+1;i++)
{
if(i==(p-1))
{
if(i==0)
{
    newb->next=head;
    newb->prev=a[n];
    head=newb;
}
else
{
    newb->next=a[i-1]->next;
    newb->prev=a[i-1];
    a[i-1]->next=newb;
}
}
}
for(int i=0;i<n+3;i++)
{
if(i==0)
    a[i]=head;
else
    a[i]-a[i-1]->next;
}
printf("\nAFTER INSERTING:");
}
for(int i=0;i<n;i++)
{
printf("%d %d %d %d\n",a[i],a[i]->data,a[i]->prev,a[i]->next);
}
}
