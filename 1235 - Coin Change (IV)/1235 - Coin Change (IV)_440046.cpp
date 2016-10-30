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
#define MAX 20
#define inf 2000000000
#define MOD 100000000
 
template<class T>T sq(T a){ return (a*a); }
template<class T>T gcd(T a,T b){ return b==0 ? a : gcd(b,a%b); }
template<class T>T lcm(T a,T b){ return (a/gcd(a,b))*b; }
template<class T>bool isPrime(T n){ for(T i=2; i*i<=n; i++){ if(n%i==0) return false; } return true; }
 
long a[MAX];
vector<long>sums1;
vector<long>sums2;
long k;
int yes;
 
void genSubset2(int i,int n,long sum=0){
    if(yes) return;
    if(sum==k){
        yes=1;
        return;
    }
    sums2.pb(sum);
    for(int k=i;k<n;k++){
        genSubset2(k+1,n,sum+a[i]);
        genSubset2(k+1,n,sum+2*a[i]);
    }
}
 
void genSubset1(int i,int n,long sum=0){
    if(yes) return;
    if(sum==k){
        yes=1;
        return;
    }
    sums1.pb(sum);
    for(int k=i;k<n;k++){
        genSubset1(k+1,n,sum+a[i]);
        genSubset1(k+1,n,sum+2*a[i]);
    }
}
 
int binary_s(long v,int szb){
    int low=0;
    int high=szb-1;
    while(low<=high){
        int mid=low+(high-low)/2;
        if(sums2[mid]==v)
            return 1;
        else if(v>sums2[mid])
            low=mid+1;
        else
            high=mid-1;
    }
    return 0;
}
 
int main()
{
   // filein;
    //fileout;
 
    int t,T=0;
    sc(t);
    while(t--){
        int n;
        scanf("%d %ld",&n,&k);
        REP(i,n)
            scanf("%ld",&a[i]);
 
        yes=0;
        int f=n>>1;
        for(int i=0;i<f;i++)
            genSubset1(i,f);
 
        if(!yes){
            for(int i=f;i<n;i++)
                genSubset2(i,n);
 
            if(!yes){
                sort(all(sums2));
                int szb=sums2.size();
                int sza=sums1.size();
                for(int i=0;i<sza; i++){
                    long v=k-sums1[i];
                    if( binary_s(v,szb) ){
                        yes=1;
                        break;
                    }
                }
            }
        }
        printf("Case %d: %s\n",++T,(yes) ? "Yes" : "No");
        sums1.clear();
        sums2.clear();
    }
    return 0;
}
 
