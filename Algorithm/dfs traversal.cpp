#include<bits/stdc++.h>
#define LIM 10000//this is the highest for array of vectors/node numbers
using namespace std;


template <typename T>
void display_graph(vector<T> v[],int n)
{
    for(int i=1;i<=n ;i++)//if node start from 1 than i=1;
    {
        cout<<i<<"->";
        for(auto j : v[i]) cout<<j<<" ";
        cout<<endl;
    }
    cout<<endl<<endl;
}

void dfs(vector<int> G[],vector<bool> vis,int u)//recursive procedure//vector<int> (&G)[LIM] for call by reference of array of vectors
{
    cout<<"In -> "<<u<<endl;
    //getchar();//for debugging,press enter in output to debug line by line

    vis[u]=true;

    int v;

    for(int i=0 ; i<G[u].size() ; i++)
    {
        v = G[u][i];

        if(!vis[v])
            dfs(G,vis,v);
    }

    cout<<"out -> "<<u<<" (cause "<<v<<" already visited)"<<endl;
    //getchar();
}

int main()
{
    int t,n,m,u,v,i;
    vector<int> G[LIM];//array of vectors//It means G[0] , G[1] , …. G[99] all are vectors.//mainly used for making adjacency list
                        //if row and column are known than we can use vector<vector<int> > ;
    vector<bool> visited;
    cin>> t;
    while(t--)
    {
        cin>> n >> m;//number of nodes and set of edges

        visited.assign(n,false);
        for(int u=1; u<=n; u++) G[u].clear();//for clearing previous vector

        for(i=0;i<m;i++)
        {
            cin>> u >> v;
            G[u].push_back(v);
            //G[v].push_back(u);for undirected graph use this line too
        }

        display_graph(G,n);

        int source=1;
        dfs(G,visited,source);



    }
}

/**
1
11 13
1 2
2 3
3 4
4 5
5 2
2 7
7 6
6 9
9 10
10 7
10 11
11 8
8 7
*/
