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
    char f[102];
    char test[4];
    char N[5];
    scanf("%s",test);
    int t=atoi(test),ca=0;
    while(t--){
       scanf("%s %s",N,f);
       int sz=strlen(f);
       int co=0,crew=0;
       int flag=0;
       for(int i=0; i<sz; i++){
            if(f[i]=='.')
                co++;
            if(co==3){
                crew++;
                co=0;
                flag=1;
            }
 
            if(f[i]=='.' && f[i+1]=='#' && f[i+2] == '#' && flag==0){
                crew++;
                co=0;
                i=i+2;
                flag=0;
                continue;
            }
 
            if(f[i]=='.' && f[i+1]=='#' && co==2 && flag==0){
                crew++;
                co=0;
                i=i+1;
                flag=0;
                continue;
            }
            if(f[i]=='.' && f[i+1]=='#' && f[i+2] == '.' && co==1 && flag==0){
                crew++;
                co=0;
                i=i+2;
                flag=0;
                continue;
            }
            flag=0;
       }
       if(co!=0)
        crew++;
       printf("Case %d: %d\n",++ca,crew);
    }
    return 0;
}
 
 
 
 
 
 
 
 
 
 
 
