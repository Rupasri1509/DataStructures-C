#include<stdio.h>
#include<string.h>
struct node
{
char data;
struct node *next;
};
int main()
{
int c=0;
struct node *top=NULL,*temp;
char a[100],b[100];
printf("ENTER THE EXPRESSION:");
scanf("%s",&a);
int n=strlen(a);
for(int i=0;i<n;i++)
{
if(a[i]=='(')
{
struct node *newnode;
newnode=malloc(sizeof(struct node));
newnode->data=a[i];
if(top==0)
{
    newnode->next=NULL;
    top=newnode;
}
else
{
newnode->next=top;
top=newnode;
}
}
else if(a[i]=='+' || a[i]=='-')
{
if(top->data=='*'  || top->data=='/')
{
while(top!=NULL)
{
temp=top;
if(top->data!='(')
{
b[c]=top->data;
c++;
}
top=temp->next;
free(temp);
}
struct node *newnode;
newnode=malloc(sizeof(struct node));
newnode->data=a[i];
if(top==0)
{
    newnode->next=NULL;
    top=newnode;
}
else
{
newnode->next=top;
top=newnode;
}
}
else
{
struct node *newnode;
newnode=malloc(sizeof(struct node));
newnode->data=a[i];
if(top==0)
{
    newnode->next=NULL;
    top=newnode;
}
else
{
newnode->next=top;
top=newnode;
}
}
}
else if(a[i]=='*'||a[i]=='/')
{
struct node *newnode;
newnode=malloc(sizeof(struct node));
newnode->data=a[i];
if(top==0)
{
    newnode->next=NULL;
    top=newnode;
}
else
{
newnode->next=top;
top=newnode;
}
}
else if(a[i]==')')
{
do
{
temp=top;
if(top->data!='(')
{
b[c]=top->data;
c++;
}
top=temp->next;
free(temp);
}while((top->data)!='(');
}
else if(i==n)
{
b[c]=a[i];
c++;
while(top!=NULL)
{
temp=top;
if(top->data!='(')
{
b[c]=top->data;
c++;
}
top=temp->next;
free(temp);
}
}
else
{
    b[c]=a[i];
    c++;
}
}
for(int i=0;i<c;i++)
{
printf("%c",b[i]);
}
}
