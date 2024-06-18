#include<stdio.h>
struct node{
int data;
struct node *next;
};
int front1,rear1;
int front=-1,rear=-1,top=-1;
int front2=-1,rear2=-1;
struct node *a[20];
struct node *b[20];
struct node *c[20];
int n;
int i,x=0;
void enquene()
{
    if(front==-1)
    {
       front=front+1;
       rear=rear+1;
       i=0;
       a[i]=malloc(sizeof(struct node));
       printf("Enter the value:");
       scanf("%d",&a[i]->data);
       a[i]->next=a[i];
       front1=a[i];
       rear1=a[i];
    }
    else if(rear<(n-1))
    {
       rear=rear+1;
       i=i+1;
       a[i]=malloc(sizeof(struct node));
       printf("Enter the value:");
       scanf("%d",&a[i]->data);
       rear1=a[i];
       a[i]->next=a[i-1]->next;
       a[i-1]->next=a[i];
    }
    else if(rear>=n-1)
    {
        printf("QUENE OVERFLOW\n");
    }
}
void dequene()
{
    if(front==-1)
    {
        printf("QUENE UNDERFLOW");
    }
    else if(front<(n-1))
    {
        front1=a[x+1];
        x=x+1;
        front=front+1;
        display2(front1,rear1);
    }
    else if(front==rear)
    {
        front=-1;
        rear=-1;
        printf("QUENE UNDERFLOW");
    }
}
void sort()
{
    for (int i=0;i<n;i++)
    {
        int t;
        for(int j=0;j<n;j++)
        {
            if(a[i]->data>=a[j]->data)
            {
                t=a[i]->data;
                a[i]->data=a[j]->data;
                a[j]->data=t;
            }
        }
    }
    for(int x=0;x<n;x++)
    {
        top=top+1;
        c[top]=malloc(sizeof(struct node));
        c[top]->data=a[x]->data;
        printf("%d",c[top]->data);
    }
}
void enquene1()
{
    if(front2==-1)
    {
       front2=front2+1;
       rear2=rear2+1;
       i=0;
       b[i]=malloc(sizeof(struct node));
       b[i]->data=a[top]->data;
       b[i]->next=b[i];
       front1=b[i];
       rear1=b[i];
       top=top-1;
       display1(front1);
    }
    else if(rear2<(n-1))
    {
       rear2=rear2+1;
       i=i+1;
       b[i]=malloc(sizeof(struct node));
       b[i]->data=a[top]->data;
       b[i]->next=b[i-1]->next;
       b[i-1]->next=b[i];
       rear1=b[i];
       top=top-1;
       display1(front1);
    }
    else if(rear2>=n-1)
    {
        printf("QUENE OVERFLOW\n");
    }
}
void dequene1()
{
    if(front2==-1)
    {
        printf("QUENE UNDERFLOW\n");
    }
    else if(front2<(n-1))
    {
        front1=b[x+1];
        x=x+1;
        front2=front2+1;
        display2(front1,rear1);
    }
    else if(front2==rear2)
    {
        front2=-1;
        rear2=-1;
        printf("QUENE UNDERFLOW\n");
    }
}
void display1(struct node *p)
{
    int q=p;
    do
    {
        printf("%d\n",p->data);
        p=p->next;
    }while(p!=q);
}
void display2(struct node *p,struct node *q)
{
    while(p!=q)
    {
        printf("%d\n",p->data);
        p=p->next;
    }
    printf("%d\n",q->data);
}
int main()
{
    printf("Enter the number of elements:");
    scanf("%d",&n);
    int o;
    int c=1;
    while(1)
    {
        printf("Enter (1) to Enquene\nEnter (2) to Dequene\nEnter (3) to Sort\nEnter (4) to Enquene1\nEnter (5) to Dequenq1\n");
        printf("Enter the choice: ");
        scanf("%d",&o);
        switch(o)
        {
        case 1:
            enquene();
            display1(front1);
            break;
        case 2:
            dequene();
            break;
        case 3:
            sort();
            printf("\nSorted\n");
            break;
        case 4:
            enquene1();
            break;
        case 5:
            dequene1();
            break;
        }
    }

}
