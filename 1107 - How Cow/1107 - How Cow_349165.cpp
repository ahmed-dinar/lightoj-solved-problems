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
        int x1,y1,x2,y2,m,a,b;
        cin >> x1 >> y1 >> x2 >> y2;
        cin >> m;
        printf("Case %d:\n",++ca);
        while(m--)
        {
            cin >> a >> b;
            if(a<=x1 || a>=x2 || b<=y1 || b>=y2)
                printf("No\n");
            else
                printf("Yes\n");
        }
    }
    return 0;
}
 
