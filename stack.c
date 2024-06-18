#include<stdio.h>
struct stack{
int data;
struct stack *next;
};
void pop(struct stack *p)
{
int temp;
temp=p;
if(p==NULL)
    printf("STACK UNDERFLOW");
else
{
    p=p->next;
    free(temp);
    printf("AFTER POP:");
    print(p);
    printf("\n");
    pop(p);
}
}
void print(struct stack *p)
{
while(p!=NULL)
{
printf("%d"/* %d %d\n*/,p->data/*,p,p->next*/);
p=p->next;
}
}
int main()
{
int *top=NULL;
int n;
printf("ENTER THE NO.OF.NODE:");
scanf("%d",&n);
struct stack *a;
for(int i=1;i<=n;i++)
{
a=malloc(sizeof(struct stack));
printf("ENTER THE DATA:");
scanf("%d",&(a->data));
if(top==NULL)
{
a->next=top;
top=a;
}
else
{
a->next=top;

top=a;
}
}
print(top);
int b=1;
while(b)
{
struct stack *newnode;
newnode=malloc(sizeof(struct stack));
printf("\nENTER THE DATA TO BE PUSHED:");
scanf("%d",&(newnode->data));
newnode->next=top;
top=newnode;
printf("AFTER PUSHING AND PRINTING IN FUNCTION:");
print(top);
printf("\nENTER ONE TO PUSH AGAIN:");
scanf("%d",&b);
}
print(top);
pop(top);
}
