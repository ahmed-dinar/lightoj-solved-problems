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
 
#define EPS 1e-7
#define pi acos(-1.0)
#define MAX 1000000
#define oo 20000000
#define mod 1000000007
 
typedef long long i64;
typedef pair<int,int> pri;
typedef vector<int> vci;
typedef vector<i64> vci64;
typedef vector<pri> vcp;
 
template<class T>bool iseq(T a,T b){return fabs(a-b)<EPS;}
template<class T>T sq(T a){ return (a*a); }
template<class T>T gcd(T a,T b){ return (b==0) ? a : gcd(b,a%b); }
template<class T>T lcm(T a,T b){ return (a/gcd(a,b))*b; }
template<class T>T Pow(T n,T p) { T res=n; for(T i=1;i<p; i++){ res *= n; } return res; }
template<class T>bool isPrime(T n){ for(T i=2; i*i<=n; i++){ if(n%i==0) return false; } return true; }
 
 
int main(){
 
   // filein;
 
 /*   int wins[100]; //start alice
    wins[1]=0;
    wins[2]=1;
    wins[3]=1;
    wins[4]=0;
    wins[5]=1;
    wins[6]=1;
    wins[7]=0;
 
    cout << (4%3) << endl;
    */
 
    int t,T=0;
    scanf("%d",&t);
    while(t--){
        int n;
        string name;
        cin>>n>>name;
        printf("Case %d: ",++T);
        if(name[0]=='A')
            puts( (n%3!=1) ? "Alice" : "Bob" );
        else
            puts( (n%3==0) ? "Alice" : "Bob" );
    }
    return 0;
}
 
