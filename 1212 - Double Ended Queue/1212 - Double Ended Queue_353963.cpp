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
 
using namespace std;
 
#define empt  printf("The queue is empty\n")
#define full  printf("The queue is full\n")
#define pl(x) (!strcmp(x,"pushLeft") ? 1 : 0 )
#define pr(x) (!strcmp(x,"pushRight") ? 1 : 0 )
#define pol(x) (!strcmp(x,"popLeft") ? 1 : 0 )
#define por(x) (!strcmp(x,"popRight") ? 1 : 0 )
 
 
int main()
{
    deque<int>Q;
    int t,ca=0;
    int n,m,v;
    char command[20];
    scanf("%d",&t);
    for(int i=0; i<t; i++)
    {
        scanf("%d %d",&n,&m);
        printf("Case %d:\n",++ca);
        for(int j=0; j<m; j++)
        {
            scanf("%s",command);
            if( pl(command) || pr(command) )
                    scanf("%d",&v);
 
            if( pol(command) )
            {
                if(Q.empty() )
                {
                    empt;
                }
                else if(!Q.empty())
                {
                    printf("Popped from left: %d\n",Q.front());
                    Q.pop_front();
                }
            }
            else if( por(command))
            {
                if(Q.empty())
                {
                    empt;
                }
                else if(!Q.empty())
                {
                    printf("Popped from right: %d\n",Q.back());
                    Q.pop_back();
                }
            }
            else if(pl(command))
            {
                if(Q.size()==n)
                {
                    full;
                }
                else
                {
                    printf("Pushed in left: %d\n",v);
                    Q.push_front(v);
                }
            }
            else if( pr(command))
            {
                if(Q.size()==n)
                {
                    full;
                }
                else
                {
                    printf("Pushed in right: %d\n",v);
                    Q.push_back(v);
                }
            }
        }
        Q.clear();
    }
    return 0;
}
 
 
 
