#include<bits/stdc++.h>
using namespace std;
#define LIM 10000

bool bfs_bicolorable(vector<int> G[LIM],int color[],int source)
    {
        color[source] = 1;//1 -> red
        queue<int> q;
        q.push(source);


        while(q.size())
        {
            int u = q.front();
            q.pop();

            for(int i=0;i<G[u].size();i++)
            {
                int v= G[u][i];

                if(!color[v])//means the node has now no color/white color
                {
                    if(color[u] == 1)//previous node is red
                         color[v] = 2;//2 -> blue

                    else color[v] = 1;//red

                    q.push(v);
                }

                if(color[u] == color[v])//means a cycle found
                    return false;
            }
        }

        return true;


    }

int main()
{
    int t,n,e,a,b;
    int color[LIM];//0 -> white
    vector<int> G[LIM];

    cin>>t;

    while(t--)
    {
        cin>> n >> e;

        memset(color,0,sizeof color);
        for(int u=1; u<=n; u++) G[u].clear();//1 based graph

        for(int i=0;i<e;i++)
        {
            cin>> a >> b;
            G[a].push_back(b);
        }

        int source =1;

        if(bfs_bicolorable(G,color,source)) cout<<"the graph is bicolorable."<<endl;
        else cout<<"the graph is not bicolorable."<<endl;


    }
}

/*
2
5 5
1 2
1 3
2 4
3 5
4 5

6 6
1 2
1 3
2 4
3 5
4 6
5 6
*/

