#include<cstdio>
#include<sstream>
#include<cstdlib>
#include<cctype>
#include<cmath>
#include<algorithm>
#include<set>
#include<queue>
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
 
using namespace std;
 
#define eps 0.0000000001
#define pr pair<int,int>
#define mp make_pair
#define ss second
#define fi first
#define i64 long long
#define nl printf("\n")
#define pb(x) push_back(x)
#define all(x) x.begin(),x.end()
#define Find(x,n) find(all(x),n)
#define mset(x,v) memset(x,v,sizeof(x))
#define sc(n) scanf("%d",&n)
#define filein freopen("in.txt","r",stdin)
#define fileout freopen("my.txt","w",stdout)
#define REP(i,n) for(int i=0;i<n; i++)
#define FOR(i,k,n) for(int i=k;i<=n; i++)
#define fr(i,k,n) for(int i=k;i<n; i++)
#define MAX 30005
#define inf 2000000000
#define MOD 100000000
 
template<class T>T sq(T a){ return (a*a); }
template<class T>T gcd(T a,T b){ return b==0 ? a : gcd(b,a%b); }
template<class T>T lcm(T a,T b){ return (a/gcd(a,b))*b; }
template<class T>bool isPrime(T n){ for(T i=2; i*i<=n; i++){ if(n%i==0) return false; } return true; }
 
struct edge
{
    int u;
    i64 w;
    edge(int u,i64 w){ this->u=u; this->w=w; }
};
 
i64 mx;
int V;
int visited[MAX];
vector<edge>g[MAX];
 
void dfs(int u,i64 w){
    visited[u]=1;
    int sz=g[u].size();
    if(w>mx){
        mx=w;
        V=u;
    }
    REP(i,sz){
        int v=g[u][i].u;
        if(!visited[v]){
            dfs(v,w+g[u][i].w);
        }
    }
}
 
int main()
{
   // filein;
 
    int t,T=0;
    sc(t);
    while(t--){
        int n;
        sc(n);
        REP(i,n-1){
            int u,v;
            i64 w;
            scanf("%d %d %lld",&u,&v,&w);
            g[u].pb( edge(v,w) );
            g[v].pb( edge(u,w) );
           visited[i]=0;
        }
        visited[n-1]=0;
        mx=0; 
        dfs(0,0);
        mx=0;
        REP(i,n) visited[i]=0;
        dfs(V,0);
        printf("Case %d: %lld\n",++T,mx);
        REP(i,n) g[i].clear();
    }
    return 0;
}
