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
#define MAX 12
#define oo 20000000
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
 
int dx[]={+1,+0,-1,+0};
int dy[]={+0,+1,+0,-1};
 
struct cell
{
    pri a,b,c;
    int d;
    cell(pri a,pri b,pri c,int d) : a(a),b(b),c(c),d(d) {}
};
 
char maze[MAX][MAX],u;
pri a,b,c;
int n;
map<pri,map<pri,map<pri,int> > >vis;
 
bool valid(int rr,int cc){
    return (rr>=0 && rr<n && cc>=0 && cc<n);
}
 
int bfs(){
    queue<cell>q;
    q.push( cell(a,b,c,0) );
    vis[a][b][c]=1;
    int d;
    while(!q.em){
        cell cc=q.front(); q.pp;
 
        a=cc.a;
        b=cc.b;
        c=cc.c;
        d=cc.d;
 
        if(maze[a.fi][a.ss]=='X' && maze[b.fi][b.ss]=='X' && maze[c.fi][c.ss]=='X') return d;
 
        REP(i,4){
            pri x=mp(a.fi+dx[i],a.ss+dy[i]);
            pri y=mp(b.fi+dx[i],b.ss+dy[i]);
            pri z=mp(c.fi+dx[i],c.ss+dy[i]);
 
 
            if( !valid(x.fi,x.ss) || maze[x.fi][x.ss]=='#' ) x=a;
            if( !valid(y.fi,y.ss) || maze[y.fi][y.ss]=='#' ) y=b;
            if( !valid(z.fi,z.ss) || maze[z.fi][z.ss]=='#' ) z=c;
 
            if( x==a && y==b && z==c ) continue;
 
            if(x==a){
                if(x==y) y=b;
                if(x==z) z=c;
            }
            if(y==b){
                if(x==y) x=a;
                if(y==z) z=c;
            }
            if(z==c){
                if(z==x) x=a;
                if(y==z) y=b;
            }
 
            if( x==a && y==b && z==c ) continue;
 
            if( (x==y || x==z) || (y==x || y==z) || (z==x || z==y) ) continue;
 
            if(vis[x][y][z]) continue;
 
            vis[x][y][z]=1;
 
            q.push( cell(x,y,z,d+1) );
 
        }
 
    }
    return -1;
}
 
 
 
int main(){
 
    //filein;
    //fileout;
 
    int t,T=0;
    IO(t);
    while(t--){
        IO(n);
        REP(i,n){
            REP(j,n){
                cin>>u;
                if(u=='A') a=mp(i,j),maze[i][j]='.';
                else if(u=='B') b=mp(i,j),maze[i][j]='.';
                else if(u=='C') c=mp(i,j),maze[i][j]='.';
                else maze[i][j]=u;
            }
        }
        printf("Case %d: ",++T);
        int ans=bfs();
        if(ans==-1) puts("trapped");
        else printf("%d\n",ans);
        vis.cl;
    }
    return 0;
}
 
