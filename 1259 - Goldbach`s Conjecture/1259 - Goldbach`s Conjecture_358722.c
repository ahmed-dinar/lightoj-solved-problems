#include <stdio.h>
#include <math.h>
#include <stdlib.h>
 
#define ll long long
#define N 10000000
 
ll m[312501]={0},pri[664580];
 
void sieve()
{
    ll k,n,i;
    ll sq=sqrt(N);
    m[0/32] = m[0/32] | 1 << 0%32;
    m[1/32] = m[1/32] | 1 << 1%32;
    for(k=3; k<=sq; k = k+2)
    {
        if( (m[k/32] & 1<<k) == 0 )
        {
            for(i=k*k; i<=N; i += 2*k )
            {
                m[i/32] = m[i/32] | 1 << i%32;
            }
        }
    }
    for(i=4; i<=N; i += 2 )
    {
        if( (m[i/32] & 1<<i) == 0 )
        {
            m[i/32] = m[i/32] | 1 << i%32;
        }
    }
    k=1;
    pri[0]=2;
    for(i=3; i<=N; i += 2 )
    {
        if( (m[i/32] & 1<<i) == 0 )
        {
            pri[k]=i;
            k++;
        }
    }
}
 
 
int main()
{
    sieve();
    int t,ca=0;
    ll a,i,mns,no;
    scanf("%d",&t);
    while( t-- )
    {
        scanf("%lld",&a);
        no=0;
        for(i=0; pri[i]<=a/2; i++)
        {
            mns = a - pri[i];
            if( (m[mns/32] & 1<<mns) == 0)
            {
                no++;
            }
        }
        printf("Case %d: %lld\n",++ca,no);
     }
    return 0;
}
 
