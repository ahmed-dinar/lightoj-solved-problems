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
 
ll tree[mx*3];
ll A[mx];
 
void IN(int node,int low,int high)
{
    if(low==high){
        tree[node] = A[low];
        return;
    }
    int l = node*2;
    int r = node*2+1;
    int m = (low+high)/2;
    IN(l,low,m);
    IN(r,m+1,high);
    tree[node] = tree[l] + tree[r];
}
 
void update_zero(int node,int low,int high,int i,ll amount)
{
    if(i>high || i<low) return;
 
    if(low>=i && high<=i){
        tree[node] = amount;
        return;
    }
    int l = node*2;
    int r = node*2+1;
    int m = (low+high)/2;
    update_zero(l,low,m,i,amount);
    update_zero(r,m+1,high,i,amount);
    tree[node] = tree[l] + tree[r];
}
 
void update(int node,int low,int high,int i,ll amount)
{
    if(i>high || i<low) return;
 
    if(low>=i && high<=i){
        tree[node] += amount;
        return;
    }
    int l = node*2;
    int r = node*2+1;
    int m = (low+high)/2;
    update(l,low,m,i,amount);
    update(r,m+1,high,i,amount);
    tree[node] = tree[l] + tree[r];
}
 
ll Q(int node,int low,int high,int i,int j)
{
    if(i>high || j<low) return 0;
 
    if(low>=i && high<=j){
        return tree[node];
    }
 
    int l = node*2;
    int r = node*2+1;
    int m = (low+high)/2;
    ll x = Q(l,low,m,i,j);
    ll y = Q(r,m+1,high,i,j);
    return x+y;
}
 
int main()
{
    int t;
    scanf("%d",&t);
    for(int T=1; T<=t; T++)
    {
        int n,q;
        scanf("%d %d",&n,&q);
        for(int i=1; i<=n; i++)
            scanf("%lld",&A[i]);
 
        IN(1,1,n);
        printf("Case %d:\n",T);
        while(q--)
        {
            int indx,i;
            scanf("%d %d",&indx,&i);
            ++i;
            if(indx==1)
            {
                printf("%lld\n",A[i]);
                A[i]=0;
                update_zero(1,1,n,i,0);
            }
            else if(indx==2)
            {
                ll v;
                scanf("%lld",&v);
                A[i] += v;
                update(1,1,n,i,v);
            }
            else if(indx==3)
            {
                int j;
                scanf("%d",&j);
                printf("%lld\n",Q(1,1,n,i,++j));
            }
        }
    }
    return 0;
}
 
 
