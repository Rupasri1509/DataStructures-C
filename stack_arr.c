#include<stdio.h>
#include<stdlib.h>
int a[100],top=-1;
void create()
{
int n;
printf("enter the total elements:");
scanf("%d",&n);
for(int i=0;i<n;i++)
{
top=top+1;
printf("ENTER THE ELEMENT:");
scanf("%d",&a[top]);
}
}
void push()
{
int n;
printf("\nENTER THE ELEMENT TO BE PUSHED:");
scanf("%d",&n);
if(top==(sizeof(a)))
{
printf("stack is full");
}
else
{
top=top+1;
a[top]=n;
}
}
void pop()
{
if(top<0)
{
    printf("stack underflow");
}
else
    top=top-1;
printf("\nAFTER POPING:");
display();
}
void display()
{
for(int i=0;i<=top;i++)
printf("%d",a[i]);
}
int main()
{
int n,c=1;
while(c)
{
printf("\nENTER:\n1.CREATE\n2.PUSH\n3.POP\n4.EXIT\n");
scanf("%d",&n);
switch(n)
{
case 1:
create();
printf("\nAFTER CREATING:");
display();
break;
case 2:
push();
printf("AFTER PUSHING:");
display();
break;
case 3:
pop();
break;
case 4:
c=0;
break;
}
}
}
