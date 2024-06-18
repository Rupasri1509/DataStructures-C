#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *next;
};
struct node *head;
void display(struct node *p)
{
    while(p!=NULL)
    {
        printf("%d",p->data);
        p=p->next;
    }
    printf("\n");
}
int insertbeg(struct node*n)
{
    struct node*newnode;
    newnode=malloc(sizeof(struct node));
    newnode->data=4;
    newnode->next=n->next;
    n->next=newnode;
    display(head);
}
int insertend(struct node*n)
{
    struct node*newnode;
    newnode=malloc(sizeof(struct node));
    newnode->data=4;
    newnode->next=n->next;
    n->next=newnode;
    n=newnode;
    display(head);
}
int main()
{
    struct node*one,*two,*three,*newnode;
    head=malloc(sizeof(struct node));
    one=malloc(sizeof(struct node));
    two=malloc(sizeof(struct node));
    three=malloc(sizeof(struct node));
    head->data=NULL;
    one->data=1;
    two->data=2;
    three->data=3;
    head->next=one;
    one->next=two;
    two->next=three;
    three->next=head;
    insertbeg(head);
    insertend(three);

}
