/*

 Sobar theke sobar min distance calculation

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
#define MAX_SIZE 20
#define INF 63
#define READ(x)  freopen(x, "r", stdin)
#define WRITE(x)  freopen(x, "w", stdout)
 int d[MAX_SIZE+1][MAX_SIZE+1];

 void floydwarshall()
 {
     for(int k = 1;k<=MAX_SIZE;k++)
        for(int i = 1;i<=MAX_SIZE;i++)
        for(int j = 1;j<=MAX_SIZE;j++)
     {
         d[i][j] = min(d[i][j],d[i][k]+d[k][j]);
     }
 }

int main()
{
   // READ("input.txt");
    //WRITE("output.txt");
    int i,j,k,p,m,n,t;
    int cnt,tc = 0;

    while(scanf("%d", &cnt) == 1) {

         tc++;
        memset(d,INF,sizeof(d));
        for(i = 1;i<= 20;i++) d[i][i] = 0;

        for(t = 1; t <= cnt; t++) {
            scanf("%d", &k);
            d[1][k] = d[k][1] = 1;
        }

        for(i = 2;i<= 19;i++)
        {
            scanf("%d", &j);
            for( int t = 1;t<=j;t++)
            {
                scanf("%d", &k);
                d[i][k] = d[k][i] = 1;
            }
        }

        floydwarshall();

        scanf("%d", &p);
        cout<<"Test Set #"<<tc<<endl;
        while(p--)
        {
            scanf("%d %d", &m, &n);
            printf("%2d to %2d: %d\n",m,n,d[m][n]);
        }
        cout<<endl;

    }


    return 0;
}
