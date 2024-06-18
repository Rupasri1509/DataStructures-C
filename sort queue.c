#include<stdio.h>
int q[],q2[],s[],top=-1,front=-1,rear=-1;

int create(int n)
{
    int num,i;
    while(i<n){
    printf("Enter a data :");
    scanf("%d",&num);
    if(front==n)
        printf("overflow");
    if(front==-1)
    {
        front++;
        rear++;
    }
    else
        rear++;
    q[rear]=num;
    i++;
    }

}
int swap(int *a,int *b)
{
    int p=*a;
    *b=*a;
    *b=p;
}
int main()
{
    int n,i,p;
    printf("Enter no. of elements in queue 1:");
    scanf("%d",&n);
    create(n);

    printf("queue 1\n");
    for(int i=0;i<n;i++)
        printf("%d ",q[i]);

    top++;
    int t=n;
    s[top]=q[0];
    printf("\n%d\n",s[top]);
    int q2[]={0,0};

    printf("\n%d\n",q2[0]);
   for(i=1;i<n;i++)
    {
            if(q[i]<s[top])
            {
               q2[i-1]=q[i];
               if((i-1)==0)
                continue;

               else if(q2[i-1]<q2[i-2])
                {
                    printf("%d d\n",i);
                    swap(&q2[i-1],&q2[i-2]);
                //p=q2[i-2];
               // q2[i-2]=q[i-1];
                //q2[i-1]=p;
                }
            }
            else
            {
                q2[i-1]=s[top];
                s[top]=q[i];
            }

    }
    printf("\nn:%d\n",t);
    for(int i=0;i<t;i++)
        printf("%d ",q2[i]);


}
