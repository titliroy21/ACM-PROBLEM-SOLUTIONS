/*

Minimum Spanning TREE Calculation

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
int parr[MAX_NODE];
int mstCost;
int N,E,u,v,w;
typedef struct {
    int u, v;
    int w;
} Edge;
vector<Edge> edges,mstEdge;


void initSet()
{
    for(int i = 0;i<=MAX_NODE;i++)
    {
        parr[i] = i;
    }


}

int Find(int x)
{
     if (parr[x]!= x)
        parr[x] = Find(parr[x]);
     return parr[x];
}

void Union(int x,int y){
    int xRoot,yRoot;
     xRoot = Find( x );
     yRoot = Find( y );
     parr[xRoot]= yRoot;
     //parr[Find(x)] = find(y) this line can be written instead of those 4 line
}
bool compare (Edge i,Edge j) { return (i.w<j.w); } //used for ascending or descending ordering

void kruskal()
{
    initSet();
    mstCost = 0;
   sort(edges.begin(),edges.end(),compare);
   for( int i = 0;i<edges.size();i++)
   {
       if(Find(edges[i].u)!=Find(edges[i].v))
          {
              mstCost+=edges[i].w;
               Union(edges[i].u,edges[i].v);
               mstEdge.push_back(edges[i]);
          }


   }

}
int main()
{
   // READ("input.txt");
   // WRITE("output.txt");

    while(cin>>N>>E)
    {
        edges = vector<Edge> ( E );
        for(int i = 0 ; i<E;i++)
        {
            cin>>u>>v>>w;
          //  e.u = u;e.v = v;e.w =wNo
           // edges.push_back(e)
            edges[i].u = u;
            edges[i].v = v;
            edges[i].w = w;
        }
        kruskal();
         for(int i =0;i<mstEdge.size();i++)
        cout<<mstEdge[i].u<<" "<<mstEdge[i].v<<" "<<mstEdge[i].w<<endl;
        cout<<"Cost :"<<mstCost<<endl;
    }

    return 0;
}

/* Sample Input

5 7
0 1 4
0 2 4
0 3 6
0 4 6
1 2 2
2 3 8
3 4 9


Sample output

1 2 2
0 1 4
0 3 6
0 4 6
Cost :18


*/


