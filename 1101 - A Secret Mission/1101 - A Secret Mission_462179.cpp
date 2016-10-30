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
#include<ctime>
 
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
#define MAX 60005
#define oo 2000000000
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
    int u,v;
    i64 w;
    node(int u,int v,i64 w) : u(u),v(v),w(w) {}
    bool operator<(const node& p)const{ return w < p.w; }
};
 
vector<node>g;
vector<pair<int,i64> >adj[MAX];
int T[MAX],L[MAX],P[MAX][40];
i64 Q[MAX][40],A[MAX];
 
int parent(int x){
    return (T[x]==x) ? x : T[x]=parent(T[x]);
}
 
void mst(int n){
    sort(all(g));
    int nd=0;
    REP(i,g.sz){
        int u=parent(g[i].u);
        int v=parent(g[i].v);
        if(u!=v){
            T[u]=v;
            nd++;
            adj[u].pb( mp(v,g[i].w) );
            adj[v].pb( mp(u,g[i].w) );
            if(nd==n-1) return;
        }
    }
}
 
void dfs(int u,int p,int d,i64 D){
    L[u]=d;
    T[u]=p;
    A[u]=D;
    REP(i,adj[u].sz){
        int v=adj[u][i].fi;
        if(v!=p)
            dfs(v,u,d+1,adj[u][i].ss);
    }
}
 
void lca_init(int n){
    REP(i,n)
        for(int j=0; (1<<j)<n; j++)
            P[i][j]=-1;
 
    REP(i,n)
        P[i][0]=T[i],Q[i][0]=A[i];
 
    for(int j=1; (1<<j)<n; j++)
        REP(i,n)
            if(P[i][j-1]!=-1)
                P[i][j]=P[P[i][j-1]][j-1],Q[i][j]=max(Q[i][j-1],Q[P[i][j-1]][j-1]);
}
 
i64 LCA(int p,int q){
    int x;
 
    if(L[p]<L[q]) swap(p,q);
 
    for(x=1; (1<<x)<=L[p]; x++);
    --x;
 
    i64 ret=0;
    for(int i=x; i>=0; i--)
        if(L[p]-(1<<i)>=L[q])
            ret=max(ret, Q[p][i]),p=P[p][i];
 
    if(p==q) return ret;
 
    for(int i=x; i>=0; i--)
        if(P[p][i]!=-1 && P[p][i]!=P[q][i])
            ret=max(ret, Q[p][i]),ret=max(ret, Q[q][i]),p=P[p][i],q=P[q][i];
 
    ret=max(ret,A[p]);
    ret=max(ret,A[q]);
    return ret;
}
 
 
int main(){
 
//    filein;
 
 
    int n,m,q,N=0,t;
    IO(t);
    while(t--){
        IO(n); IO(m);
        while(m--){
            int u,v;
            i64 w;
            IO(u); IO(v); IO(w);
            --u; --v;
            g.pb( node(u,v,w) );
        }
 
        REP(i,n) T[i]=i;
 
        mst(n);
        dfs(0,0,0,0);
        lca_init(n);
 
        printf("Case %d:\n",++N);
 
        IO(q);
        while(q--){
            int u,v;
            IO(u); IO(v);
            printf("%lld\n",LCA(u-1,v-1));
        }
        REP(i,n) adj[i].cl;
        g.cl;
    }
    return 0;
}
 
