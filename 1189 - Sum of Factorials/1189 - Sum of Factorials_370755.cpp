#include<cstdio>
#include<cstdlib>
#include<cctype>
#include<cmath>
#include<cstring>
#include<algorithm>
#include<iostream>
#include<sstream>
#include<fstream>
#include<numeric>
#include<string>
#include<vector>
#include<map>
#include<set>
#include<queue>
#include<stack>
#include<list>
#include<iterator>
#include<limits.h>
 
using namespace std;
 
#define ll long long
 
ll F[21];
 
ll fact(ll n)
{
    if(n==0)
        return 1;
    return n*fact(n-1);
}
 
void gen()
{
    F[0]=1;
    F[1]=1;
    for(ll i=2; i<=20; i++)
        F[i] = fact(i);
}
 
int main()
{
    gen();
    int t;
    scanf("%d",&t);
    for(int T=1; T<=t; T++)
    {
        ll N,m;
        int ans[30],k=0;
        scanf("%lld",&N);
        m=N;
        for(int i=20; i>=0; i--){
            if(m<=0)
                break;
            if(F[i]<=m)
            {
                m = m - F[i];
                ans[k] = i;
                k++;
            }
        }
        printf("Case %d: ",T);
        if(m==0){
            for(int i=k-1; i>=0; i--){
                printf("%d!",ans[i]);
                if(i)
                    printf("+");
            }
        }
        else
            printf("impossible");
 
        printf("\n");
    }
 
    return 0;
}
 
 
