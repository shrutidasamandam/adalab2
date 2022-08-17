#include<stdio.h>
int a,b,u,v,n,i,j,ne=1;
int parent[10],min,mincost=0,adj[10][10];

int find(int i)
{
  while(parent[i])
  i = parent[i];
  return i;
}

int uni(int i, int j)
{
  if(i!=j)
  {
    parent[j]=i;
    return 1;
  }
  return 0;
}

void main()
{
	printf("\nEnter the number of nodes:");
	scanf("%d",&n);
	printf("\nEnter the adjacency matrix:\n");
	for(i=1;i<=n;i++)
    {
	for(j=1;j<=n;j++)
	{
		scanf("%d",&adj[i][j]);
		if(adj[i][j]==0)
			adj[i][j]=999;
	}
    }
	while(ne < n)
	{
		for(i=1,min=999;i<=n;i++)
    {
		for(j=1;j<=n;j++)
    {
		if(adj[i][j]< min)
		{
			min=adj[i][j];
			a=u=i;
			b=v=j;
      }
		}
  }
u  = find(u);
v = find(v);
 if(uni(u,v))
{
  printf("\n%d edge (%d,%d) = %d",ne++,a,b,min);
  mincost = mincost + min;
}
adj[a][b] = adj[b][a] = 999;
}
printf("\nMinimum cost = %d\n",mincost);
}

/*
Enter the number of nodes:6

Enter the adjacency matrix:
0 3 0 0 6 5
3 0 1 0 0 4
0 1 0 6 0 4
0 6 6 0 8 5
6 0 0 8 0 2
5 4 4 5 2 0 
n1 edge (2,3) = 1n2 edge (5,6) = 2n3 edge (1,2) = 3n4 edge (2,6) = 4n5 edge (4,6) = 5
Minimum cost = 15
*/
