#include <stdio.h>
#define TRUE 1
#define FALSE 0

int inc[50],w[50],sum,n;

void sumset(int i, int wt, int total)
{
  int j;
  if(((wt+total)>=sum)&&((wt == sum)||(wt + w[i+1]<=sum)))
  {
    if(wt == sum){
      printf("\n{\t");
      for(j=0; j<=i; j++)
      if(inc[j])
      printf("%d\t",w[j]);
      printf("}\n");
    } else {
      inc[i+1] = TRUE;
      sumset(i+1,wt+w[i+1],total-w[i+1]);
      inc[i+1] = FALSE;
      sumset(i+1,wt,total-w[i+1]);
    }
  }
}

void main(){
  int i,j,n,temp,total = 0;
  printf("\nEnter amount of numbers: ");
  scanf("%d",&n);
  printf("\nEnter the numbers: ");
  for(i=0; i<n; i++){
    scanf("%d",&w[i]);
    total = total + w[i];
  }
  printf("\nInput the sum value to create subsets: ");
  scanf("%d",&sum);
  for(i=0; i<=n; i++)
    for(j=0; j<n-1; j++)
      if(w[j]>w[j+1]){
        temp = w[j];
        w[j] = w[j+1];
        w[j+1] = temp;
      }
      printf("\n The given numbers in ascending order: ");
      for(int i=0; i<n; i++)
        printf("%d\t",w[i]);
      
      if(total < sum)
        printf("\n Subset construction not possible");
      else
        for(i=0; i<n; i++)
        inc[i] = 0;
        printf("\n Backtracking solution is: ");
        sumset(-1,0,total);
    }