#include<stdio.h>
struct node
{
    int data;
    struct node *next;
};
int display(struct node *p)
{
    while(p!=NULL)
    {
        printf("%d ",p->data);
        p=p->next;
    }
}
int main()
{
    int n;
    int head=NULL;
    printf("Enter the no of nodes :");
    scanf("%d",&n);
    struct node *a[n];
    for(int i=0;i<n;i++)
    {
        a[i]=malloc(sizeof(struct node));
        printf("Enter data :");
        scanf("%d",&(a[i]->data));
        if(head==NULL)
        {
            a[i]->next=NULL;
            head=a[i];
        }
        else
        {
            a[i]->next=a[i-1]->next;
            a[i-1]->next=a[i];
        }
    }
    display(head);
    for(int i=n-1;i>0;i--)
    {
        a[i-1]->next=a[i]->next;
        a[i]->next=a[i-1];

    }
        head=a[n-1];
    printf(" \n.......\n ");
    display(head);
}
