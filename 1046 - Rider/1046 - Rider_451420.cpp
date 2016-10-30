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
#define scd(n,m) scanf("%d %d",&n,&m)
#define sct(n,m,v) scanf("%d %d %d",&n,&m,&v)
#define nl puts("")
 
#define REP(i,n) for(__typeof(n) i = 0; i < (n); ++i)
#define FOR(i,k,n) for(__typeof(n) i = (k); i <= (n); ++i)
#define For(i,k,n) for(__typeof(n) i = (k); i < (n); ++i)
 
#define EPS 1e-9
#define pi acos(-1.0)
#define MAX 15
#define oo 20000000
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
 
int dx[]={-2,-2,+2,+2,+1,-1,+1,-1};
int dy[]={+1,-1,+1,-1,-2,-2,+2,+2};
char chess[MAX][MAX];
int moves[110][MAX][MAX];
int reach[110][MAX][MAX];
vector<pair<int,pri> >knights;
int r,c;
 
bool valid(int nx,int ny){
    return (nx>=0 && nx<r && ny>=0 && ny<c);
}
 
int bfs(){
 
    REP(i,r) REP(j,c) REP(k,knights.sz) reach[k][i][j]=0,moves[k][i][j]=oo;
 
    REP(k,knights.sz){
        queue<int>qx,qy,qk;
 
        int si=knights[k].ss.fi;
        int sj=knights[k].ss.ss;
        int sk=knights[k].fi;
 
        qx.push(si);
        qy.push(sj);
        qk.push(1);
 
        moves[k][si][sj]=0;
        reach[k][si][sj]=1;
 
        while(!qx.em){
 
            int px=qx.front(); qx.pop();
            int py=qy.front(); qy.pop();
            int pk=qk.front(); qk.pop();
            int nk=(pk==sk) ? 1 : pk+1;
 
 
            REP(i,8){
                int nx=px+dx[i];
                int ny=py+dy[i];
 
                if( valid(nx,ny) ){
 
                    int cost=(pk==1) ? 1 : 0;
 
                    if( moves[k][nx][ny]>moves[k][px][py]+cost ){
                        moves[k][nx][ny]=moves[k][px][py]+cost;
                        qx.push(nx);
                        qy.push(ny);
                        qk.push(nk);
                        reach[k][nx][ny]=1;
                    }
                }
            }
        }
    }
    int res=oo;
    REP(i,r){
        REP(j,c){
            int p=0,q=0;
            REP(k,knights.sz){
                if(!reach[k][i][j]){
                    p=0;
                    break;
                }
                q+=moves[k][i][j];
                p=1;
            }
            if(p) res=min(res,q);
        }
    }
    return (res==oo) ? -1 : res;
}
 
int main(){
 
   // filein;
 
    int t,T=0;
    scanf("%d",&t);
    while(t--){
        scanf("%d %d",&r,&c);
        REP(i,r){
            REP(j,c){
                cin>>chess[i][j];
                if( isdigit(chess[i][j]) ){
                    knights.pb( mp( (chess[i][j]-'0'),mp(i,j) ) );
                }
            }
        }
        printf("Case %d: %d\n",++T,bfs());
        knights.cl;
    }
    return 0;
}
 
