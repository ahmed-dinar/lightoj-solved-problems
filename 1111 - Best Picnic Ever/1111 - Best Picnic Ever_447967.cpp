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
#define fileout freopen("new_years_resolution_out.txt","w",stdout)
 
#define cs(x) printf("Case %d: ",x)
#define csn(x) printf("Case %d:\n",x)
 
#define nFind(v,n) find(all(v),n)==v.end()
#define Find(v,n) find(all(v),n)!=v.end()
#define all(x) x.begin(),x.end()
#define mp make_pair
#define pb push_back
#define sz size()
#define cl clear()
#define em empty()
#define ss second
#define fi first
 
#define sc(n) scanf("%d",&n)
#define nl puts("")
 
#define REP(i,n) for(int i=0;i<n; i++)
#define FOR(i,k,n) for(int i=k;i<=n; i++)
#define For(i,k,n) for(int i=k;i<n; i++)
 
#define EPS 1e-9
#define pi acos(-1.0)
#define MAX 1005
#define oo 200000000
#define MOD 1000000007
 
typedef long long i64;
typedef pair<int,int> pri;
typedef vector<int> vci;
typedef vector<pri> vcp;
 
template<class T>bool iseq(T a,T b){return fabs(a-b)<EPS;}
template<class T>T sq(T a){ return (a*a); }
template<class T>T gcd(T a,T b){ return (b==0) ? a : gcd(b,a%b); }
template<class T>T lcm(T a,T b){ return (a/gcd(a,b))*b; }
template<class T>T Pow(T n,T p) { T res=n; for(T i=1;i<p; i++){ res *= n; } return res; }
template<class T>bool isPrime(T n){ for(T i=2; i*i<=n; i++){ if(n%i==0) return false; } return true; }
 
int vis[105][MAX];
vci g[MAX];
 
void dfs(int u,int i){
    vis[i][u]=1;
    REP(j,g[u].sz)
        if(!vis[i][g[u][j]])
            dfs(g[u][j],i);
}
 
int main(){
 
    //filein;
 
    int t,T=0,h,k,m,n;
    scanf("%d",&t);
    while(t--){
        scanf("%d %d %d",&k,&n,&m);
        set<pri>home_city;
        set<pri>::iterator it;
        REP(i,k){
            scanf("%d",&h);
            home_city.insert( mp(i+1,h) );
        }
        while(m--){
            int u,v;
            scanf("%d %d",&u,&v);
            g[u].pb(v);
        }
        memset(&vis,0,sizeof(vis));
        for(it=home_city.begin(); it!=home_city.end(); it++){
            pri p=*it;
            dfs(p.ss,p.fi);
        }
        int ans=0;
        FOR(i,1,n){
            int x=1;
            FOR(j,1,k){
                if(!vis[j][i]){
                    x=0;
                    break;
                }
            }
            ans+=x;
        }
        printf("Case %d: %d\n",++T,ans);
        FOR(i,1,n) g[i].cl;
    }
    return 0;
}
 
