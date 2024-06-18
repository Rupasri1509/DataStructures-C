#include<stdio.h>
#include<stdlib.h>
struct node {
int data,link;
};
struct node *head;
void delbeg(struct node *p)
{
head->link=p->link;
free(p);
}
void delmid(struct node *b,int a,struct node *c)
{
int n=1;
struct node *newm;
newm=malloc(sizeof(struct node));
while(b!=NULL)
{
if(n==a)
{
newm->link=b->link;
free(b);
break;
}
n++;
b=b->link;
}
n=1;
while(c!=NULL)
{
if(n==1)
{
c->link=newm->link;
break;
}
n++;
c=c->link;
}
free(newm);
}
void print(struct node *p)
{
while(p!=NULL)
{
printf("%d",p->data);
p=p->link;
}
}
int main()
{
struct node *one;
struct node *two;
struct node *last;
head=malloc(sizeof(struct node));
one=malloc(sizeof(struct node));
two=malloc(sizeof(struct node));
last=malloc(sizeof(struct node));
one->data=1;
two->data=2;
last->data=3;
head=one;
one->link=two;
two->link=last;
last->link=NULL;
delmid(head,,head);
print(head);
}

