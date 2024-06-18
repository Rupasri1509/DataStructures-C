#include<stdio.h>
struct node{
int data;
struct node *prev;
struct node *next;
};
void print(struct node *p)
{
while(p!=NULL)
{
printf("%d",p->data);
p=p->next;
}
}
int main()
{
int n,b=0;
int head=NULL;
printf("ENTER THE NODES:");
scanf("%d",&n);
b=n;
struct node *a[n];
for(int i=0;i<n;i++)
{
a[i]=malloc(sizeof(struct node ));
printf("ENTER THE VALUE:");
scanf("%d",&(a[i]->data));
if(head==NULL)
{
a[i]->next=NULL;
a[i]->prev=NULL;
head=a[i];
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
for(int i=0;i<3;i++)
{
printf("\nENTER THE POSITION:");
scanf("%d",&p);
struct node *newb;
newb=malloc(sizeof(struct node));
printf("\nENTER THE DATA:");
scanf("%d",&(newb->data));
for(int i=0;i<100;i++)
{
if(i==(p-1))
{
if(i==0)
{
    b++;
    newb->next=head;
    newb->prev=NULL;
    head=newb;
    break;
}
else
{
    b++;
    newb->next=a[i-1]->next;
    newb->prev=a[i-1];
    a[i-1]->next=newb;
    break;
}
}
}
for(int i=0;i<b;i++)
{
if(i==0)
    a[i]=head;
else
    a[i]=a[i-1]->next;
}
for(int i=0;i<b;i++)
{
if(i==0)
{
a[i]->next=NULL;
a[i]->prev=NULL;
head=a[i];
}
else
{
a[i]->next=a[i-1]->next;
a[i]->prev=a[i-1];
a[i-1]->next=a[i];
}
}
printf("\nAFTER INSERTING:");
for(int i=0;i<=b;i++)
{
printf("\n%d %d %d %d\n",a[i]->data,a[i]->prev,a[i],a[i]->next);
}
}
}

