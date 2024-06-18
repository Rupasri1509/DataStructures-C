#include<stdio.h>
struct node{
int data;
struct node *next,*prev;
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
    int n;
    printf("Enter the number of nodes:");
    scanf("%d",&n);
    struct node *a[n];
    int head=NULL;
    for(int i=0;i<n;i++)
    {
        printf("Enter the value:");
        a[i]=malloc(sizeof(struct node));
        scanf("%d",&a[i]->data);
        if(head==NULL)
        {
            a[i]->prev=NULL;
            a[i]->next=NULL;
            head=a[i];
        }
        else
        {
            a[i]->next=a[i-1]->next;
            a[i]->prev=a[i-1];
            a[i-1]->next=a[i];
        }
    }
    print(head);
    int p;
    printf("\nenter the position:");
    scanf("%d",&p);
    struct node *newb;
    newb=malloc(sizeof(struct node));
    printf("\nenter data:");
    scanf("%d",&(newb->data));
    for(int i=0;i<n+1;i++)
    {
    if(i==(p-1))
    {
    if(i==0)
    {
    newb->next=head;
    newb->prev=NULL;
    a[i]->prev=newb;
    newb=head;
    }
    else
    {
    newb->next=a[i-1]->next;
    newb->prev=a[i-1];
    a[i-1]->next=a[i];
    }
    }
    }
    print(head);
    for(int i=0;i<n;i++)
    {
    if(i==0)
        head=a[i];
    else
        a[i]=a[i-1]->next;
    }

    print(head);
}









