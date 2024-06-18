#include<stdio.h>
int front=-1,rear=-1;
int a[20],n;
void create()
{
    printf("Enter the number of elements:");
    scanf("%d",&n);
}
void enquene()
{
    if(front==-1)
    {
        front+=1;
       rear=rear+1;
       printf("Enter the value:");
       scanf("%d",&a[rear]);
    }
    else if(rear>=n-1)
    {
        printf("QUENE OVERFLOW\n");
    }
    else
    {
        rear=rear+1;
        printf("Enter the value:");
       scanf("%d",&a[rear]);
    }
}
void dequene()
{
    if(front==-1)
    {
        printf("QUENE UNDERFLOW");
    }
    else if(front==rear)
    {
        front=-1;
        rear=-1;
        display();
    }
    else if(front<(n-1))
    {
        front=front+1;
        display();
    }
}
void display()
{
    for(int i=front;i<=rear;i++)
    {
        printf("%d\n",a[i]);
    }
}
int main()
{
    int o;
    int c=1;
    while(1)
    {
        printf("Enter (1) for creation\nEnter (2) to Enquene\nEnter (3) to Dequene\n");
        printf("Enter the choice: ");
        scanf("%d",&o);
        switch(o)
        {
        case 1:
            create();
            break;
        case 2:
            enquene();
            display();
            break;
        case 3:
            dequene();
            break;
        case 4:
            printf("\nEND");
            c=0;
        }
    }

}
