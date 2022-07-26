#include<bits/stdc++.h>
using namespace std;

#define INF 1000000000

int main()
{
    int n,e,i,j,k,a,b,c;
    int adjmatrix[100][100];

    cin>>n >>e;//nodes and edges

    for(i=1;i<=n;i++)//1 based graph
        for(j=1;j<=n;j++)
    {
        adjmatrix[i][j] = INF;

        adjmatrix[i][i] = 0; //making same node cost 0 and node to node cost is INF//this line should be always after previous line

    }

    for(i=0;i<e;i++)
    {
        cin>> a >> b >> c;//edges and cost
        adjmatrix[a][b] = c;
    }

    for(k=1;k<=n;k++)
        for(i=1;i<=n;i++)
            for(j=1;j<=n;j++)
                {
                    if(adjmatrix[i][k] == INF || adjmatrix[k][j] == INF) continue;//we can't travel through edge that doesn't exist;(optimization)

                    adjmatrix[i][j] = min(adjmatrix[i][j], adjmatrix[i][k] + adjmatrix[k][j]);
                }

    for(i=1;i<=n;i++)
        for(j=1;j<=n;j++)
        {
            cout<<"shortest path from "<<i<<" to "<<j <<" is "<< adjmatrix[i][j]<<endl;
        }

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
