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
 
#define eps 0.0000000001
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
#define fileout freopen("my.txt","w",stdout)
#define REP(i,n) for(int i=0;i<n; i++)
#define FOR(i,k,n) for(int i=k;i<=n; i++)
#define fr(i,k,n) for(int i=k;i<n; i++)
#define MAX 50000000000
#define inf 2000000000
#define MOD 100000000
 
template<class T>T sq(T a){ return (a*a); }
template<class T>T gcd(T a,T b){ return b==0 ? a : gcd(b,a%b); }
template<class T>T lcm(T a,T b){ return (a/gcd(a,b))*b; }
template<class T>bool isPrime(T n){ for(T i=2; i*i<=n; i++){ if(n%i==0) return false; } return true; }
 
 
int main()
{
  //  filein;
   // fileout;
 
    int n,t,T=0;
    sc(t);
    while( t-- ){
        i64 w;
        scanf("%d %lld",&n,&w) ;
        set<i64>b;
        while(n--){
            i64 x,y;
            scanf("%lld %lld",&x,&y);
            b.insert(y);
        }
        i64 k=MAX,total=0;
        for(set<i64>::iterator it = b.begin(); it!=b.end(); ++it){
            i64 p = (i64)*it;
           // cout << p << endl;
            if( k==MAX ){
                //cout << " - > " <<  p << endl;
                k=p+w;
                ++total;
            }
            else if( p>k ){
                k=p+w;
                ++total;
            }
        }
        printf("Case %d: %lld\n",++T,total);
    }
    return 0;
}
 
 
