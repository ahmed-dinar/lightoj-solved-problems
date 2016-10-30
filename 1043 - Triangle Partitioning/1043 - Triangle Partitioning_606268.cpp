 
#include<cstdio>
#include<sstream>
#include<cstdlib>
#include<cctype>
#include<cmath>
#include<algorithm>
#include<set>
#include<queue>
#include<deque>
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
#include<limits>
 
using namespace std;
 
#define filein       freopen("in.txt","r",stdin)
#define fileout      freopen("out2.txt","w",stdout)
 
#define MS(x,v)      memset(&x,v,sizeof(x))
#define CL(x)        memset(&x,0,sizeof(x))
#define mp           make_pair
#define pb           push_back
#define sz           size()
#define cl           clear()
#define ss           second
#define fi           first
 
#define vanish       scanf("\n")
#define nl           puts("")
#define endl         '\n'
#define i64          long long
#define all(x)       x.begin(),x.end()
 
#define Iterate(s)   for(typeof(s.begin()) it = s.begin(); it != s.end(); it++)
#define FOR(i,k,n)   for(__typeof(n) i = (k); i <= (n); ++i)
#define For(i,k,n)   for(__typeof(n) i = (k); i < (n); ++i)
#define ROF(i,k,n)   for(__typeof(n) i = k; i >= n; i--)
#define REP(i,n)     for(__typeof(n) i = 0; i < (n); ++i)
#define sq(x)        (x*x)
 
#define EPS          0.0000001
#define MAX          200005
#define oo           10000000
#define MOD          1000000007
 
#define PI           acos(-1.0)
 
 
int main(){
 
    int t,T=0;
    scanf("%d",&t);
    while(t--){
        double AB,AC,BC,R;
        scanf("%lf %lf %lf %lf",&AB,&AC,&BC,&R);
 
        double hi=AB,low=0.0;
        double s = (AB+BC+AC)/2.0;
        double ABC = sqrt( s*(s-AB)*(s-AC)*(s-BC) );
        double AD;
 
        int  c = 0;
        while( fabs(low-hi) > EPS  ){
 
            AD = (hi+low)/2.0;
 
            double AE = (AC * AD ) / AB;
            double DE = (BC * AD ) / AB;
 
            s = (AD + AE + DE)/2.0;
 
            double ADE = sqrt( s*(s-AD)*(s-DE)*(s-AE) );
            double BDEC = ABC - ADE;
            double r = ADE / BDEC;
 
            if( fabs(r-R) < EPS ){
                break;
            }
            else if( r > R ){
                hi = AD;
            }
            else{
                low = AD;
            }
 
             //printf("%lf %lf %lf %lf %lf\n",low,hi,AD,r,R);
 
             c++;
 
        }
 
        printf("Case %d: %lf\n",++T,AD);
 
    }
    return 0;
}
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
