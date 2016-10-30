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
#define MAX 505
#define oo 2000000000.0
#define MOD 1000000007
 
typedef long long i64;
typedef pair<int,int> pri;
typedef vector<string> vcs;
typedef vector<int> vci;
typedef vector<pri> vcp;
 
template<class T>bool iseq(T a,T b){return fabs(a-b)<EPS;}
template<class T>T sq(T a){ return (a*a); }
template<class T>T gcd(T a,T b){ return (b==0) ? a : gcd(b,a%b); }
template<class T>T lcm(T a,T b){ return (a/gcd(a,b))*b; }
template<class T>T Pow(T n,T p) { T res=n; for(T i=1;i<p; i++){ res *= n; } return res; }
template<class T>bool isPrime(T n){ for(T i=2; i*i<=n; i++){ if(n%i==0) return false; } return true; }
 
int dx[]={+0,+0,-1,+1};
int dy[]={+1,-1,+0,+0};
int r,c;
char maze[MAX][MAX];
int vis[MAX][MAX],ans[MAX][MAX];
 
bool valid(int rr,int cc){
    return (rr>=0 && rr<r && cc>=0 && cc<c);
}
 
void bfs(int sx,int sy){
    queue<int>qx,qy;
    qx.push(sx);
    qy.push(sy);
    int cry=(maze[sx][sy]=='C');
    vcp cells;
    cells.pb(mp(sx,sy));
    vis[sx][sy]=1;
    while(!qx.em){
        int px=qx.front();
        qx.pop();
        int py=qy.front();
        qy.pop();
        REP(i,4){
            int nx=px+dx[i];
            int ny=py+dy[i];
            if( valid(nx,ny) && maze[nx][ny]!='#' && !vis[nx][ny] ){
                vis[nx][ny]=1;
                cry+=(maze[nx][ny]=='C');
                qx.push(nx);
                qy.push(ny);
                cells.pb(mp(nx,ny));
            }
        }
    }
    REP(i,cells.sz) ans[cells[i].fi][cells[i].ss]=cry;
}
 
int main(){
 
   // filein;
 
    int t,T=0,Q;
    sc(t);
    while( t-- ){
        scanf("%d %d %d\n",&r,&c,&Q);
        REP(i,r) gets(maze[i]);
 
        REP(i,r) REP(j,c) vis[i][j]=0,ans[i][j]=0;
 
 
        REP(i,r) REP(j,c) if(maze[i][j]!='#' && !vis[i][j]) bfs(i,j);
 
        printf("Case %d:\n",++T);
        while(Q--){
            int x,y;
            scanf("%d %d",&x,&y);
            printf("%d\n",ans[x-1][y-1]);
        }
    }
    return 0;
}
 
