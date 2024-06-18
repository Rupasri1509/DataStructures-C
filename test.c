#include<stdio.h>
int size=0;
int hash(int k)
{
    int i;
    i=k%size;
    return i;
}
int rel(int k)
{
    int i;
    i=(k+1)%size;
    return i;
}
int req(int k,int j)
{
    int i;
    i=(k+(j*j))%size;
    return i;
}
int red(int k)
{
    int p;
    for(int i=size;i>=2;i--)
    {
        int c=0;
        for(int j=size;j>=2;j--)
        {
            if(i%j==0)
                c+=1;
        }
        if(c==1)
        {
            p==i;
            break;
        }
    }
    printf("\n%d",p);
    int d;
    d=p-(k%p);
    return d;
}
int main()
{
    int n,key,x;
    printf("ENTER THE TAB SIZE:");
    scanf("%d",&size);
    printf("NETER THE NO:");
    scanf("%d",&n);
    int a[n],h[size];
    printf("ENTER THE ELEMENTS: ");
    for(int i=0;i<n;i++)
        scanf("%d",&a[i]);
    for(int k=0;k<size;k++)
        h[k]=-1;
    for(int i=0;i<n;i++)
    {
        //int j=1;
        key=a[i];
        x=hash(key);
        while(h[x]!=-1)
        {
            x=red(x);
            //j++;
        }
        h[x]=key;
    }
    for(int i=0;i<size;i++)
        printf("THE POSITION %d is %d\n",i,h[i]);

}
