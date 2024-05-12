#include<stdio.h>
#define MAX_CITIES 20
#define INF 9999
int n, d[MAX_CITIES][MAX_CITIES],dp[1<<MAX_CITIES][MAX_CITIES],av;
int t(int v ,int p)
{
    if(v==av)return d[p][0];
    if(dp[v][p]!=-1)return dp[v][p];
    int a =INF;

    for(int c=0;c<n;c++)
    if(!(v&(1<<c)))
    {
        int nv=v | (1<<c),na=d[p][c]+t(nv,c);
        a=(a<na)?a:na;


    }
    return dp[v][p]=a;
}
int main()
{
  printf("ENTER THE NO OF CITIES:\n");
  scanf("%d",&n);

  printf("ENTER THE DISTANCES:\n");
  for(int i=0;i<n;i++)
  {
      for(int j=0;j<n;j++)
      {
        scanf("%d",&d[i][j]);
      }
  }



  for(int i=0;i<(1<<n);i++)
  {
      for(int j=0;j<n;j++)
      {
          dp[i][j]=-1;
          av=(1<<n)-1;
      }
  }
  printf("THE COST IS %d\n",t(1,0));
  return 0;
}
