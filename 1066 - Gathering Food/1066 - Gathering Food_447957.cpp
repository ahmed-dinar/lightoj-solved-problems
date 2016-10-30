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
#define MAX 15
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
 
int x[]={+0,+0,-1,+1};
int y[]={+1,-1,+0,+0};
int n,d[MAX][MAX];;
char maze[MAX][MAX];
vcp food;
 
bool valid(int rr,int cc){
    return (rr>=0 && rr<n && cc>=0 && cc<n);
}
 
void bfs(int si,int sj){
    char next=maze[si][sj]+1;
    REP(i,n)
        REP(j,n)
            d[i][j]=oo;
    queue<pri>q;
    q.push( mp(si,sj) );
    d[si][sj]=0;
    while(!q.em){
        int rx=q.front().fi;
        int cx=q.front().ss; q.pop();
        REP(i,4){
            int xx=rx+x[i];
            int yy=cx+y[i];
            if( valid(xx,yy) && (maze[xx][yy]=='.' || maze[xx][yy]==next) && d[xx][yy]>d[rx][cx]+1){
                d[xx][yy]=d[rx][cx]+1;
                q.push( mp(xx,yy) );
            }
        }
    }
}
 
bool com(pri a,pri b){
    return maze[a.fi][a.ss] < maze[b.fi][b.ss];
}
 
int main(){
 
    //filein;
 
    int t,T=0;
    scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        REP(i,n){
            REP(j,n){
                cin>>maze[i][j];
                if(isupper(maze[i][j]))
                    food.pb(mp(i,j));
            }
        }
        sort(all(food),com);
        int Impossible=0,ans=0;
        REP(i,food.sz-1){
            bfs(food[i].fi,food[i].ss);
            if(d[food[i+1].fi][food[i+1].ss]==oo){
                Impossible=1;
                break;
            }
            else
                ans+=d[food[i+1].fi][food[i+1].ss],maze[food[i].fi][food[i].ss]='.';
        }
        printf("Case %d: ",++T);
        (Impossible) ? puts("Impossible") : printf("%d\n",ans);
        food.cl;
    }
    return 0;
}
 
