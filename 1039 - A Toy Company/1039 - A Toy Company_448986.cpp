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
#define MAX 15
#define oo 2000000000.0
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
 
string S,E;
map<string,int>press;
map<string,int>vis;
 
char Pre(char ch){
    if(ch=='a') return 'z';
    return (char)ch-1;
}
 
char Post(char ch){
    if(ch=='z') return 'a';
    return (char)ch+1;
}
 
int bfs(){
 
    if( vis[S] || vis[E]   ) return -1;
 
    if(S==E) return 0;
 
    queue<pair<string,int> >q;
    q.push( mp(S,0) );
    vis[S]=1;
    while(!q.em){
 
        pair<string,int> p=q.front();
        q.pop();
 
        string s=p.fi;
        int d=p.ss;
 
        REP(i,3){
            string u=s;
            u[i]=Post(u[i]);
            if( !vis[u] && !press[u] ){
                if(u==E) return d+1;
                press[u]=1;
                q.push( mp(u,d+1) );
            }
            u=s;
            u[i]=Pre(u[i]);
            if( !vis[u] && !press[u] ){
                press[u]=1;
                if(u==E) return d+1;
                q.push( mp(u,d+1) );
            }
        }
    }
    return -1;
}
 
int main(){
 
    //filein;
   // fileout;
 
    int t,T=0,n;
    scanf("%d",&t);
    while(t--){
        string C[4];
        cin >> S >> E;
        scanf("%d",&n);
        while(n--){
            cin >> C[0] >> C[1] >> C[2];
            for(int i=0; C[0][i]!='\0'; i++){
                for(int j=0; C[1][j]!='\0'; j++){
                    for(int k=0; C[2][k]!='\0'; k++){
                        string o="";
                        o+=C[0][i];
                        o+=C[1][j];
                        o+=C[2][k];
                        vis[o]=1;
                    }
                }
            }
        }
        printf("Case %d: %d\n",++T,bfs());
        press.cl;
        vis.cl;
    }
    return 0;
}
 
