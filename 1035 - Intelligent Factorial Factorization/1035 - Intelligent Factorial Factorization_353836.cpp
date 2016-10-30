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
 
int prime[26];
vector<int>V[105];
int FAC[105][105]={0};
 
void pri()
{
    int bol[12]={0};
    int ik,jk,sq;
    prime[0] = 2;
    sq= sqrt(12);
    for( ik = 3; ik <=sq; ik+=2 )
    {
        if( bol[ik] == 0)
        {
            for( jk = ik*ik; jk <= 12; jk += 2*ik )
            {
                 bol[jk] = 1;
            }
        }
    }
    for( ik = 3,jk=1; ik <= 12; ik+=2 )
    {
        if( bol[ik] == 0)
        {
            prime[jk] = ik;
            jk++;
        }
    }
}
 
 
void primeFactorize(int pn )
{
    int i=0,sqrtPn,temp=pn;
    sqrtPn =sqrt(pn);
    for( i = 0; prime[i] <= sqrtPn; i++ )
    {
        if( pn % prime[i] == 0 )
        {
            V[temp].push_back(prime[i]);
            while( pn % prime[i] == 0 )
            {
                pn /= prime[i];
                FAC[temp][prime[i]]++;
            }
        }
    }
    if(pn > 1)
    {
        V[temp].push_back(pn);
        FAC[temp][pn]++;
    }
}
 
void preg()
{
    for(int i=1; i<=100; i++)
        primeFactorize(i);
}
 
int main()
{
    pri();
    preg();
    int num,ca=0,test;
    scanf("%d",&test);
    while(test--)
    {
        scanf("%d",&num);
       int ans[105]={0};
       vector<int>tot;
       for(int i=1; i<=num; i++)
       {
           int sz=V[i].size();
           for(int j=0; j<sz; j++)
           {
                int u=V[i][j];
                int v=FAC[i][u];
                if(ans[u] != 0){
                    ans[u]=ans[u]+v;
                }
                else{
                    tot.push_back(u);
                    ans[u]=ans[u]+v;
                }
            }
        }
        printf("Case %d: %d =",++ca,num);
        int sz=tot.size();
        for(int i=0; i<sz; i++){
                printf(" %d (%d)",tot[i],ans[tot[i]]);
                if(i<sz-1)
                    printf(" *");
        }
        printf("\n");
    }
    return 0;
}
 
