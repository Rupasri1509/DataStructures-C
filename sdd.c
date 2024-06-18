#include<stdio.h>
struct node{
int data;
struct node *prev;
struct node *next;
};
int  display(struct node *p)
{
int q=p;
do
{
printf("%d ",(p->data));
p=p->next;
}while(p!=q);
}
int create(int n)
{

int head=NULL;

struct node *a[n];
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
int sort(struct node *head1,struct node *head2)
{
    struct node *temp,*temp1;
    int p;
    temp=head1;

    while(temp->next!=head1)
    {
        temp1=temp->next;
        while(temp1!=head1){
        if(temp->data > temp1->data)
        {
            p=temp->data;
            temp->data=temp1->data;
            temp1->data=p;
        }
        temp1=temp1->next;
    }
    temp=temp->next;
}


return head1;
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
temp=head1;
while(temp->next!=head1)
{
temp=temp->next;
}
temp->next=head2;
head2->prev=temp;

struct node *temp1;
temp1=head2;
while(temp1->next!=head2)
{
temp1=temp1->next;
}
head1->prev=temp1;
temp1->next=head1;

printf("\n");
display(head1);
sort(head1,head2);
printf("\n");
display(head1);
printf("\n\n");



temp=head1;
int c;
 do
    {
        temp1=temp;
         c=0;
       do{
        if(temp->data == temp1->data)
        {
           c++;
        }
       // if(c==1)
           // printf("%d ",temp->data);
        temp1=temp1->next;
        }while(temp1!=head1);
        if(c==1)
            printf("%d ",temp->data);
        temp=temp->next;
}while(temp!=head1);
}
