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
 
int binary(long X){
    int countt=0;
    while(X != 0){
        if(X%2 == 1)
        {
            countt++;
        }
        X = X/2;
    }
    return countt;
}
 
int main()
{
    int t,ca=0;
    scanf("%d",&t);
    while(t--)
    {
        long N;
        scanf("%ld",&N);
        if(binary(N)%2 != 0)
            printf("Case %d: odd\n",++ca);
        else
            printf("Case %d: even\n",++ca);
    }
    return 0;
}
 
 
