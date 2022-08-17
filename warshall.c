#include <stdio.h>
#include <stdlib.h>

int a[10][10],t[10][10],n;

void warshallspath()
{
  int i,j,k;
  for(k=0; k<n; k++){
    for(i=0; i<n; i++){
      for(j=0; j<n; j++)
      {
        if( t[i][j] || t[i][k] && t[k][j] )
        t[i][j] = 1;
      }
    }
  }
}

int main()
{
  int i,j;
  printf("\nEnter n number of vertices: ");
  scanf("%d",&n);
  printf("\nEnter the adjacent matrix: \n");
  for(i=0; i<n; i++)
    for(j=0; j<n; j++)
    {
      scanf("%d",&a[i][j]);
      t[i][j] = a[i][j];
    }
    warshallspath();
    printf("\n The final transitive closure is : \n");
  for(i=0; i<n; i++)
    {
    for(j=0; j<n; j++)
    {
      printf("%5d",t[i][j]);
    }
    printf("\n");
  }
}

/*
Enter n number of vertices: 4

Enter the adjacent matrix: 
0 1 0 1 
0 0 1 0 
0 0 0 1
0 1 0 0 

 The final transitive closure is : 
    0    1    1    1
    0    1    1    1
    0    1    1    1
    0    1    1    1
*/