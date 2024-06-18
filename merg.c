#include<stdio.h>
struct node{
int data;
struct node *prev;
struct node *next;
};
int sort(struct node*p,struct node *r)
{
int q=p,t;
do
{
r=p;
printf("\n%d %d",r,p);
do
{
if((p->data)>(r->data))
{
t=r->data;
p->data=r->data;
r->data=t;
}
printf("\n%d",r);
printf("\n%d",p->data);
r=r->next;
}while(r!=q);
p=p->next;
}while(p!=q);
}
int  display(struct node *p)
{
int q=p;
do
{
printf("%d ",p->data);
p=p->next;
}while(p!=q);
}
int create(int n)
{

int head=NULL;

struct node *a[n+1];
for(int i=1;i<=n;i++)
{
a[i]=malloc(sizeof(struct node ));
printf("ENTER THE VALUE:");
scanf("%d",&(a[i]->data));
if(head==NULL)
{
a[i]->next=a[i];
head=a[i];
}
else
{
a[i]->next=a[i-1]->next;
a[i]->prev=a[i-1];
a[i-1]->next=a[i];
}
}
a[1]->prev=a[n];
return head;
}

int main()
{
int n,m;
struct node*head1,*head2;
printf("ENTER THE NODES 1:");
scanf("%d",&n);
head1=create(n);
printf("ORGINAL LIST1:\n");
display(head1);


printf("\n");
printf("ENTER THE NODES 2:");
scanf("%d",&m);
head2=create(m);
printf("ORGINAL LIST2:\n");
display(head2);
struct node *temp;
int t2=0;
temp=head1;
while(temp->next!=head1)
{
temp=temp->next;
}
temp->next=head2;
head2->prev=temp;
struct node *temp1;
int t3;
temp1=head2;
while(temp1->next!=head2)
{
temp1=temp1->next;
}
temp1->next=head1;
head1->prev=temp1;
printf("\n");
display(head1);
sort(head1,head1);
display(head1);
}

