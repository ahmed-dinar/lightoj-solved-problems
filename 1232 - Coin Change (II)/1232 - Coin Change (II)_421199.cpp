#include<bits/stdc++.h>
 
using namespace std;
 
#define all(x) x.begin(),x.end()
#define Find(x,n) find(all(x),n)
#define pi acos(-1.0)
#define i64 long long
#define pb(x) push_back(x)
#define mset(x,v) memset(x,v,sizeof(x))
#define sc(n) scanf("%d",&n)
#define scl(n) scanf("%ld",&n)
#define scd(n,m) scanf("%d %d",&n,&m)
#define scdl(n,m) scanf("%ld %ld",&n,&m)
#define filein freopen("in.txt","r",stdin)
#define fileout freopen("my.txt","w",stdout)
#define FOR(i,n) for(int i=0;i<n; i++)
#define inf 10000.0
#define MAX 5000000
#define MOD 100000007
 
bool isUpper(char ch){ if( ch>='A' && ch<='Z' ) return true; return false; }
bool isLower(char ch){ if( ch>='a' && ch<='z') return true; return false;}
bool isLetter(char ch){ if( ch>='A' && ch<='Z' || ch>='a' && ch<='z') return true; return false; }
bool isDigit(char ch){ if( ch>='0' && ch<='9') return true; return false; }
char toLower(char ch){ if (isUpper(ch)) return (ch+32); return ch; }
char toUpper(char ch){ if (isLower(ch)) return (ch-32); return ch; }
 
template<class T>bool isEven(T a){ return (a%2==0);}
template<class T>T sq(T a){ return a*a; }
template<class T>T gcd(T a,T b){ return b==0 ? a : gcd(b,a%b); }
template<class T>T lcm(T a,T b){ return (a/gcd(a,b))*b; }
template<class T>bool isPrime(T n){ for(T i=2; i*i<=n; i++){ if(n%i==0) return false; } return true; }
template<class T>T Pow(T n,T p) { T res=n; for(T i=1;i<p; i++){ res *= n; } return res; }
template<class T>T Max(T n,T p) { if(n>=p) return n; return p; }
template<class T>T ABS(T n) { return (n<0) ?  (-n) :  n; }
 
 
int main()
{
    //filein;
 
    int T;
    sc(T);
    for(int t=1;t<=T;t++){
        int n,k;
        scd(n,k);
        int coin[n+1];
        for(int i=0;i<n;i++){
            sc(coin[i]);
        }
        i64 ans[k+1];
        mset(ans,0);
        ans[0]=1%MOD;
        for(int i=0;i<n;i++){
            for(int j=coin[i];j<=k;j++){
                ans[j] = (ans[j]%MOD +  ans[j-coin[i]]%MOD)%MOD;
            }
        }
        printf("Case %d: %lld\n",t,ans[k]);
    }
    return 0;
}
 
 
