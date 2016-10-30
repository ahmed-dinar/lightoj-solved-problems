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
 
long decimal(long x)
{
    int p=0;
    long dc;
    dc = ((x%10)*1);
    x = x/10;
    while(x !=  0 )
    {
        dc = dc + ((x%10)*(2<<p));
        x = x/10;
        p++;
    }
    return dc;
}
 
int main()
{
    int t,ca=0;
    cin >> t;
    while(t--)
    {
        int d1,d2,d3,d4;
        long b1,b2,b3,b4;
        char ch;
        scanf("%d%c%d%c%d%c%d",&d1,&ch,&d2,&ch,&d3,&ch,&d4);
        scanf("%ld%c%ld%c%ld%c%ld",&b1,&ch,&b2,&ch,&b3,&ch,&b4);
        if( (d1!=decimal(b1)) ||  (d2!=decimal(b2)) || (d3!=decimal(b3)) || (d4!=decimal(b4)) )
        {
            printf("Case %d: No\n",++ca);
        }
        else
        {
            printf("Case %d: Yes\n",++ca);
        }
    }
    return 0;
}
