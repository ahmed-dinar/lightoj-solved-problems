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
#define fileout freopen("my.txt","w",stdout)
#define REP(i,n) for(int i=0;i<n; i++)
#define FOR(i,k,n) for(int i=k;i<=n; i++)
#define fr(i,k,n) for(int i=k;i<n; i++)
#define MAX 1000005
#define inf 2000000000
#define MOD 100000000
 
template<class T>T sq(T a){ return (a*a); }
template<class T>T gcd(T a,T b){ return b==0 ? a : gcd(b,a%b); }
template<class T>T lcm(T a,T b){ return (a/gcd(a,b))*b; }
template<class T>bool isPrime(T n){ for(T i=2; i*i<=n; i++){ if(n%i==0) return false; } return true; }
 
int skip[MAX];
 
void kmp_prefix(char *b,int sz){
    skip[0]=0;
    for(int i=1,j=0;i<sz; i++){
        while( j>0 && b[i]!=b[j] ){
            j = skip[j-1];
        }
        if(b[i]==b[j]){
            ++j;
            skip[i]=j;
        }
        else{
            j=0;
            skip[i]=j;
        }
    }
}
 
int KMP(char *a,char *b){
    int sz=strlen(a);
    int ln=strlen(b);
    kmp_prefix(b,ln);
    int oc=0;
    for(int i=0,j=0;i<sz; i++){
        while( j>0 && a[i]!=b[j] ){
            j=skip[j-1];
        }
        if(a[i]==b[j]) ++j;
 
        if(j==ln){
            ++oc;
            j=skip[j-1];
        }
    }
    return oc;
}
 
int main()
{
    //filein;
 
    char a[MAX];
    char b[MAX];
    int t,T=0;
    scanf("%d",&t);
    while(t--){
        scanf("%s",a);
        scanf("%s",b);
        printf("Case %d: %d\n",++T,KMP(a,b));
    }
    return 0;
}
 
 
