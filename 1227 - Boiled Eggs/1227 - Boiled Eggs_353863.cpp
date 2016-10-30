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
 
int main()
{
    int t,ca=0;
    int n,weight[50],q,co,p;
    scanf("%d",&t);
    while(t--){
       scanf("%d %d %d",&n,&p,&q);
       for(int x=1; x<=n; x++){
            scanf("%d",&weight[x]);
       }
       int w=0;
       co=0;
       for(int x=1;x<=n; x++){
            if(co+1<=p&&w+weight[x]<=q){
                w=w+weight[x];
                co++;
            }
            else
                break;
       }
       printf("Case %d: %d\n",++ca,co);
    }
    return 0;
}
 
