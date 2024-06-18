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
    printf("Enter the number of nodes :");
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
    printf("Original list values :\n");
    display(head);
    int position;
    for(int i=0;i<3;i++)
    {
    struct node *newnode;
    newnode=malloc(sizeof(struct node));
        printf("\nENTER THE POSITION :");
        scanf("%d",&position);
        printf("NEWNODE VALUE :");
        scanf("%d",&(newnode->data));
        for(int i=0;i<100;i++)
        {
            if(i==(position))
            {
                if(i==0)
                {
                    n++;
                    newnode->next=head;
                    head=newnode;
                    break;

                }
                else
                {
                    n++;
                    newnode->next=a[i-1]->next;
                    a[i-1]->next=newnode;
                    break;
                }
            }
    printf("%d",n);


        for(int i=0;i<n;i++)
        {
            if(i==0)
            {
                a[i]=head;
            }
            else
            {
                a[i]=a[i-1]->next;
            }
        }
        display(head);
       // for(int i=0;i<n+1;i++)
        //{
          //  printf("\nnode %d value %d",a[i],a[i]->next);
        }
        }
    }
       // n++;
    //}

