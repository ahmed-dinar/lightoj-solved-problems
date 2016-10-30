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
 
 
struct MX
{
    int v,u,w;
    MX(int U,int V,int W) { u=U; v=V; w=W; }
    bool operator < ( const MX& p) const { return w > p.w; }
};
 
struct MN
{
    int v,u,w;
    MN(int U,int V,int W) { u=U; v=V; w=W; }
    bool operator < ( const MN& p) const { return w < p.w; }
};
 
priority_queue<MX>maximum;
priority_queue<MN>minimum;
int maxp[102];
int minp[102];
 
int max_parent(int x){
    return (maxp[x]==x) ? x : max_parent(maxp[x]);
}
 
int min_parent(int x){
    return (minp[x]==x) ? x : min_parent(minp[x]);
}
 
int min_mst(int n){
    int total=0,cost=0;
    while(!maximum.empty()){
        MX m=maximum.top();
        maximum.pop();
        int u = max_parent(m.u);
        int v = max_parent(m.v);
        if(u!=v){
            maxp[u]=v;
            cost += m.w;
            total++;
            if(total==n) break;
        }
    }
    return cost;
}
 
int max_mst(int n){
    int total=0,cost=0;
    while(!minimum.empty()){
        MN m=minimum.top();
        minimum.pop();
        int u = min_parent(m.u);
        int v = min_parent(m.v);
        if(u!=v){
            minp[u]=v;
            cost += m.w;
            total++;
            if(total==n) break;
        }
    }
    return cost;
}
 
int main()
{
    
 
    int t;
    sc(t);
    for(int T=1;T<=t;T++){
        int n,u,v,w;
        sc(n);
        while(scanf("%d %d %d",&u,&v,&w)==3){
            if(u==0 && v==0 && w==0) break;
 
            maximum.push(MX(u,v,w));
 
            minimum.push(MN(u,v,w));
 
            maxp[u]=u;
            maxp[v]=v;
            minp[u]=u;
            minp[v]=v;
        }
        int res = max_mst(n)+min_mst(n);
 
        printf("Case %d: ",T);
 
        isEven(res) ? printf("%d\n",res/2) : printf("%d/%d\n",res,2);
 
        while(!minimum.empty()) minimum.pop();
        while(!maximum.empty()) maximum.pop();
    }
    return 0;
}
 
 
