#include<iostream>
#include<cctype>
#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<cstring>
 
using namespace std;
 
#define ll long long
#define FOR(i,n) for(int i=0;i<n; i++)
#define test(T,t) for(int T=1; T<=t;T++)
#define inf 1000000
 
int main()
{
 
    int t;
    scanf("%d",&t);
    test(T,t){
        ll n,m;
        scanf("%lld %lld",&n,&m);
        ll total = (n/m)/2;
        ll a = (m*(m+1))/2;
        m *= 2;
        ll b = (m*(m+1))/2;
        b -= a;
 
        printf("Case %d: %lld\n",T,(b-a)*total);
    }
    return 0;
}
 
 
