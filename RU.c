#include<stdio.h>
struct node{
int data;
struct node *next,*prev;
};
void delbig(struct node *p,struct node *q)
{
    p->next=q;
    q->prev=p;
}
void delmid(struct node *p,struct node *q)
{
    p->next=q;
    q->prev=p;
}
void delend(struct node *p,struct node *q)
{
    p->next=q;
    q->prev=p;
}
void print(struct node *p)
{
    int x=p;
    do
    {
        printf("%d",p->data);
        p=p->next;
    }while(p!=x);
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
    int o;
    printf("Enter (1) for deletion at the beginning \n Enter (2) for deletion at the middle\n Enter (3) for deletion at end\n");
    scanf("%d",&o);
    switch(o)
    {
        case 1:
            delbig(a[n-1],a[1]);
            print(a[1]);
            break;
        case 2:
            printf("Enter the position to be deleted:");
            int x;
            scanf("%d",&x);
            delmid(a[x-2],a[x]);
            print(a[0]);
            break;
        case 3:
            delend(a[n-2],a[0]);
            print(a[0]);
    }

}
