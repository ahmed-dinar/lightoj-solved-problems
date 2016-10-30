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
#define fileout freopen("my.txt","w",stdout)
 
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
 
map<int,vci >F;
int d[MAX];
 
void divisors(){
    int prime[]={2,3,5 ,7,11,13,17,19,23,29,31,37, 41,43,47,53};
    for(int n=1; n<=1002; n++){
        int m=n;
        for(int i=0;prime[i]*prime[i]<=n; i++){
            if(m%prime[i]==0){
                F[n].pb(prime[i]);
                while(m%prime[i]==0){
                    m/=prime[i];
                }
            }
        }
        if(m>1 && m!=n)
            F[n].pb(m);
    }
}
 
int bfs(int n,int m){
    memset(&d,0,sizeof(d));
    queue<int>q;
    q.push(n);
    while(!q.em){
        n=q.front();
        q.pop();
        REP(i,F[n].sz){
            int x=F[n][i]+n;
            if( x<=m && !d[x] ){
                d[x]=d[n]+1;
                if(x==m) return d[x];
                q.push(x);
            }
        }
    }
    return -1;
}
 
int main(){
 
    //filein;
    //fileout;
 
    divisors();
    int t,T=0;
    scanf("%d",&t);
    while(t--){
        int n,m;
        scanf("%d %d",&n,&m);
        if(n>m)
            printf("Case %d: -1\n",++T);
        else if(n==m)
            printf("Case %d: 0\n",++T);
        else
            printf("Case %d: %d\n",++T,bfs(n,m));
    }
    return 0;
}
 
