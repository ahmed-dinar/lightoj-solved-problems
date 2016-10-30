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
    int n,m,ca=0,t;
    scanf("%d",&t);
    while(  t-- )
    {
        scanf("%d",&n);
        string a,b;
        vector<string>bev;
        map<string,int>ind;
        map<string, vector<string> >oh;
        for(int i=0; i<n-1; i++)
        {
            cin >> a >> b;
            ind[b]++;
            if(  find(bev.begin(),bev.end(),a) == bev.end() )
                bev.push_back(a);
            if(  find(bev.begin(),bev.end(),b) == bev.end() )
                bev.push_back(b);
 
            oh[a].push_back(b);
        }
        map<string,int>visited;
        int c=0;
        printf("Case %d:\n",++ca);
        while(c<n)
        {
            for(int i=0; i<n; i++)
            {
                if( ind[bev[i]]==0  && visited[bev[i]]==0 )
                {
                    c++;
                    visited[bev[i]]=1;
                    cout << bev[i] << "\n" ;
                    for(int j=0; j<oh[bev[i]].size(); j++)
                    {
                        ind[oh[bev[i]][j]]= ind[oh[bev[i]][j]] - 1;
                    }
                    break;
                }
            }
        }
 
            printf("\n");
    }
    return 0;
}
 
