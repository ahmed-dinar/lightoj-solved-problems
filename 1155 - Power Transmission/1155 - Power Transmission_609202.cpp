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
#define MAX          210
#define oo           100000000LL
#define MOD          1000000007
 
#define PI           acos(-1.0)
 
 
int n,N;
i64 c[MAX][MAX];
int par[MAX],vis[MAX];
vector<int>g[MAX];
 
int bfs(int s,int d){
    queue<int>q;
 
    FOR(i,1,N) vis[i] = 0;
 
    q.push(s);
    vis[s] = 1;
    par[s] = s;
    while(!q.empty()){
        int u = q.front();
        q.pop();
 
        REP(i,g[u].sz){
            int v = g[u][i];
            if( !vis[v] && c[u][v] > 0LL ){
                par[v] = u;
                vis[v] = 1;
                q.push(v);
            }
        }
    }
    return vis[d];
}
 
i64 mf(int s,int d){
    i64 mxFlow = 0LL;
 
    while( bfs(s,d)  ){
        i64 flow = 100000000000000LL;
        int v = d,u;
       // cout << "----------------\n";
        while( par[v] != v ){
            u = par[v];
           // cout << u << "->" << v << " " << c[u][v] << endl;
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
 
 //   filein;
    //fileout;
 
 
    int t,T=0;
    scanf("%d",&t);
    while(t--){
        int m,u,v,B,D;
        i64 cost;
        scanf("%d",&n);
 
        N = 2*n + 2;
 
        FOR(i,1,N){
            g[i].cl;
            FOR(j,1,N) c[i][j] = 0LL;
        }
 
        FOR(i,1,n){
            scanf("%lld",&cost);
            u = i;
            v = n+u;
            g[u].pb(v);
            g[v].pb(u);
            c[u][v] = cost;
        }
 
        scanf("%d",&m);
        while(m--){
            scanf("%d %d %lld",&u,&v,&cost);
            c[n+u][v] = cost;
            g[n+u].pb(v);
            g[v].pb(n+u);
        }
 
        scanf("%d %d",&B,&D);
 
        u = N - 1;
        REP(i,B){
            scanf("%d",&v);
            c[u][v] = oo;
            g[u].pb(v);
        }
 
        v = N;
        REP(i,D){
            scanf("%d",&u);
            c[n+u][v] = oo;
            g[n+u].pb(v);
            g[v].pb(n+u);
        }
 
 
        u = N - 1;
        v = N;
        printf("Case %d: %lld\n",++T,mf(u,v));
 
    }
    return 0;
}
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
