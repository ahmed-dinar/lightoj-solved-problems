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
 
#define PI (2*acos(0.0))
 
int main()
{
    int t,ca=0;
    cin >> t;
    while(t--)
    {
        double r,circle,squre;
        cin >> r;
        circle = PI*(r*r);
        squre = (r+r)*(r+r);
        printf("Case %d: %.2lf\n",++ca,squre-circle);
 
    }
    return 0;
}
 
