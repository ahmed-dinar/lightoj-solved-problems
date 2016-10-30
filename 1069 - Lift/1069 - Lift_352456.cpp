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
    int ca=0,t,m,l,tim;
    scanf("%d",&t);
    while(t--)
    {
         scanf("%d %d",&m,&l);
         tim = 0;
         if(l>=m){
            tim = (l*4)+19;
         }
         else
         {
            tim = (m-l)*4;
            tim = tim + (m*4) + 19;
         }
         printf("Case %d: %d\n",++ca,tim);
    }
    return 0;
}
 
 
 
 
 
 
 
 
 
 
