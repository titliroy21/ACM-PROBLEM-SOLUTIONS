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
int t;
void DFS_VISIT(int u)
{
    cout << "Visiting " << u << endl;
    t = t+1;
    dist[u] = t;
    color[u] = GRAY;
    for(int i = 0;i<graph[u].size();i++)
    {
        int v =graph[u][i];
        if(color[v] ==WHITE)
        {
            parent[v] = u;
            DFS_VISIT(v);
        }
    }
    color[u] = BLACK;
    t = t +1;
}
void DFS()
{
    int u, v;
    t = 0;
    dist = vector<int>(MAX_NODE);
    color = vector<char>(MAX_NODE, WHITE);
    parent = vector<int>(MAX_NODE);

    for(int i = 0;i<N;i++) {
            if(color[i] == WHITE)
            {
                cout<<"starting : "<<i<<endl;
                DFS_VISIT(i);
            }
    }

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
    DFS();
    cout<<t<<endl;

    return 0;
}
