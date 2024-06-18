#include<stdio.h>
#include<stdlib.h>
#define COUNT 10
struct tree{
int data;
struct tree *left,*right;
};
struct tree *create()
{
    struct tree *newnode;
    newnode=malloc(sizeof(struct tree));
    printf("ENTER THE DATA(-1 if no data):");
    scanf("%d",&(newnode->data));
    if(newnode->data==-1)
        return NULL;
    printf("\nENTER THE LEFT NODE :`\n");
    newnode->left=create();
    printf("\nENTER THE RIGHT NODE :\n");
    newnode->right=create();
    return newnode;
};
void preorder(struct tree *roots)
{
    if(roots==NULL)
        return;
    printf("%d,",roots->data);
    preorder(roots->left);
    preorder(roots->right);
}
void inorder(struct tree *roots)
{
     if(roots==NULL)
        return;
    inorder(roots->left);
    printf("%d,",roots->data);
    inorder(roots->right);
}
void postorder(struct tree *roots)
{
    if(roots==NULL)
        return;
    postorder(roots->left);
    postorder(roots->right);
    printf("%d,",roots->data);
}
void display(struct tree* root, int space)
{
    if (root == NULL)
        return;
    space += COUNT;
    display(root->right, space);
    printf("\n");
    for (int i = COUNT; i < space; i++)
        printf(" ");
    printf("%d\n", root->data);
    display(root->left, space);
}
void main()
{
    struct tree *root=0;
    root=create();
    printf("\nPREORDER:\n");
    preorder(root);
    printf("\nINORDER:\n");
    inorder(root);
    printf("\nPOSTORDER:\n");
    postorder(root);
    display(root,0);
}
