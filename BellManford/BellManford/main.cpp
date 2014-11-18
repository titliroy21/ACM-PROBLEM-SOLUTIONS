/*

Negative Cycle calculation

*/

#include <set>
#include <map>
#include <list>
#include <cmath>
#include <ctime>
#include <queue>
#include <stack>
#include <cctype>
#include <cstdio>
#include <string>
#include <vector>
#include <cassert>
#include <cstdlib>
#include <cstring>
#include <sstream>
#include <iostream>
#include <algorithm>


using namespace std;
#define READ(x)  freopen(x, "r", stdin)
#define WRITE(x)  freopen(x, "w", stdout)
#define MAX_NODE 100
#define INF 999999
vector<int> dist;
int parr[MAX_NODE];
int mstCost;
int N,E,u,v,w;
typedef struct
{
    int u, v;
    int w;
} Edge;
vector<Edge> edges;
/*
void bellmanford(int src)
{
    dist = vector<int> (N,INF);
    dist[src] = 0;
    for(int i =1;i<N;i++)
        for(int j = 0;j<edges.size();j++)
        {
            if(dist[edges[j].v]>dist[edges[j].v]+edges[j].w)
            dist[edges[j].v] = dist[edges[j].v]+dist[edges[j].w];

        }
}
*/

bool bellmanford(int src)
{
    dist = vector<int> (N,INF);
    dist[src] = 0;
    for(int i =1; i<N; i++)
        for(int j = 0; j<edges.size(); j++)
        {
            if(dist[edges[j].v] > dist[edges[j].u] + edges[j].w)
            {
                dist[edges[j].v] = dist[edges[j].u] + edges[j].w;
            }
            //  if(dist[edges[j].v] > dist[edges[j].u] + edges[j].w) return false;
            //  else return true;
        }

    for(int i =1; i<N; i++)
        for(int j = 0; j<edges.size(); j++)
        {
            if(dist[edges[j].v] > dist[edges[j].u] + edges[j].w) return false;
            else return true;
        }
}
int main()
{
    READ("input.txt");
    WRITE("output.txt");

    while(cin>>N>>E)
    {
        edges = vector<Edge> ( E );
        for(int i = 0 ; i<E; i++)
        {
            cin>>u>>v>>w;
            //  e.u = u;e.v = v;e.w =w
            // edges.push_back(e)
            edges[i].u = u;
            edges[i].v = v;
            edges[i].w = w;
        }
        bool neg =  bellmanford(0);
        if(neg) cout<<"true"<<endl;
        else cout<<"false"<<endl;
        for(int i = 0; i<N; i++)
            cout<<dist[i]<<" ";
    }

    return 0;
}
