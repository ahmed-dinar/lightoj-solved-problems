#include<bits/stdc++.h>
 
using namespace std;
 
#define pf(x) printf("%d",x)
#define pfd(x,y) printf("%d %d",x,y)
#define pfl(x) printf("%ld",x)
#define pfll(x) printf("%lld",x)
#define pfllu(x)
#define nl printf("\n")
 
#define cs(x) printf("Case %d: ",x)
#define csn(x) printf("Case %d:\n",x)
 
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
#define inf 10000.0
#define MAX 5000001
#define MOD 4294967296
 
bool isUpper(char ch){ if( ch>='A' && ch<='Z' ) return true; return false; }
bool isLower(char ch){ if( ch>='a' && ch<='z') return true; return false;}
bool isLetter(char ch){ if( ch>='A' && ch<='Z' || ch>='a' && ch<='z') return true; return false; }
bool isDigit(char ch){ if( ch>='0' && ch<='9') return true; return false; }
char toLower(char ch){ if (isUpper(ch)) return (ch+32); return ch; }
char toUpper(char ch){ if (isLower(ch)) return (ch-32); return ch; }
 
template<class T>bool isEven(T a){ return (a%2==0);}
template<class T>T sq(T a){ return (a*a); }
template<class T>T gcd(T a,T b){ return b==0 ? a : gcd(b,a%b); }
template<class T>T lcm(T a,T b){ return (a/gcd(a,b))*b; }
template<class T>bool isPrime(T n){ for(T i=2; i*i<=n; i++){ if(n%i==0) return false; } return true; }
template<class T>T Pow(T n,T p) { T res=n; for(T i=1;i<p; i++){ res *= n; } return res; }
template<class T>T Max(T n,T p) { if(n>=p) return n; return p; }
template<class T>T ABS(T n) { return (n<0) ?  (-n) :  n; }
 
unsigned i64 res[MAX]={0};
 
void gen_res(){
    for(int i=2;i<MAX;i++){
        if(!res[i]){
            res[i]=i-1;
            for(int j=2*i;j<MAX;j+=i){
                if(!res[j])
                    res[j]=j;
                res[j] -= res[j]/i;
            }
        }
        res[i] = sq(res[i])+res[i-1];
    }
}
 
int main(){
 
    //filein;
 
    gen_res();
    int t,T=0;
    sc(t);
    while(t--){
        int a,b;
        scd(a,b);
        cs(++T);
        printf("%llu",res[b]-res[a-1]);
        nl;
    }
    return 0;
}
 
 
