#include<stdio.h>
#include<stdlib.h>
struct node {
int data,link;
};
int head;
void insbeg(struct node *p)
{
struct node *newb;
newb=malloc(sizeof(struct node ));
newb->data=4;
newb->link=p->link;
p->link=newb;
printf("the list after inserting at beginning:");
print(head);
}
void insmid(struct node *mid,int a)
{
int n=1;
while(mid!=NULL)
{
if(n==a)
{
struct node *newm;
newm=malloc(sizeof(struct node ));
newm->data=5;
newm->link=mid->link;
mid->link=newm;
printf("\nthe list after inserting at middle:");
print(head);
break;
}
n++;
mid=mid->link;
}
}
void insend(struct node *p)
{
struct node *newe;
newe=malloc(sizeof(struct node ));
newe->data=6;
newe->link=p->link;
p->link=newe;
printf("\nthe list after inserting at end:");
print(head);
}
void print(struct node *p)
{
int q=p;
while(1)
{
if(p->link==q)
{
printf("%d",p->data);
p=p->link;
break;
}
else
{
printf("%d",p->data);
p=p->link;
}
}
}
int main()
{
struct node *one;
struct node *two;
struct node *last;
one=malloc(sizeof(struct node));
two=malloc(sizeof(struct node));
last=malloc(sizeof(struct node));
one->data=1;
two->data=2;
last->data=3;
head=one;
one->link=two;
two->link=last;
last->link=head;
insbeg(head);
insmid(head,2);
insend(last);
}
