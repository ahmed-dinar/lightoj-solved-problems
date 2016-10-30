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
 
#define inf 2147483647
#define ll long long
#define FOR(i,n) for(int i=0;i<n;i++)
#define test(T,t) for(int T=1;T<=t;T++)
#define pb(v,n) v.push_back(n)
#define Size(n) n.size()
#define len(s) strlen(s)
#define all(n) n.begin(),n.end()
#define Case(T) printf("Case %d: ",T)
#define mem(n,v) memset(&n,v,sizeof(n))
 
int main()
{
    int t;
    scanf("%d",&t);
    test(T,t){
        ll n,m;
        scanf("%lld %lld",&n,&m);
        ll a = (m*(m+1))/2;
        ll b = ((m*2)*((m*2)+1))/2;
        printf("Case %d: %lld\n",T,((b-a)-a)*((n/m)/2));
    }
    return 0;
}
 
 
