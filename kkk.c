#include<stdio.h>
struct node
    {
        int data,next;
    }*first,*mid,*last,*newnode;
int display(struct node *p)
{
int q=p;
while(1)
{
if(p->next==q)
{
printf("%d",p->data);
p=p->next;
break;
}
else
{
printf("%d",p->data);
p=p->next;
}

}
}
int head;
int mains()
{
    first=malloc(sizeof(struct node));
    mid=malloc(sizeof(struct node));
    last=malloc(sizeof(struct node));
    newnode=malloc(sizeof(struct node));
    first->data=1;
    mid->data=2;
    last->data=3;
    first->next=mid;
    mid->next=last;
    last->next=first;
    head=first;
}
int main()
{
    mains();                  //ADT to deletion at beginning
    head=first->next;
    last->next=first->next;
    free(first);
    display(head);
    printf("\n");
    mains();                 //ADT to deletion at middle
    first->next=mid->next;
    free(mid);
    display(head);
    printf("\n");
    mains();                 //ADT to deletion at last
    mid->next=last->next;
    free(last);
    display(head);
}
