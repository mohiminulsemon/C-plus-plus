#include<bits/stdc++.h>
using namespace std;

#define INF 1000000000

vector<int> constractpath(int u,int v,int next[][100])//1st bracket value is optional but 2nd bracket value is required;
{
    if(next[u][v] == INF) return {};//empty array
    vector<int> path={u};
    while(u!=v)
    {
        u = next[u][v];
        path.push_back(u);
    }
    return path;
}


int main()
{
    int n,e,i,j,k,a,b,c;
    int adjmatrix[100][100];
    int next[100][100];//for finding path
    vector<int> path;

    cin>>n >>e;//nodes and edges

    for(i=1;i<=n;i++)//1 based graph
        for(j=1;j<=n;j++)
    {
        adjmatrix[i][j] = INF;

        next[i][j] = INF;

        adjmatrix[i][i] = 0; //making same node cost 0 and node to node cost is INF//this line should be always after previous line

    }

    for(i=0;i<e;i++)
    {
        cin>> a >> b >> c;//edges and cost

        adjmatrix[a][b] = c;

        next[a][b] = b;
    }

    for(k=1;k<=n;k++)
        for(i=1;i<=n;i++)
            for(j=1;j<=n;j++)
                {
                    if(adjmatrix[i][k] == INF || adjmatrix[k][j] == INF) continue;

                    if(adjmatrix[i][j] > adjmatrix[i][k] + adjmatrix[k][j])
                    {
                        adjmatrix[i][j] = adjmatrix[i][k] + adjmatrix[k][j];
                        next[i][j] = k;
                    }
                }


    //finding paths between 2 nodes;
    int u,v,flag = 0;
    u=1;
    v=3;


//    if(next[u][v] == INF)
//    {
//        cout<<"there is no path between "<<u<<" and "<<v<<endl;
//        flag=1;
//    }
//
//    path = {u};
//
//    while(u != v && flag==0)
//    {
//        u = next[u][v];
//
//        path.push_back(u);
//    }

    path = constractpath(u,v,next);

    int size = path.size();

    if(size == 0) cout<<"there is no path between "<<u<<" and "<<v<<endl;

    for(i=0; i< size-1; i++)
    {
        cout<<path[i]<<" -> ";
    }
    cout<<path[size-1]<<endl;
}

/*
4 6
1 2 3
2 1 2
4 1 20
4 3 8
3 2 5
2 3 2
*/
