#include<stdio.h>

#define v 4
#define INF 999

void floydwarshall(int [][v]);

int main()
{
	int graph[v][v]={{0,3,6,15},{INF,0,-2,INF},{INF,INF,0,2},{1,INF,INF,0}};
	floydwarshall(graph);
	return 0;
}

void floydwarshall(int g[][v])
{
	int dist[v][v],i,j,k,path[v][v];
	for(i=0;i<v;i++)
		for(j=0;j<v;j++)
		{
			dist[i][j]=g[i][j];
			if(dist[i][j]==0 || dist[i][j]==INF)
				path[i][j]=-1;
			else if(dist[i][j]>0 || dist[i][j]<0)
				path[i][j]=i;
		}
	
	printf("initial distance matrix\n");
	for(i=0;i<v;i++)
	{
                for(j=0;j<v;j++)
		{
                        printf("%d\t",dist[i][j]);
		}
		printf("\n");
	}
	printf("\n");

	printf("initial path matrix\n");
	for(i=0;i<v;i++)
        {
                for(j=0;j<v;j++)
                {
                        printf("%d\t",path[i][j]);
                }
                printf("\n");
        }
	printf("\n");

	
	for(k=0;k<v;k++)
		for(i=0;i<v;i++)
			for(j=0;j<v;j++)
			{
				if (dist[i][k] + dist[k][j] < dist[i][j])
				{ 
                    			dist[i][j] = dist[i][k] + dist[k][j];
					path[i][j]=path[k][j];
				}
					 
			}
	printf("shortest path matrix\n");
	for (int i = 0; i < v; i++) 
    	{ 
        	for (int j = 0; j < v; j++) 
        	{ 
            		if (dist[i][j] == INF) 
                		printf("INF\t"); 
            		else
                		printf ("%d\t", dist[i][j]); 
        	} 
        	printf("\n"); 
    	}
	printf("\n"); 

	printf("final path matrix\n");
	for(i=0;i<v;i++)
        {
                for(j=0;j<v;j++)
                {
                        printf("%d\t",path[i][j]);
                }
                printf("\n");
        }
	while(1)
	{
		int s,d;
		printf("enter source : ");
		scanf("%d",&s);
		printf("enter destination : ");
		scanf("%d",&d);
		printf("<-%d",d);
		while(path[s][d]!=s && path[s][d]!=-1)
		{
			printf("<-%d",path[s][d]);
			d=path[s][d];
       		}
		printf("<-%d",s);
		printf("\n");
	}
}
