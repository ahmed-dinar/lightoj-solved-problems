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
#define MAX 5005
#define inf 2000000000
#define MOD 100000000
 
template<class T>T sq(T a){ return (a*a); }
template<class T>T gcd(T a,T b){ return b==0 ? a : gcd(b,a%b); }
template<class T>T lcm(T a,T b){ return (a/gcd(a,b))*b; }
template<class T>bool isPrime(T n){ for(T i=2; i*i<=n; i++){ if(n%i==0) return false; } return true; }
 
struct edge
{
    int v,w;
    edge(int v,int w) { this->v=v; this->w=w; }
};
 
struct node
{
    int u,w,id;
    node(int u,int w,int id) { this->u=u; this->w=w; this->id=id; }
    bool operator<( const node& p) const { return w > p.w; }
};
 
vector<edge>g[MAX];
 
int  Dijkstra(int n){
    int vi[n+1];
    int vi2[n+1];
    int d[n+1];
    int d2[n+1];
    FOR(i,1,n) d[i]=inf,d2[i]=inf,vi[i]=0,vi2[i]=0;
    priority_queue<node>q;
    q.push( node(1,0,0) );
    d[1]=0;
    while(!q.empty()){
        int u = q.top().u;
        int id = q.top().id;
        q.pop();
 
        if( id==0 && vi[u] )
            continue;
        else if( id==1 && vi2[u] )
            continue;
        else if( id==0 )
            vi[u]=1;
        else if(id==1)
            vi2[u]=1;
 
        int sz=g[u].size();
        REP(i,sz){
            int v = g[u][i].v;
            int w = g[u][i].w;
 
            if(id==0) w+=d[u];
            else w+=d2[u];
 
            if( d[v] > w ){
                //cout << u << " to " << v << "  " << w << " f= " << d[v] << "  s= " << d2[v] <<  endl;
                d2[v] = d[v];
                d[v] = w;
                q.push( node(v,d[v],0) );
                q.push( node(v,d2[v],1) );
            }
            else if( d2[v] > w && w != d[v] ){
                d2[v] = w;
                q.push( node(v,d2[v],1) );
            }
        }
    }
    //cout << "Best = " << d[n] << " & second Best = " << d2[n] << endl;
    return d2[n];
}
 
int main()
{
    //filein;
    //fileout;
 
    int t,T=0;
    sc(t);
    while(t--){
        int n,m;
        scanf("%d %d",&n,&m);
        while(m--){
            int u,v,w;
            scanf("%d %d %d",&u,&v,&w);
            g[u].pb( edge(v,w) );
            g[v].pb( edge(u,w) );
        }
        printf("Case %d: %d\n",++T,Dijkstra(n));
        FOR(i,1,n) g[i].clear();
    }
    return 0;
}
 
 
