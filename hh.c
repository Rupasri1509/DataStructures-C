#include<stdio.h>
int a[];
void swap(int *a,int *b)
{
    int temp=*b;
    *b=*a;
    *a=temp;
}
void maxheap(int a[],int n,int i)
{
    int l=i;
    int left=2*i+1;
    int right=2*i+2;
    if(left<n && a[left]<a[l])
        l=left;
    if(right<n && a[right]<a[l])
        l=right;
    if(l!=i)
    {
        swap(&a[i],&a[l]);
        maxheap(a,n,l);
    }
}
void buildmax(int a[],int n)
{
    int last=(n/2)-1;
    for(int i=last;i>=0;i--)
    {
        maxheap(a,n,i);
    }
}
void delmax(int a[],int n)
{
    a[0]=a[n-1];
    n--;
    maxheap(a,n,0);
}
int main()
{
    int x;
    scanf("%d",&x);
    int a[100];
    for(int i=0;i<x;i++)
    {
        scanf("%d",&a[i]);
    }
    buildmax(a,x);
    //printf("%d",x);
    for(int i=0;i<x;i++)
    {
        printf("%d ",a[i]);
    }
    delmax(a,x);
    x--;
    printf("\n");
    for(int i=0;i<x;i++)
    {
        printf("%d ",a[i]);
    }
}
