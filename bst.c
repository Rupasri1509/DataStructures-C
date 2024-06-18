#include<stdio.h>
# define COUNT 4
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
void inorder(struct node *roots)
{
    if(roots==0)
        return;
    inorder(roots->left);
    printf("%d,",roots->data);
    inorder(roots->right);
}
void preorder(struct node *roots)
{
    if(roots==0)
        return;
    printf("%d,",roots->data);
    preorder(roots->left);
    preorder(roots->right);
}
void postorder(struct node *roots)
{
    if(roots==0)
        return;
    postorder(roots->left);
    postorder(roots->right);
    printf("%d,",roots->data);
}
struct node *Delete(int x,struct node *t)
{
    if(t==NULL)
        printf("NO ELEMENT");
    if(x<t->data)
    {
        t->left=Delete(x,t->left);
        return t;
    }
    if(x>t->data)
    {
        t->right=Delete(x,t->right);
        return t;
    }
    if(t->left==NULL && t->right==NULL)
    {
        struct node *temp=t;
        free(temp);
        return NULL;
    }
    if(t->left==NULL)
    {
        struct node *temp=t;
        t=t->right;
        free(temp);
        return t;
    }
    if(t->right==NULL)
    {
        struct node *temp=t;
        t=t->left;
        free(temp);
        return t;
    }
    struct node *temp=findmin(t->right);
    t->data=temp->data;
    t->right=Delete(temp->data,t->right);
    return t;
};
void display(struct node* root, int space,int d)
{
    if (root == NULL)
        return;
    //printf("%d",root->data);
    space += COUNT;
    display(root->right, space,d);
    printf("\n");
    for (int i = COUNT; i < space; i++)
        printf(" ");
    printf("%d\n", root->data);
    if((root->data)>d)
    {
        //printf("d");
     for (int i = COUNT; i < space-2; i++)
     {
        printf(" ");
        if(i==(space-3))
            printf("X");
     }
    }
   /* else
    {
        //printf("d");
        for (int i =COUNT; i< space-2; i++)
     {
        printf(" ");
        if(i==(space-3))
           printf("X  ");
     }
    }*/
    //printf("%d %d",space,COUNT);
    display(root->left,space,d);
}
int main()
{
    struct node *root=NULL;
    int x;
    printf("ENTER THE DATA :");
    for(int i=0;i<100;i++)
    {
        scanf("%d",&x);
        if(x==-1)
            break;
        root=insert(x,root);
    }
    //printf("%d",root->data);
    display(root,0,root->data);
    printf("\nINORDER :\n");
    inorder(root);
    printf("\nPREORDER :\n");
    preorder(root);
    printf("\nPOSTORDER :\n");
    postorder(root);
    printf("\nENTER THE ELEMENT TO BE DELETED :");
    scanf("%d",&x);
    Delete(x,root);
    display(root,0,root->data);
    printf("\nINORDER :\n");
    inorder(root);
    printf("\nPREORDER :\n");
    preorder(root);
    printf("\nPOSTORDER :\n");
    postorder(root);
}
