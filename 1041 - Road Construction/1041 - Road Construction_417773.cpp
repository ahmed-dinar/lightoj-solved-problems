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
#define inf 2147483646
 
 
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
 
struct E
{
    int v,u,w;
    E(int U,int V,int W) { u=U; v=V; w=W; }
    bool operator < ( const E& p) const { return w > p.w; }
};
 
priority_queue<E>q;
map<string,int>city;
int par[52];
 
int parent(int x){
    return (par[x]==x) ? x : parent(par[x]);
}
 
int mst(int n){
    int total=0,res=0;
    while(!q.empty()){
        E e=q.top();
        q.pop();
       // if(e.w==0) continue;
        int u=parent(e.u);
        int v=parent(e.v);
        if(u!=v){
            par[u]=v;
            total++;
            res += e.w;
            if(total==n-1){
                return res;
            }
        }
    }
    return -1;
}
 
int main()
{
    //filein;
 
    int t;
    sc(t);
    for(int T=1;T<=t;T++){
        int n,index=0;
        sc(n);
        for(int i=0;i<n;i++){
            string u,v;
            int w;
            cin >> u >> v >> w ;
            if(city[u]==0){
                city[u]=++index;
            }
            if(city[v]==0){
                city[v]=++index;
            }
            q.push( E(city[u],city[v],w) );
            par[city[u]]=city[u];
            par[city[v]]=city[v];
        }
        int res = mst(index);
 
        printf("Case %d: ",T);
 
        (res==-1) ? printf("Impossible\n") : printf("%d\n",res);
 
        while(!q.empty()) q.pop();
        city.clear();
    }
    return 0;
}
 
 
