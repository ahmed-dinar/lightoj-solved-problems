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
 
#define ll long long
 
ll coin[200];
ll times[200];
ll DP[200][1010];
ll n,k;
 
ll change(ll i,ll price)
{
    if(i>=n)
    {
        if(price == k)
            return 1;
        else
            return 0;
    }
 
    if(price>k) return 0;
 
    if(price == k) return 1;
 
    if(DP[i][price] != -1) return DP[i][price];
    ll p=0;
    for(int m=1; m<=times[i]; m++)
    {
        if(price+(coin[i]*m)>=0)
            p+=change(i+1,price+(coin[i]*m))%100000007;
        else
            break;
    }
    p += change(i+1,price)%100000007;
    return DP[i][price]=p%100000007;
}
 
int main()
{
 
    ll t;
    int ca=0;
    scanf("%lld",&t);
    while(t--)
    {
        scanf("%lld %lld",&n,&k);
        for(int j=0; j<n; j++)
            scanf("%d",&coin[j]);
 
        for(int j=0; j<n; j++)
            scanf("%lld",&times[j]);
        memset(&DP, -1, sizeof(DP));
        printf("Case %d: %lld\n",++ca,change(0,0));
    }
    return 0;
}
 
