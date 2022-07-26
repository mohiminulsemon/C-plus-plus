#include<bits/stdc++.h>
using namespace std;
#define LIM 10000

void bfs(vector<int> G[LIM],int d[],bool vis[],int pre[],int source)
    {
        d[source] = 0;
        vis[source] = 1;
        queue<int> q;
        q.push(source);

        while(q.size())
        {
            int u = q.front();
            q.pop();

            int size= G[u].size();//time optimization, means we don't need to calculate G[u].size() every time

            for(int i=0;i<size;i++)//instead of, for(int i=0;i<G[u].size();i++)
            {
                int v= G[u][i];

                if(!vis[v])
                {
                    pre[v]=u;
                    vis[v] = 1;
                    d[v] = d[u]+1;
                    q.push(v);
                }
            }
        }


    }

int main()
{
    int t,n,e,a,b;
    int distance[LIM],previous[LIM];
    bool visited[LIM];
    vector<int> G[LIM];

    cin>>t;

    while(t--)
    {
        cin>> n >> e;

        memset(visited,0,sizeof visited);
        memset(distance,-1,sizeof distance );
        for(int u=1; u<=n; u++) G[u].clear();//1 based graph

        for(int i=0;i<e;i++)
        {
            cin>> a >> b;
            G[a].push_back(b);
        }

        int source =1;
        bfs(G,distance,visited,previous,source);

        cout<<"#distance from SOURCE to NODE is SHORTEST DISTANCE/LEVEL: BACK TRAVERSING PATH TO SOURCE"<<endl<<endl;
        for(int i=1;i<=n;i++)
        {
            cout<<"distance from "<<source<<" to "<<i<<" is "<<distance[i]<<": ";

            int j=i;
            while(j!=source)
            {
                cout<<previous[j]<<" ";
                j=previous[j];
            }
            cout<<endl;
        }


    }
}

/*
1
10 13
1 2
1 4
1 3
2 6
4 7
3 8
3 7
6 10
7 9
9 10
8 5
5 10
7 8
*/
