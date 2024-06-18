#include<stdio.h>
int a[],front=-1,rear=-1,n;
int cr()
{
printf("enter the size of array:");
scanf("%d",&n);
}

void enqueue()
{
if(rear==n-1)
{
printf("queue overflow");
}
else if(front==-1)
{
front+=1;
rear+=1;
printf("enter the element:");
scanf("%d",&a[rear]);
}
else
{
rear+=1;
printf("enter the element:");
scanf("%d",&a[rear]);
}
}
void dequeue()
{
if(front==n)
    printf("queue underflow");
else if(rear==0)
{
front-=1;
rear-=1;
}
else
{
front+=1;
}
}
void display()
{
for(int i=front;i<=rear;i++)
{
printf("%d",a[i]);
}
}
int main()
{
int c=1,n;
cr();
while(c)
{
printf("\nenter:\n1.enqueue\n2.dequeue\n3.exit\n");
scanf("%d",&n);
switch(n)
{
case 1:
enqueue();
printf("\nthe elements:");
display();
break;
case 2:
dequeue();
printf("\nthe elements:");
display();
break;
case 3:
c=0;
break;
}
}}
