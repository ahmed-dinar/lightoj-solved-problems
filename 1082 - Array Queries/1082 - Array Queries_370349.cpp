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
 
int tree[mx*3];
int A[mx];
 
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
    if( tree[l]<tree[r] )
        tree[node] = tree[l];
    else
        tree[node] = tree[r];
}
 
int Q(int node,int low,int high,int i,int j)
{
    if(i>high || j<low) return inf;
 
    if(low>=i && high<=j) return tree[node];
 
    int l = node*2;
    int r = node*2+1;
    int m = (low+high)/2;
    int x = Q(l,low,m,i,j);
    int y = Q(r,m+1,high,i,j);
    if(x<y)
        return x;
 
    return y;
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
            scanf("%d",&A[i]);
 
        IN(1,1,n);
        printf("Case %d:\n",T);
        while(q--)
        {
            int i,j;
            scanf("%d %d",&i,&j);
            printf("%d\n",Q(1,1,n,i,j));
        }
    }
 
    return 0;
}
 
 
