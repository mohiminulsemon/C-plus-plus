
#include<bits/stdc++.h>
#define LIM 10005//probably this is the highest for array of vectors
using namespace std;

int cycle_count=0;

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

//int previous[LIM];
//int black=1,white=0;//white for which node is in recursion/processing && black is which node processing is finished
//bool color[LIM];
//void dfs(vector<int> G[],bool vis[],int u)//cycle finding for undirected graph
//{
//    cout<<" "<<u;
//
//    vis[u]=true;
//
//    color[u]=white;
//
//    int v;
//
//
//    for(int i=0 ; i<G[u].size() ; i++)
//    {
//        v = G[u][i];
//
//        if(v == previous[u]) continue;
//
//        if(!vis[v]){
//
//            previous[v] = u;
//            dfs(G,vis,v);
//        }
//
//        else if(color[v] == white) cycle_count++;
//    }
//
//    color[u]=black;
//
//
//
//}

void dfs(vector<int> G[],bool vis[],int u)//recursive procedure
{
    cout<<" "<<u;

    vis[u]=true;

    int v,previous;

    previous = u;

    for(int i=0 ; i<G[u].size() ; i++)
    {
        v = G[u][i];

        if(!vis[v])
            dfs(G,vis,v);

        else if(previous != v) cycle_count++;
    }



}

int main()
{
    int t,n,m,u,v,i;
    vector<int> G[LIM];//array of vectors//It means G[0] , G[1] , …. G[99] all are vectors.//mainly used for making adjacency list
                        //if row and column are known than we can use vector<vector<int> > ;
    bool visited[LIM];
    cin>> t;
    while(t--)
    {
        cin>> n >> m;//number of nodes and set of edges

        memset(visited,0,sizeof(visited));
        for(int u=1; u<=n; u++) G[u].clear();//for clearing previous vector

        for(i=0;i<m;i++)
        {
            cin>> u >> v;
            G[u].push_back(v);
            //G[v].push_back(u);//for undirected graph use this line too
        }

        display_graph(G,n);

        int components=0;

        for(i=1;i<=n;i++)
        {
            if(!visited[i])
            {
                cout<<"components: "<< ++components <<"=";
                dfs(G,visited,i);
                cout<<endl;
            }
        }
        cout<<"there are "<<components<<" connected components."<<endl;
        cout<<"there are "<<cycle_count<<" cycle in the graph."<<endl;

    }
}

/*
1
12 15
1 2
1 4
2 5
2 3
3 6
4 7
4 5
5 8
5 6
6 8
7 8
9 10
10 11
11 12
12 9
*/

