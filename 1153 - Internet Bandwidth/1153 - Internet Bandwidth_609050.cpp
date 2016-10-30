 
#include<cstdio>
#include<sstream>
#include<cstdlib>
#include<cctype>
#include<cmath>
#include<algorithm>
#include<set>
#include<queue>
#include<deque>
#include<stack>
#include<list>
#include<iostream>
#include<fstream>
#include<numeric>
#include<string>
#include<vector>
#include<cstring>
#include<map>
#include<iterator>
#include<limits>
 
using namespace std;
 
#define filein       freopen("in.txt","r",stdin)
#define fileout      freopen("out2.txt","w",stdout)
 
#define MS(x,v)      memset(&x,v,sizeof(x))
#define CL(x)        memset(&x,0,sizeof(x))
#define mp           make_pair
#define pb           push_back
#define sz           size()
#define cl           clear()
#define ss           second
#define fi           first
 
#define vanish       scanf("\n")
#define nl           puts("")
#define endl         '\n'
#define i64          long long
#define all(x)       x.begin(),x.end()
 
#define Iterate(s)   for(typeof(s.begin()) it = s.begin(); it != s.end(); it++)
#define FOR(i,k,n)   for(__typeof(n) i = (k); i <= (n); ++i)
#define For(i,k,n)   for(__typeof(n) i = (k); i < (n); ++i)
#define ROF(i,k,n)   for(__typeof(n) i = k; i >= n; i--)
#define REP(i,n)     for(__typeof(n) i = 0; i < (n); ++i)
#define sq(x)        (x*x)
 
#define EPS          0.0000001
#define MAX          105
#define oo           1000000
#define MOD          1000000007
 
#define PI           acos(-1.0)
 
 
int n;
int c[MAX][MAX];
int par[MAX],vis[MAX];
vector<int>g[MAX];
 
int bfs(int s,int d){
    queue<int>q;
 
    FOR(i,1,n) vis[i] = 0;
 
    q.push(s);
    vis[s] = 1;
    par[s] = s;
    while(!q.empty()){
        int u = q.front();
        q.pop();
 
        REP(i,g[u].sz){
            int v = g[u][i];
            if( !vis[v] && c[u][v] > 0 ){
                par[v] = u;
                vis[v] = 1;
                q.push(v);
            }
        }
    }
    return vis[d];
}
 
int mf(int s,int d){
    int mxFlow = 0;
    while( bfs(s,d) ){
        int flow = oo;
        int v = d,u;
        while( par[v] != v ){
            u = par[v];
            flow = min(flow,c[u][v]);
            v = u;
        }
        v=d;
        while( par[v] != v ){
            u = par[v];
            c[u][v] -= flow;
            c[v][u] += flow;
            v = u;
        }
        mxFlow += flow;
    }
    return mxFlow;
}
 
int main(){
  //  ios_base::sync_with_stdio(0); cin.tie(0);
 
    //filein;
    //fileout;
 
 
    int t,T=0;
    scanf("%d",&t);
    while(t--){
        int s,d,m;
        scanf("%d",&n);
        scanf("%d %d %d",&s,&d,&m);
 
        FOR(i,1,n){
            g[i].cl;
            FOR(j,1,n) c[i][j] = 0;
        }
 
        while(m--){
            int u,v,cost;
            scanf("%d %d %d",&u,&v,&cost);
            c[u][v] += cost;
            c[v][u] += cost;
            g[u].pb(v);
            g[v].pb(u);
        }
 
 
        printf("Case %d: %d\n",++T,mf(s,d));
 
    }
    return 0;
}
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
