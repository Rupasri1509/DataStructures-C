#include<stdio.h>
int max=0;
int m()
{
    printf("Enter the no.of.vertices:");
    scanf("%d",&max);
}
void bfs(int a[][max],int visited[],int start,int n1[][100])
{
    int q[max],rear=-1,front=-1;
    for(int k=0;k<max;k++)
        visited[k]=0;
    rear+=1;
    front+=1;
    q[rear]=start;
    visited[start]=1;
    while(rear>=front)
    {
        start=q[front];
        front+=1;
        printf("%s ",n1[start]);
        for(int i=0;i<max;i++)
        {
            if(a[start][i]==1 && visited[i]==0)
            {
                rear+=1;
                q[rear]=i;
                visited[i]=1;
            }
        }
    }
}
void dfs(int a[][max],int visited[],int start,int n1[][100])
{
    int s[max],top=-1;
    for(int i=0;i<max;i++)
        visited[i]=0;
    top+=1;
    s[top]=start;
    visited[start]=1;
    while(top!=-1)
    {
        start=s[top];
        top-=1;
        printf("%s ",n1[start]);
        for(int i=0;i<max;i++)
        {
            if(a[start][i]==1 && visited[i]==0)
            {
                top+=1;
                s[top]=i;
                visited[i]=1;
            }
        }
    }
}
int main()
{
    int n1[max][100];
    m();
    int v[50]={0};
    int n,choice;
    int a[max][max];
    do
    {
    printf("ENTER:\n1.ENTER THE VALUES\n2.BFS TRAVERSAL\n3.DFS TRAVERSAL\n4.EXIT:");
    scanf("%d",&choice);
    switch(choice)
    {
    case 1:
        {
            printf("ENTER THE NODES: ");
            for(int i=1;i<=n;i++)
            {
                scanf("%s",n1[i]);
            }
            printf("enter the adjacency matrix:\n");
            for(int i=0;i<max;i++)
            {
                for(int j=0;j<max;j++)
                {
                    scanf("%d",&a[i][j]);
                }
            }
            break;
        }
    case 2:
        {
            bfs(a,v,0,n1);
            break;
        }
    case 3:
        {
            dfs(a,v,0,n1);
            break;
        }
    }
}while(choice!=4);
}
