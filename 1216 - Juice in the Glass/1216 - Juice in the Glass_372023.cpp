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
 
#define PI 3.141592653589793238462643383279502885
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
        double r1,r2,h,p;
        scanf("%lf %lf %lf %lf",&r1,&r2,&h,&p);
        double R = p/h*(r1-r2)+r2;
 
        printf("Case %d: %lf\n",T,1/3.0*PI*p*((R*R)+(r2*R)+(r2*r2)));
    }
    return 0;
}
 
 
