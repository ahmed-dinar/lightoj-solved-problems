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
#define MAX 35
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
 
int dx[]={+1,+0,-1,+0,-1,-1,+1,+1};
int dy[]={+0,+1,+0,-1,+1,-1,-1,+1};
 
struct cell
{
    int i,j,k; string dir;
    cell(int i,int j,int k,string dir) : i(i),j(j),k(k),dir(dir) {}
};
 
map<char,vcp>g;
char maze[MAX][MAX],u;
int occur[MAX],r,c,len,vis[MAX][MAX][18];
string getDir[]={ ", D", ", R", ", U", ", L", ", UR", ", UL", ", DL", ", DR", ", *" };
string s,direction;
 
bool valid(int rr,int cc){
    return (rr>=0 && rr<r && cc>=0 && cc<c);
}
 
int bfs(int si,int sj){
    queue<cell>q;
    string D="";
    q.push( cell(si,sj,1,D) );
    while(!q.em){
 
        cell cc=q.front(); q.pp;
 
        int px=cc.i;
        int py=cc.j;
        int k=cc.k;
        string face=cc.dir;
 
        if(k>=len){
            direction=face;
            return 1;
        }
 
        if( s[k-1]==s[k] ){
            string ff=face;
           // ff.append(getDir[8]);
            int p=k;
            while( p<len && s[k-1]==s[p] ){
                p++;
                ff.append(getDir[8]);
                q.push( cell(px,py,p,ff) );
            }
        }
 
        REP(i,8){
            int nx=px+dx[i];
            int ny=py+dy[i];
            if( valid(nx,ny) &&  maze[nx][ny]==s[k] && !vis[nx][ny][k] ){
                vis[nx][ny][k]=1;
                string ff=face;
                ff.append(getDir[i]);
                q.push( cell(nx,ny,k+1,ff) );
            }
        }
    }
    return 0;
}
 
int solvable(){
    REP(i,len) if(!occur[s[i]-'A']) return 0;
    return 1;
}
 
int main(){
 
   // filein;
    //fileout;
 
    int t,T=0,n;
    IO(t);
    while(t--){
        IO(r); IO(c);
        CL(occur);
        REP(i,r){
            REP(j,c){
                cin>>u;
                occur[u-'A']=1;
                g[u].pb(mp(i,j));
                maze[i][j]=u;
            }
        }
        printf("Case %d:\n",++T);
        IO(n);
        while(n--){
            cin>>s;
            len=s.sz;
            if(!solvable()){
                printf("%s not found\n",s.c_str());
                continue;
            }
            int yes=0;
            u=s[0];
            CL(vis);
            REP(i,g[u].sz){
                pri p=g[u][i];
                yes=bfs(p.fi,p.ss);
                if(yes){
                    printf("%s found: (%d,%d)%s\n",s.c_str(),p.fi+1,p.ss+1,direction.c_str());
                    break;
                }
            }
            if(!yes) printf("%s not found\n",s.c_str());
        }
        for(char ch='A'; ch<='Z'; ch++) g[ch].cl;
    }
    return 0;
}
 
