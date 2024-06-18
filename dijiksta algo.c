#include<stdio.h>
int main()
{
    int n;
    printf("ENTER THE NUMBER OF NODES :");
    scanf("%d",&n);
    int cost[n][n],distance[n],fromnode[n],visited[n],nextnode,ne=1,min,startnode;
    int n1[n][100];
    printf("ENTER THE NODES: ");
	for(int i=0;i<n;i++)
    {
        scanf("%s",n1[i]);
    }
    printf("ENTER THE ADJACANCY MATRIX \n:");
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
        {
            scanf("%d",&cost[i][j]);
            if(cost[i][j]==0)
                    cost[i][j]=999;
        }
    printf("ENTER THE START NODE :");
    scanf("%d",&startnode);
    for(int i=0;i<n;i++)
    {
        distance[i]=cost[startnode][i];
        fromnode[i]=startnode;
        visited[i]=0;
    }
    distance[startnode]=0;
    visited[startnode]=1;
    while(ne<n)
    {
        min=999;
        for(int i=0;i<n;i++)
            if(distance[i]<min && !visited[i])
            {
                min=distance[i];
                nextnode=i;
            }
            visited[nextnode]=1;
        for(int i=0;i<n;i++)
            if(distance[i]>(min+cost[nextnode][i] )&& !visited[i])
            {
                distance[i]=min+cost[nextnode][i];
                fromnode[i]=nextnode;
            }
            ne++;
    }
    for(int i=0;i<n;i++)
        if(i!=startnode)
        {
            printf("\nDistance of %s = %d", n1[i], distance[i]);
			printf("\nPath = %s", n1[i]);
			int j=i;
			do
			{
				j=fromnode[j];
				printf(" <-%s", n1[j]);
			}
			while(j!=startnode);
        }
}
