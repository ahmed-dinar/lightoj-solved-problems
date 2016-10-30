#include<cstdio>
#include<sstream>
#include<cstdlib>
#include<cctype>
#include<cmath>
#include<algorithm>
#include<set>
#include<queue>
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
 
#define EPS 0.0000000001
#define pr pair<int,int>
#define mp make_pair
#define ss second
#define fi first
#define i64 long long
#define nl printf("\n")
#define pb(x) push_back(x)
#define all(x) x.begin(),x.end()
#define Find(x,n) find(all(x),n)
#define mset(x,v) memset(x,v,sizeof(x))
#define sc(n) scanf("%d",&n)
#define filein freopen("in.txt","r",stdin)
#define fileout freopen("out.txt","w",stdout)
#define REP(i,n) for(int i=0;i<n; i++)
#define FOR(i,k,n) for(int i=k;i<=n; i++)
#define fr(i,k,n) for(int i=k;i<n; i++)
#define MAX 210
#define inf 2000000
#define MOD 100000000
 
template<class T>T sq(T a){ return (a*a); }
template<class T>T gcd(T a,T b){ return b==0 ? a : gcd(b,a%b); }
template<class T>T lcm(T a,T b){ return (a/gcd(a,b))*b; }
template<class T>bool isPrime(T n){ for(T i=2; i*i<=n; i++){ if(n%i==0) return false; } return true; }
 
int jane[MAX][MAX];
int fire[MAX][MAX];
char maze[MAX][MAX];
int r,c;
int x[] = {1,0,-1,0};
int y[] = {0,1,0,-1,};
 
bool valid_move(int rr,int cc){
    if( maze[rr][cc]=='#' )
        return false;
    else
        return ( (rr>=0&&rr<r) && (cc>=0&&cc<c) );
}
 
bool Exit(int rr,int cc){
    if( rr==0 || rr==r-1 || cc==0 || cc==c-1 )
        return true;
    else
        return false;
}
 
int bfs_Jane(int sr,int sc){
    queue<pr>q;
    q.push( mp(sr,sc) );
    jane[sr][sc]=0;
    while(!q.empty()){
        pr p = q.front(); q.pop();
        if( Exit(p.fi,p.ss) ) return jane[p.fi][p.ss]+1;
        REP(i,4){
            int rr=p.fi+x[i];
            int cc=p.ss+y[i];
            if( valid_move(rr,cc) && jane[p.fi][p.ss]+1<jane[rr][cc] ){
                if( fire[rr][cc]>jane[p.fi][p.ss]+1 ){
                    jane[rr][cc] = jane[p.fi][p.ss]+1;
                    q.push( mp(rr,cc) );
                }
            }
        }
    }
    return -1;
}
 
 
void bfs_fire(int sr,int sc){
    queue<pr>q;
    q.push( mp(sr,sc) );
    fire[sr][sc]=0;
    while(!q.empty()){
        pr p = q.front(); q.pop();
        REP(i,4){
            int rr=p.fi+x[i];
            int cc=p.ss+y[i];
            if( valid_move(rr,cc) && fire[p.fi][p.ss]+1<fire[rr][cc] ){
                fire[rr][cc] = fire[p.fi][p.ss]+1;
                q.push( mp(rr,cc) );
            }
        }
    }
}
 
 
int main()
{
    //filein;
 
    int t,T=0;
    sc(t);
    while( t-- ){
        scanf("%d %d\n",&r,&c);
        int jr=-1,jc=-1;
        vector<pr>fires;
        REP(i,r){
            gets(maze[i]);
            REP(j,c){
                if( maze[i][j]=='J' ){
                    jr = i;
                    jc = j;
                }
                else if( maze[i][j]=='F' ){
                    fires.pb( mp(i,j) );
                    maze[i][j] = '#';
                }
                jane[i][j]=inf;
                fire[i][j]=inf;
            }
        }
        if(jr==-1){
            printf("Case %d: Impossible\n",++T);
            continue;
        }
        int sz = fires.size();
        if(sz>0){
            REP(i,sz) bfs_fire(fires[i].fi,fires[i].ss);
        }
        sz = bfs_Jane(jr,jc);
        (sz==-1) ? printf("Case %d: IMPOSSIBLE\n",++T) : printf("Case %d: %d\n",++T,sz);
     }
    return 0;
}
 
 
