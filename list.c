#include<stdio.h>
#include<stdlib.h>
struct node {
int data;
struct node *link;
};
struct node *head;

void insbeg(struct node *p)
{
struct node *newb;
newb=malloc(sizeof(struct node ));
newb->data=9;
newb->link=p->link;
p->link=newb;
printf("the list after inserting at beginning:");
print(head);
}
void insmid(struct node *p)
{
struct node *newm;
newm=malloc(sizeof(struct node ));
newm->data=8;
newm->link=p->link;
p->link=newm;
printf("\nthe list after inserting at middle:");
print(head);
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
while(p!=NULL)
{
printf("%d",p->data);
p=p->link;
}
printf("\n");
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
insbeg(head);
insmid(two);
insend(last);
}
