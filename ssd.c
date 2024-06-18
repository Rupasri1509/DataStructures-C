#include<stdio.h>
int main()
{
    int n,top;
    printf("Enter the number of elements:");
    scanf("%d",&n);
    int a[n];
    for(int i=0;i<n;i++)
    {
        printf("Enter the value:");
        scanf("%d",&a[i]);
    }
    for(int y=0;y<n;y++)
    {
        top=a[y];
        printf("The elements after pushing in are:\n");
        for(int t=0;t<=y;t++)
        {
            printf("%d\n",a[t]);
        }
    }
    printf("STACK OVERFLOW\n");
    printf("The elements before pooping are:\n");
    for(int d=0;d<n;d++)
    {
        printf("%d\n",a[d]);
    }
    top=a[n-1];
    for(int x=2;x<=n;x++)
    {
        top=a[n-x];
        printf("\nThe elements after popping out one element:\n");
        for(int j=n-x;j>=0;j--)
        {
            printf("%d\n",a[j]);
        }
    }
    printf("Stack underflow");
}
