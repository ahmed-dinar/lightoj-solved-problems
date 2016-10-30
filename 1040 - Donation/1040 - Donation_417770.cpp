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
int cable[52][52];
int par[52];
int res;
 
int parent(int x){
    return (par[x]==x) ? x : parent(par[x]);
}
 
bool mst(int n){
    int total=0;
    while(!q.empty()){
        E e=q.top();
        q.pop();
        if(e.w==0) continue;
        int u=parent(e.u);
        int v=parent(e.v);
        if(u!=v){
            if(cable[e.v][e.u]>0 && cable[e.u][e.v]>0){
                res += Max(cable[e.v][e.u],cable[e.u][e.v]);
            }
            par[u]=v;
            total++;
            cable[e.u][e.v]=-1;
            cable[e.v][e.u]=-1;
            if(total==n-1){
                return true;
            }
        }
    }
    return false;
}
 
int main()
{
    
    int t;
    sc(t);
    for(int T=1;T<=t;T++){
        int n,l;
        sc(n);
        for(int i=1;i<=n;i++)
            for(int j=1;j<=n;j++)
                cable[i][j]=0;
 
        res=0;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                sc(l);
                if(i==j && l>0)
                    res+=l;
                else if(i!=j ){
                    par[i]=i;
                    par[j]=j;
                    q.push( E(i,j,l) );
                    cable[i][j]=l;
                }
            }
        }
        if(n==1)
            printf("Case %d: %d\n",T,res);
        else if(  mst(n) ){
            for(int i=1;i<=n;i++){
                for(int j=1;j<=n;j++){
                    if(i==j)
                        continue;
                    else if(cable[i][j]==-1)
                        continue;
                    else if(cable[i][j]>0){
                        res += cable[i][j];
                        cable[i][j] = -1;
                    }
                }
            }
            printf("Case %d: %d\n",T,res);
        }
        else
            printf("Case %d: -1\n",T);
 
        while(!q.empty()) q.pop();
    }
    return 0;
}
 
 
