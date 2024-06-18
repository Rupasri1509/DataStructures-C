#include<stdio.h>
int top=0;
int main()
{
int n,d,t;
printf("enter the no.of.elements:");
scanf("%d",&n);
int a[n],b[n];
int s[n];
int front1=-1,rear1=-1;
int front2=-1,rear2=-1;
for(int i=0;i<n;i++)
{
printf("ENTER THE ELEMENT:");
scanf("%d",&d);
if(front1==-1)
{
front1+=1;
rear1+=1;
a[rear1]=d;
}
else
{
rear1+=1;
a[rear1]=d;
}
}
int i;
for(i=front1;i<=rear1;i++)
{
if(top==0)
{
//printf("d:\n%d\n",a[i]);
s[top]=a[i];
printf("d:%d\n",s[top]);
top+=1;
}
else if(s[top]>s[top-1])
{
s[top]=a[i];
top+=1;
printf("t:%d",s[top-1]);
}
else if(s[top-1]<s[top-2])
{
int temp=s[top-1];
printf("c:%d",s[top-1]);
while(top!=-1)
{
if(front2==-1)
{
front2+=1;
rear2+=1;
}
else
{
rear2+=1;
}
b[rear2]=s[top];
top-=1;
}
top=0;
s[top]=temp;
}
}
while(top!=-1)
{
if(front2==-1)
{
front2+=1;
rear2+=1;
}
else
{
rear2+=1;
}
b[rear2]=s[top-1];
top-=1;
}
/*for(int i=front2;i<=rear2;i++)
{
printf("%d\n",b[i]);*/
}
