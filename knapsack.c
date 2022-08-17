#include <stdio.h>
#include <stdlib.h>

int max(int a, int b)
{
  if(a>b)
  return a;
  else
  return b;
}

int knapsack(int c, int wt[], int val[], int n)
{
  int i,j;
  int k[n+1][c+1];
  for(i=0; i<=n; i++)
  {
    for(j=0; j<=c; j++)
    {
      if(i==0 || j==0)
      k[i][j] = 0;
      else if (wt[i-1]<=j)
      k[i][j] = max(k[i-1][j],val[i-1]+k[i-1][j-wt[i-1]]);
      else
      k[i][j] = k[i-1][j];
    }
  }
  for(i=0; i<=n; i++)
  {
    for(j=0; j<=n; j++)
    {
      printf("%5d",k[i][j]);
    }
    printf("\n");
  }
  return k[n][c];
}

int main()
{
  int val[10],wt[10],c,n,i;
  printf("\nEnter number of elements: ");
  scanf("%d",&n);
  printf("\nEnter the weight and profit: ");
  for(i=0; i<n; i++)
  {
    scanf("%d%d",&wt[i],&val[i]);
  }
  printf("\nEnter max capacity of knapsack: ");
  scanf("%d",&c);
  printf("\nThe maximum profit of knapsack = %d",knapsack(c,wt,val,n));
}

/*
Enter number of elements: 4

Enter the weight and profit: 
1 1 
3 4
4 5 
5 7 

Enter max capacity of knapsack: 7 
    0    0    0    0    0
    0    1    1    1    1
    0    1    1    4    5
    0    1    1    4    5
    0    1    1    4    5

The maximum profit of knapsack = 9%
*/