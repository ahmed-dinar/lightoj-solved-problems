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
#define MAX 100005
#define inf 2000000000
#define MOD 100000000
 
template<class T>T sq(T a){ return (a*a); }
template<class T>T gcd(T a,T b){ return b==0 ? a : gcd(b,a%b); }
template<class T>T lcm(T a,T b){ return (a/gcd(a,b))*b; }
template<class T>bool isPrime(T n){ for(T i=2; i*i<=n; i++){ if(n%i==0) return false; } return true; }
 
i64 ar[MAX];
 
struct seg
{
    i64 sum,p;
}tree[MAX*4];
 
void make_tree(int node,int low,int high){
    if( low==high ){
        tree[node].sum = 0;
        tree[node].p = -1;
        return;
    }
    int md = (low+high)/2;
    int le = node*2;
    int ri = (node*2)+1;
    tree[le].p = -1;
    tree[ri].p = -1;
    make_tree(le,low,md);
    make_tree(ri,md+1,high);
    tree[node].sum = tree[le].sum + tree[ri].sum;
}
 
void update(int node,int low,int high,int i,int j,i64 v){
    if( i>high || j<low) return;
    else if( low>=i && high<=j ){
        tree[node].sum = (high-low+1)*v;
        tree[node].p = v;
        return;
    }
    int md = (low+high)/2;
    int le = node*2;
    int ri = (node*2)+1;
    if( tree[node].p != -1 ){
        tree[le].sum = (md-low+1)*tree[node].p;
        tree[ri].sum = (high-md)*tree[node].p;
        tree[le].p = tree[node].p;
        tree[ri].p = tree[node].p;
        tree[node].p=-1;
    }
    update(le,low,md,i,j,v);
    update(ri,md+1,high,i,j,v);
    tree[node].sum = tree[le].sum + tree[ri].sum;
}
 
i64 Q(int node,int low,int high,int i,int j){
    if( i>high || j<low) return 0;
    else if( low>=i && high<=j ){
       return tree[node].sum;
    }
    int md = (low+high)/2;
    int le = node*2;
    int ri = (node*2)+1;
    if( tree[node].p != -1 ){
        tree[le].sum = (md-low+1)*tree[node].p;
        tree[ri].sum = (high-md)*tree[node].p;
        tree[le].p = tree[node].p;
        tree[ri].p = tree[node].p;
        tree[node].p=-1;
    }
    i64 ls = Q(le,low,md,i,j);
    i64 lr = Q(ri,md+1,high,i,j);
    tree[node].sum = tree[le].sum + tree[ri].sum;
 
    return ls+lr;
}
 
int main()
{
    //filein;
 
 
    int t,T=0;
    sc(t);
    while(t--){
        int n,qu;
        scanf("%d %d",&n,&qu);
        for(int i=1;i<=n; i++)
                ar[i]=0;
        printf("Case %d:\n",++T);
        make_tree(1,1,n);
        while(qu--){
            int in,i,j;
            scanf("%d %d %d",&in,&i,&j);
            if(in==1){
                i64 v;
                scanf("%lld",&v);
                update(1,1,n,++i,++j,v);
            }
            else if(in==2){
                i64 total = (i64)(j-i+1);
                i64 sum = Q(1,1,n,++i,++j);
                if( sum%total==0 )
                    printf("%lld\n",sum/total);
                else{
                    i64 gc = gcd(sum,total);
                    printf("%lld/%lld\n",sum/gc,total/gc);
                }
            }
        }
    }
    return 0;
}
 
 
