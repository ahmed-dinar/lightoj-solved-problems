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
    cin >> t;
    while(t--)
    {
        int N,sum=0,M;
        cin >> N;
        while(N--)
        {
            cin >> M;
            if(M > 0)
            {
                sum = sum + M;
            }
        }
        printf("Case %d: %d\n",++ca,sum);
    }
    return 0;
}
 
