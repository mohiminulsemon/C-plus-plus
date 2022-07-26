#include<bits/stdc++.h>
using namespace std;

#define MAX 10000
#define INF 1000000000

int main()
{
    int n,e,a,b,c,i,u,k,v,w,source,size;

    vector<pair<int,int> > G[MAX];

    cin>> n >> e >> source;

    vector<int> distance(n,INF);

    for(i = 0; i<e; i++)
    {
        cin>> a >> b >> c;
        G[a].push_back({b,c});
    }

    distance[source] = 0;

    for(i = 0;i< n-1;i++)//1 based graph
        for(u = 0; u<n; u++)
    {
        size = G[u].size();
        for(k = 0; k<size; k++)
        {
            v = G[u][k].first;
            w = G[u][k].second;
            distance[v] = min(distance[v],distance[u]+ w);
        }
    }

    bool negative_cycle = false;

    for(u=0; u<n ; u++)
        for(i=0; i<G[u].size(); i++)
    {
         v = G[u][i].first;
         w = G[u][i].second;
         if(distance[v]>distance[u]+ w) {
                negative_cycle=true;
                break;
         }
    }

    if(negative_cycle) cout<<"negative cycle found."<<endl;
    else
        for(i=0;i<n;i++)
    {
        cout<<"SSSP from "<<source<<" to "<<i<<" is "<<distance[i]<<endl;
    }

}

/* no negative cycle
  5 5 0
  0 1 1
  0 2 10
  1 3 2
  2 3 -10
  3 4 3

*/

/*negative cycle
  3 3 0
  0 1 1000
  1 2 15
  2 1 -42
*/
