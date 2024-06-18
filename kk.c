#include<stdio.h>
#include<conio.h>
int main() {
int u,v,n,i,j,ne=1;
int visited[10]= {0},min,mincost=0,cost[10][10];
	printf("\n Enter the number of nodes:");
	scanf("%d",&n);
	int nodes[n][100];
	printf("Enter the nodes:");
	for(int i=1;i<=n;i++)
        scanf("%s",nodes[i]);
	printf("\n Enter the adjacency matrix:\n");
	for (i=1;i<=n;i++)
	  for (j=1;j<=n;j++) {
		scanf("%d",&cost[i][j]);
		if(cost[i][j]==0)
		    cost[i][j]=999;
	}
	printf("The edges of Minimum Cost Spanning Tree are\n");
	while(ne<n) {
		for (i=1,min=999;i<=n;i++)
		   for (j=1;j<=n;j++)
		    if(cost[i][j]<min)
            {
			min=cost[i][j];
			u=i;
			v=j;
		}
		if(u!=v) {
			printf("\n Edge %d:(%s %s) cost:%d",ne++,nodes[u],nodes[v],min);
			mincost+=min;

		}
		cost[u][v]=cost[v][u]=999;
	}
	printf("\n Minimun cost=%d",mincost);
}
