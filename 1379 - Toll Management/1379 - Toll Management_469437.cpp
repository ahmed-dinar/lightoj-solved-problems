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
 
using namespace std;
 
#define filein freopen("in.txt","r",stdin)
#define fileout freopen("out.txt","w",stdout)
 
#define cs(x) printf("Case %d: ",++x)
#define csh(x) printf("Case #%d: ",++x)
#define csn(x) printf("Case %d:\n",++x)
#define loc(p) puts(p)
 
#define nFind(v,n) find(all(v),n)==v.end()
#define Find(v,n) find(all(v),n)!=v.end()
#define all(x) x.begin(),x.end()
#define toDigit(x) (x-'0')
#define MS(x,v) memset(&x,v,sizeof(x))
#define CL(x) memset(&x,0,sizeof(x))
#define mp make_pair
#define pb push_back
#define sz size()
#define cl clear()
#define pp pop()
#define em empty()
#define ss second
#define fi first
 
#define sc1(n) scanf("%d",&n)
#define sc2(n,m) scanf("%d %d",&n,&m)
#define sc3(n,m,v) scanf("%d %d %d",&n,&m,&v)
#define vanish scanf("\n")
#define nl puts("")
 
#define Iterate(s) for(typeof(s.begin()) it = s.begin(); it != s.end (); it++)
#define FOR(i,k,n) for(__typeof(n) i = (k); i <= (n); ++i)
#define For(i,k,n) for(__typeof(n) i = (k); i < (n); ++i)
#define ROF(i,n) for(__typeof(n) i = n; i >= 0; i--)
#define REP(i,n) for(__typeof(n) i = 0; i < (n); ++i)
 
#define check(n,pos) (bool)(n & (1<<(pos)))
 
#define EPS 1e-7
#define PI acos(-1.0)
#define MAX 10002
#define oo 10000000000
#define MOD 1000000007
 
typedef long long i64;
typedef unsigned long long ui64;
typedef pair<int,int> pri;
typedef pair<i64,i64> pri64;
typedef vector<int> vci;
typedef vector<string> vcs;
typedef vector<i64> vci64;
typedef vector<pri> vcp;
 
int on(int N,int pos){ int m=(N | (1<<pos)); return m; }
int off(int N,int pos){ int m=(N & ~(1<<pos)); return m; }
template<class T>string toString(T n){ stringstream ss; string num; ss<<n; ss>>num; return num; }
template<class T>bool iseq(T a,T b){return abs(a-b)<EPS;}
template<class T>T sq(T a){ return (a*a); }
template<class T>T gcd(T a,T b){ return (b==0) ? a : gcd(b,a%b); }
template<class T>T lcm(T a,T b){ return (a/gcd(a,b))*b; }
template<class T>T Pow(T n,T p){ if(p==0) return 1; if(p&1) return n*Pow(n,p-1);  else return sq(Pow(n,p/2));}
template<class T>bool isPrime(T n){ for(T i=2; i*i<=n; i++){ if(n%i==0) return false; } return true; }
template<class T>T bMod(T A,T P,T M){ if(P==0) return (T)1; if(!(P&1)){T temp=bMod(A,P/2); return ((temp%M)*(temp%M))%M; } return ((A%M)*(bMod(A,P-1)%M))%M; }
template<class T>inline void IO(T &x){ char c=getchar(); T sgn=1; while(c<'0'|| c>'9'){ if(c=='-') sgn=-1; c=getchar();} x=0;while(c>='0'&&c<='9'){x=(T)(x<<1)+(x<<3)+c-'0';c=getchar();}x*=sgn;}
template<class T>T InMod(T A,T M){return bMod(A,M-2,M);}
template<class T>T todeg(T x) { return (180.0*x)/((T)PI);}
template<class T>T torad(T x) { return (x*(T)PI)/(180.0);}
template<class T>T _distance(T x1,T y1,T x2, T y2){return sqrt(sq(x1-x2)+sq(y1-y2));}
 
struct node
{
    int v; i64 uv;
    node(int v,i64 uv) : v(v),uv(uv){}
    bool operator<(const node& k)const{ return uv<k.uv; }
};
 
vector<node>g[MAX],gr[MAX];
int d[MAX],dr[MAX],vis[MAX];
 
bool Dijkstra(int u,int n){
    priority_queue<node>q;
    q.push( node(u,0) );
    d[u]=0;
    while(!q.em){
        u=q.top().v; q.pp;
 
 
 
        REP(i,g[u].sz){
            int v=g[u][i].v;
            i64 uv=g[u][i].uv;
            if( d[v]>uv+d[u] ){
                d[v]=uv+d[u];
                q.push( node(v,d[v]) );
            }
        }
    }
    return (d[n]!=oo);
}
 
void Dijkstra2(int u,int n){
    FOR(i,1,n) vis[i]=0;
    priority_queue<node>q;
    q.push( node(u,0) );
    dr[u]=0;
    while(!q.em){
        u=q.top().v; q.pp;
 
 
 
        REP(i,gr[u].sz){
            int v=gr[u][i].v;
            i64 uv=gr[u][i].uv;
            if( dr[v]>uv+dr[u] ){
                dr[v]=uv+dr[u];
                q.push( node(v,dr[v]) );
            }
        }
    }
}
 
void init(int n){
    FOR(i,1,n){
        g[i].cl;
        gr[i].cl;
        d[i]=dr[i]=(i64)oo;
        vis[i]=0;
    }
}
 
int main(){
 
  
 
    int t,T=0;
    IO(t);
    while(t--){
        int n,m,s,to,u,v;
        i64 p,ans=-1,uv;
 
        IO(n); IO(m); IO(s); IO(to); IO(p);
 
        init(n);
 
        while(m--){
            IO(u); IO(v); IO(uv);
            g[u].pb( node(v,uv) );
            gr[v].pb( node(u,uv) );
        }
 
        if( Dijkstra(s,n) ){
 
            Dijkstra2(to,n);
 
            FOR(i,1,n){
                REP(j,g[i].sz){
                    v=g[i][j].v;
                    uv=g[i][j].uv;
 
                    if( (d[i]+uv+dr[v]) <=p ) ans=max(ans,uv);
 
                }
            }
        }
 
        printf("Case %d: %lld\n",++T,ans);
 
    }
    return 0;
}
 
