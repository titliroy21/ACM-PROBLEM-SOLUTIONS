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
#define WHITE 0
#define GRAY 1
#define BLACK 2
vector<int> dist,parent;
vector<char> color;
vector<vector<int> > graph;
vector<int> path;
vector<int> total_path;
int N,E;
void BFS(int source)
{
    int u, v;
    queue<int> Q;

    dist = vector<int>(MAX_NODE);
    color = vector<char>(MAX_NODE);
    parent = vector<int>(MAX_NODE);

    Q.push(source);
   // total_path.push_back(source);
    dist[source] = 0;
    parent[source] = -1;
    color[source] = GRAY;

    while( !Q.empty() ) {
        u = Q.front(); Q.pop();
          total_path.push_back(u);
        for(int i = 0;i<=graph[u].size()-1;i++) {
            v = graph[u][i];
            if(color[v] == WHITE) {
                color[v] = GRAY;
                dist[v] = dist[u] + 1;
                parent[v] = u;
                Q.push(v);

            }
        }
        color[u] = BLACK;


    }

    for(int i = 0;i<graph[u].size()-1;i++)
        cout<<i<<" : "<<parent[i]<<endl;

}
void ShowTraversalPath()
{
    for(int i = 0;i<total_path.size();i++)
    {
        cout<<total_path[i]<<" ";
    }
}

void ShowPathEdgeVisited()
{
    for(int i = 0;i<N;i++){
        for(int j = 0;j<graph[i].size();j++)
        {
          cout<<"i : "<<i<<"->"<<graph[i][j]<<endl;
        }
    }
}

void MakePath(int sink)
{
    if(parent[sink] == -1) {
        path.push_back(sink);
        return;
    }

    MakePath(parent[sink]);
    path.push_back(sink);
}

void ShowPath()
{
    for(int i=0;i<path.size();i++)
        cout << path[i] << " ";
    cout << endl;
}


int main()
{
    READ("input.txt");
    WRITE("output.txt");
    int u,v;
   scanf("%d %d",&N,&E);
   graph = vector<vector<int> >( N );
   for(int i = 0;i<E;i++)
   {
       cin>>u>>v;
       graph[u].push_back(v);
       graph[v].push_back(u);
   }
    BFS(0);
    MakePath(3);
    ShowPath();
    ShowPathEdgeVisited();
    ShowTraversalPath();
    return 0;
}
