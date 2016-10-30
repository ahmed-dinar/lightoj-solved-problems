#include<iostream>
#include<cstdio>
 
using namespace std;
 
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int x,y;
        scanf("%d",&x);
        y = x/2;
        printf("%d %d\n",y,x-y);
    }
    return 0;
}
 
