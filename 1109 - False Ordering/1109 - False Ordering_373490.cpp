/*
Ahmed Dinar
CSE,JUST
*/
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
 
#define input( f ) freopen( f, "r", stdin )
#define PI 3.14159265358979323846264338327950
#define inf 2147483647
#define ll long long
#define FOR(i,n) for(int i=0;i<n;i++)
#define test(T,t) for(int T=1;T<=t;T++)
#define pb(v,n) v.push_back(n)
#define Size(n) n.size()
#define len(s) strlen(s)
#define all(n) n.begin(),n.end()
#define mem(n,v) memset(&n,v,sizeof(n))
 
struct D
{
    int num,dv;
    D(int a,int b){num=a; dv=b;}
    bool operator<(const D&p)const{
        if(p.dv==dv)
            return p.num>num;
        else
            return p.dv<dv;
    }
};
 
priority_queue<D>Q;
int ans[1010];
 
void pre()
{
    for(int j=1; j<=1000; j++){
        int divisor = 0;
        for (int i = 1; i * i <= j; i++)
        {
            if (i * i == j)
                divisor += 1;
            else if (j % i == 0)
                divisor += 2;
        }
        Q.push(D(j,divisor));
    }
    int i=0;
    while(!Q.empty()){
        ans[++i] = Q.top().num;
        //cout << Q.top().num <<  " " <<Q.top().dv << endl;
        Q.pop();
    }
}
 
int main()
{
    //input("i");
 
    pre();
    int t;
    scanf("%d",&t);
    test(T,t){
        int n;
        scanf("%d",&n);
        printf("Case %d: %d\n",T,ans[n]);
    }
    return 0;
}
 
