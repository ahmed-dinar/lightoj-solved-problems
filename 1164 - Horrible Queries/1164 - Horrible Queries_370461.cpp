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
#define inf 2147483645
#define mx 100010
 
struct info
{
    ll prop,sum;
}tree[mx*3];
 
ll A[mx];
 
void IN(int node,int low,int high)
{
    if(low==high){
        tree[node].sum = A[low];
        return;
    }
    int l = node*2;
    int r = node*2+1;
    int m = (low+high)/2;
    IN(l,low,m);
    IN(r,m+1,high);
    tree[node].sum = tree[l].sum + tree[r].sum;
}
 
ll Q(int node,int low,int high,int i,int j,ll carry=0)
{
    int total = (high-low+1);
    if(i>high || j<low) return 0;
 
    if(low>=i && high<=j){
        return tree[node].sum+(total*carry);
    }
 
    int l = node*2;
    int r = node*2+1;
    int m = (low+high)/2;
    ll x = Q(l,low,m,i,j,carry+tree[node].prop);
    ll y = Q(r,m+1,high,i,j,carry+tree[node].prop);
 
    return x+y;
}
 
void update(int node,int low,int high,int i,int j,ll value)
{
    int total=(high-low+1);
 
    if(i>high || j<low) return;
 
    if(low>=i && high<=j){
        tree[node].sum += (total*value);
        tree[node].prop += value;
        return;
    }
    int l = node*2;
    int r = node*2+1;
    int m = (low+high)/2;
    update(l,low,m,i,j,value);
    update(r,m+1,high,i,j,value);
    tree[node].sum = tree[l].sum + tree[r].sum + (total*tree[node].prop);
}
 
int main()
{
    int t;
    scanf("%d",&t);
    for(int T=1; T<=t; T++)
    {
        int n,q;
        scanf("%d %d",&n,&q);
        memset(&tree,0,sizeof(tree));
        for(int i=1; i<=n; i++)
            A[i]=0;
 
        IN(1,1,n);
        printf("Case %d:\n",T);
        while(q--)
        {
            int j,i,in;
            scanf("%d %d %d",&in,&i,&j);
            if(in==0)
            {
                ll v;
                scanf("%lld",&v);
                update(1,1,n,++i,++j,v);
            }
            else{
                ll N = Q(1,1,n,++i,++j);
                printf("%lld\n",N);
            }
        }
 
    }
    return 0;
 
}
 
 
