#include <stdio.h>
#include <stdlib.h>
#define COUNT 10
struct Node
{
    int key;
    struct Node *left;
    struct Node *right;
    int height;
};
struct node *findmin(struct Node *t)
    {
        while(t->left!=NULL)
            t=t->left;
        return t;
    };
int getHeight(struct Node *n){
    if(n==NULL)
        return 0;
    return n->height;
}
struct Node *createNode(int key){
    struct Node* node = (struct Node *) malloc(sizeof(struct Node));
    node->key = key;
    node->left = NULL;
    node->right = NULL;
    node->height = 1;
    return node;
}

int max (int a, int b){
    return (a>b)?a:b;
}

int getBalanceFactor(struct Node * n){
    if(n==NULL){
        return 0;
    }
    return getHeight(n->left) - getHeight(n->right);
}

struct Node* rightRotate(struct Node* y){
    struct Node* x = y->left;
    struct Node* T2 = x->right;

    x->right = y;
    y->left = T2;

    x->height = max(getHeight(x->right), getHeight(x->left)) + 1;
    y->height = max(getHeight(y->right), getHeight(y->left)) + 1;

    return x;
}

struct Node* leftRotate(struct Node* x){
    struct Node* y = x->right;
    struct Node* T2 = y->left;

    y->left = x;
    x->right = T2;

    x->height = max(getHeight(x->right), getHeight(x->left)) + 1;
    y->height = max(getHeight(y->right), getHeight(y->left)) + 1;

    return y;
}

struct Node *insert(struct Node *node, int key){
    if (node == NULL)
    {
        node=createNode(key);
        return node;
    }

    if (key < node->key)
        node->left  = insert(node->left, key);
    else if (key > node->key)
        node->right = insert(node->right, key);

    node->height = 1 + max(getHeight(node->left), getHeight(node->right));
    int bf = getBalanceFactor(node);

    // Left Left Case
        if(bf>1 && key < node->left->key){
            return rightRotate(node);
        }
    // Right Right Case
        if(bf<-1 && key > node->right->key){
            return leftRotate(node);
        }
    // Left Right Case
    if(bf>1 && key > node->left->key){
            node->left = leftRotate(node->left);
            return rightRotate(node);
        }
    // Right Left Case
    if(bf<-1 && key < node->right->key){
            node->right = rightRotate(node->right);
            return leftRotate(node);
        }
    return node;
}
struct Node *deleteNode(struct Node *root, int key) {
  if (root == NULL)
    return root;
  if (key < root->key)
    root->left = deleteNode(root->left, key);
  else if (key > root->key)
    root->right = deleteNode(root->right, key);
  else {
    if ((root->left == NULL) || (root->right == NULL)) {
      struct Node *temp = root->left ? root->left : root->right;
      if (temp == NULL) {
        temp = root;
        root = NULL;
      } else
        *root = *temp;
      free(temp);
    } else {
      struct Node *temp = findmin(root->right);
      root->key = temp->key;
      root->right = deleteNode(root->right, temp->key);
    }
  }
  if (root == NULL)
    return root;
  root->height = 1 + max(getHeight(root->left),
               getHeight(root->right));
  int balance = getBalanceFactor(root);
  if (balance > 1 && getBalanceFactor(root->left) >= 0)
    return rightRotate(root);
  if (balance > 1 && getBalanceFactor(root->left) < 0) {
    root->left = leftRotate(root->left);
    return rightRotate(root);
  }
  if (balance < -1 && getBalanceFactor(root->right) <= 0)
    return leftRotate(root);
  if (balance < -1 && getBalanceFactor(root->right) > 0) {
    root->right = rightRotate(root->right);
    return leftRotate(root);
  }
  return root;
}
void display(struct Node *root,int space)
{
     if (root == NULL)
        return root;
    space += COUNT;
    display(root->right, space);
    printf("\n");
    for (int i = COUNT; i < space; i++)
        printf(" ");
    printf("%d\n", root->key);
    display(root->left, space);
}

int main(){
    struct Node * root = NULL;
     int n,a;
    printf("enter the data:\n");
    for(int i=0;i<100;i++)
    {
        scanf("%d",&n);
        if(n==-1)
            break;
        root=insert(root,n);
    }
    display(root,0);
    printf("ENTER THE ELEMENT TO BE DELETED:");
    scanf("%d",&a);
    deleteNode(root,a);
    printf("AFTER DELETION:\n");
    display(root,0);
    return 0;
}
