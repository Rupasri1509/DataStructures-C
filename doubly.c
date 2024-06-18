#include<stdio.h>
struct node{
int data;
struct node *next;
struct node *prev;
};
void print(struct node *p)
{
int q=p;
do
{
printf("%d",p->data);
p=p->prev;
}while(p!=q);
}
int main()
{
int n;
int head=NULL;
printf("enter no.of.nodes:");
scanf("%d",&n);
struct node *a[n];
for(int i=0;i<n;i++)
{
a[i]=malloc(sizeof(struct node ));
printf("\nenter the value:");
scanf("%d",&(a[i]->data));
if(head==NULL)
{
a[i]->next=a[i];
head=a[i];
}
else
{
a[i]->prev=a[i-1];
a[i]->next=a[i-1]->next;
a[i-1]->next=a[i];
}
}
a[0]->prev=a[n];
printf("before reverse:");
print(head);
}

