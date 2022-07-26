#include<bits/stdc++.h>
using namespace std;

#define MAX 10000
#define INF 1<<30

void display_graph(vector<pair<int,int> > v[],int n)
{
    for(int i=1;i<=n ;i++)//if node start from 1 than i=1;
    {
        cout<<i<<"->";
        for(auto j : v[i]) cout<<"("<<j.first<<","<<j.second<<") ";
        cout<<endl;
    }
    cout<<endl<<endl;
}

struct comp{
    bool operator() (const pair<int,int> &a,const pair<int,int> &b){
    return a.second > b.second;}//for min heap and a.second < b.second for max heap
                                //if true the greater value will be in the stack as in top of the stack we get the smaller value
};

//priority_queue<pair<int,int> > q ---> max heap means the largest number will in the front(ordered by 1st of pair element)
//priority_queue<pair<int,int>,vector<pair<int,int> >,greater<pair<int,int> > > q; ---> min heap(ordered by 1st)


void dijkstra(vector<pair<int,int> > G[],vector<int> &dis,vector<int> &pre,int n)
{
    priority_queue<pair<int,int>,vector<pair<int,int> >,comp > q;//min heap and ordered by second
    dis[n] = 0;
    pre[n] = 0;
    q.push({n,0});

    bool visited[MAX]={0};//use this for undirected graph

    while(!q.empty())
    {
        int u = q.top().first;
        q.pop();

        if(visited[u]) continue;
        else visited[u] = 1;

        int size = G[u].size();
        for(int i=0;i<size;i++)
        {
           int v = G[u][i].first;//node
           int c = G[u][i].second;//cost
           if(!visited[v] && dis[v]> dis[u] + c)//we can use dis[v] = min(dis[v],dis[u]+c) instead of if(dis[v] > dis[u]+ c) dis[v] = dis[u] + c;
           {
               pre[v] = dis[v];
               dis[v] = dis[u] + c;
               q.push({v,dis[v]});
           }
        }
    }
}

int main()
{
    int t,n,e,a,b,c;
    vector<pair<int,int> > G[MAX];
    vector<int>distance,previous;

    cin>>t;

    while(t--)
    {
        cin>> n >> e;//nodes and edges

        distance.assign(n+1,INF);//adding 1 as it is 0 based but we have 1 based graph
        previous.assign(n+1,INF);

        for(int u=1; u<=n; u++) G[u].clear();//1 based graph

        for(int i=0;i<e;i++)
        {
            cin>> a >> b >> c;//edge(a,b) and cost(c)

            G[a].push_back(make_pair(b,c));
            G[b].push_back(make_pair(a,c));

            //or
            //G[a].push_back({b,c});
            //or
            //G[a].push_back(pair<int,int>(b,c));
        }

        display_graph(G,n);

        int source=3;

        dijkstra(G,distance,previous,source);

        for(int i=1; i<=n; i++)
        {
            cout<<"distance from "<< source <<" to " <<i<<" is " <<distance[i]<<" and 2nd shortest path is "<<previous[i]<<endl;
        }
    }
}
/*
1
4 4
1 2 2
1 3 5
2 3 1
3 4 3
*/
