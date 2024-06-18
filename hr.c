#include<stdio.h>
# define COUNT 10
struct node
{
    int data;
    struct node *left,*right;
};
struct node *findmin(struct node *t)
    {
        while(t->left!=NULL)
            t=t->left;
        return t;
    };
struct node *putdata(int value)
{
    struct node *newnode=malloc(sizeof(struct node));
    newnode->data=value;
    newnode->left=newnode->right=NULL;
    return newnode;
};
struct node *insert(int x,struct node *t)
{
    if(t==NULL)
    {
        t=putdata(x);
        return t;
    }
    if(x>t->data)
    {
        t->right=insert(x,t->right);
        return t;
    }
    if(x<t->data)
    {
        t->left=insert(x,t->left);
        return t;
    }
}
