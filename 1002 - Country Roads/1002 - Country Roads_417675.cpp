#include<bits/stdc++.h>
 
using namespace std;
 
#define all(x) x.begin(),x.end()
#define Find(x,n) find(all(x),n)
#define pi acos(-1.0)
#define i64 long long
#define pb(x) push_back(x)
#define mset(x,v) memset(x,v,sizeof(x))
#define sc(n) scanf("%d",&n)
#define scl(n) scanf("%ld",&n)
#define scll(n) scanf("%lld",&n)
#define scd(n,m) scanf("%d %d",&n,&m)
#define scdl(n,m) scanf("%ld %ld",&n,&m)
#define scdll(n,m) scanf("%lld %lld",&n,&m)
#define filein freopen("in.txt","r",stdin)
#define fileout freopen("my.txt","w",stdout)
#define FOR(i,n) for(int i=0;i<n; i++)
#define inf 2000000
 
 
bool isUpper(char ch){ if( ch>='A' && ch<='Z' ) return true; return false; }
bool isLower(char ch){ if( ch>='a' && ch<='z') return true; return false;}
bool isLetter(char ch){ if( ch>='A' && ch<='Z' || ch>='a' && ch<='z') return true; return false; }
bool isDigit(char ch){ if( ch>='0' && ch<='9') return true; return false; }
char toLower(char ch){ if (isUpper(ch)) return (ch+32); return ch; }
char toUpper(char ch){ if (isLower(ch)) return (ch-32); return ch; }
 
template<class T>bool isEven(T a){ return (a%2==0);}
template<class T>T sq(T a){ return a*a; }
template<class T>T gcd(T a,T b){ return b==0 ? a : gcd(b,a%b); }
template<class T>T lcm(T a,T b){ return (a/gcd(a,b))*b; }
template<class T>bool isPrime(T n){ for(T i=2; i*i<=n; i++){ if(n%i==0) return false; } return true; }
template<class T>T Pow(T n,T p) { T res=n; for(T i=1;i<p; i++){ res *= n; } return res; }
template<class T>T Max(T n,T p) { if(n>=p) return n; return p; }
 
 
 
struct path
{
    int v,w;
    path(int V,int W) { v=V; w=W; }
    bool operator < ( const path& p) const { return w < p.w; }
};
 
vector<vector<int> >g(502);
int cost[502][502];
int res[502];
 
 void djastra(int n,int src){
 
    for(int i=0;i<n;i++) res[i]=inf;
    priority_queue<path>q;
    q.push(path(src,0));
    res[src]=0;
    while(!q.empty()){
        path p=q.top();
        q.pop();
        int u=p.v;
        int sz=g[u].size();
        for(int i=0;i<sz;i++){
            int v=g[u][i];
            if(res[v]>Max(res[u],cost[u][v])){
                res[v]=Max(res[u],cost[u][v]);
                q.push(path(v,res[v]));
            }
        }
    }
 }
 
int main()
{
    //filein;
 
    int t;
    sc(t);
    for(int T=1;T<=t;T++){
        int n,m,d;
        scd(n,m);
 
        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)
                cost[i][j]=inf;
 
        for(int i=0;i<m;i++){
            int u,v,w;
            scanf("%d %d %d",&u,&v,&w);
            g[u].push_back(v);
            g[v].push_back(u);
            if(cost[u][v]>w){
                cost[u][v]=w;
                cost[v][u]=w;
            }
        }
        sc(d);
        djastra(n,d);
        printf("Case %d:\n",T);
        for(int i=0;i<n;i++){
            (res[i]==inf) ? printf("Impossible\n") : printf("%d\n",res[i]);
            g[i].clear();
        }
    }
    return 0;
}
 
 
