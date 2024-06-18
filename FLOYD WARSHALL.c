#include<stdio.h>
int n,c[10][10];
int main()
{
    printf("ENTER THE NO.OF.VERTICES: ");
    scanf("%d",&n);
    printf("ENTER THE ADJACENCY MATRIX:\n");
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            scanf("%d",&c[i][j]);
        }
    }
    for(int k=0;k<n;k++)
    {
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(c[i][j] > c[i][k]+c[k][j])
                c[i][j]=c[i][k]+c[k][j];
            }
        }
    }
    printf("THE FLOYD MATRIX:\n");
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            printf("%d ",c[i][j]);
        }
        printf("\n");
    }
}

