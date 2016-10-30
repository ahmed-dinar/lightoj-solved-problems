#include<cstdio>
#include<cstdlib>
#include<cctype>
#include<cmath>
#include<cstring>
#include<algorithm>
#include<iostream>
#include<sstream>
#include<fstream>
#include<numeric>
#include<string>
#include<vector>
#include<map>
#include<set>
#include<queue>
#include<stack>
#include<list>
#include<iterator>
 
using namespace std;
 
int main()
{
    int t,ca=0;
    cin >> t;
    while(t--)
    {
        long a,b,c;
        cin >> a >> b >> c;
        if((a*a+b*b) == c*c || (a*a+c*c)==b*b || (b*b+c*c)== a*a)
            printf("Case %d: yes\n",++ca);
        else
            printf("Case %d: no\n",++ca);
    }
    return 0;
}
 
