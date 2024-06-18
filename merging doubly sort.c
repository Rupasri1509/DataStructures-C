#include<stdio.h>
struct node
{
    int data;
    struct node *next ,*prev;
};
int display(struct node *p)
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
    printf("\n");
}
int main()
{
    int n,m;
    int head1=NULL;
    int head2=NULL;
    printf("Enter the number of nodes for 1:");
    scanf("%d",&n);
    printf("Enter the number of nodes for 2 :");
    scanf("%d",&m);
    struct node *b[m];
    struct node *a[n+m];
    for(int i=1;i<=n;i++)
    {
        a[i]=malloc(sizeof(struct node));
        printf("Enter data :");
        scanf("%d",&(a[i]->data));
        if(head1==0)
        {
            a[i]->next=a[i];
            a[i]->prev=a[i];
            head1=a[i];
        }
        else
        {
            a[i]->next=a[1];
            a[i-1]->next=a[i];
            a[i]->prev=a[i-1];
            a[i-1]->prev=a[i];
        }
    }
    printf("Original list values :\n");
    display(head1);
    for(int i=1;i<=m;i++)
    {
        b[i]=malloc(sizeof(struct node));
        printf("Enter data :");
        scanf("%d",&(b[i]->data));
        if(head2==0)
        {
            b[i]->next=b[i];
            b[i]->prev=b[i];
            head2=b[i];
        }
        else
        {
            b[i]->next=b[1];
            b[i-1]->next=b[i];
            b[i]->prev=b[i-1];
            b[i-1]->prev=b[i];
        }
    }
    printf("Original list values :\n");
    display(head2);
    b[m]->next=a[1];
    b[1]->prev=a[n];
    a[1]->prev=b[m];
    a[n]->next=b[1];
    printf("\nafter merging:");
    display(head1);
    for(int i=1;i<=m;i++)
    {
        a[n+i]=b[i];
    }
    int temp;
    for(int i=1;i<=n+m;i++)
    {
        for(int j=i;j<=n+m;j++)
        {
            if (a[i]->data > a[j]->data)
            {
                temp=a[i]->data;
                a[i]->data=a[j]->data;
                a[j]->data=temp;
            }
        }
    }
    printf("\nafter sorting:");
    for(int i=1;i<=m+n;i++)
    {
        int c=0;
        for(int j=i;j<=m+n;j++)
            if(a[i]->data == a[j]->data)
                c++;
        if(c==1)
                printf("%d ",a[i]->data);
    }
}
