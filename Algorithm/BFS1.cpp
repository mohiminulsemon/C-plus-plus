#include<stdio.h>
#include<queue>
using namespace std;
int main()
{
    int g[100][100],n,i,j,dist[100],visited[10],source;
    queue<int>q;

    printf("enter the no. of nodes: ");
    scanf("%d",&n);

    for(i=1;i<=n;i++)
        for(j=1;j<=n;j++)
        scanf("%d",&g[i][j]);

    for(i=1;i<=n;i++) visited[i]=0;

    printf("enter sorce: ");

    scanf("%d",&source);

    dist[source]=0;
    visited[source]=1;
    q.push(source);

    int u;
    while(!q.empty())
    {
        u = q.front();
        for(j=1;j<=n;j++)
        {
            if(g[u][j]==1 && visited[j]==0)
            {
                visited[j]=1;
                q.push(j);
                dist[j]=dist[u]+1;
            }
        }
        q.pop();
    }
    for(i=1;i<=n;i++)
    {
      printf("\ndist %d to %d = %d",source,i,dist[i]);
    }
}
