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
 
#define ll long long
 
int main()
{
    int t;
    scanf("%d",&t);
    for(int T=1; T<=t; T++){
        int n,m,x=0,flag[105],ar[105],value[105];
        bool rev=false;
        scanf("%d %d",&n,&m);
        for(int i=0; i<n; i++) scanf("%d",&ar[i]);
 
        while(m--){
            char ch[2];
            scanf("%s",ch);
            if(ch[0] == 'P'){
                int i,j;
                scanf("%d %d",&i,&j);
                if(rev){
                    i = (n-1)-i;j = (n-1)-j;
                }
                int temp=ar[i];
                ar[i] = ar[j];
                ar[j] = temp;
            }
            else if(ch[0] == 'S'){
                flag[x] = 1;
                scanf("%d",&value[x++]);
            }
            else if(ch[0] == 'M'){
                flag[x] = 2;
                scanf("%d",&value[x++]);
            }
            else if(ch[0] == 'D'){
                flag[x] = 3;
                scanf("%d",&value[x++]);
            }
            else if(ch[0] == 'R'){
                if(rev) rev=false;
                else rev=true;
            }
        }
        printf("Case %d:\n",T);
        if(!rev){
            for(int i=0; i<n; i++){
                for(int j=0; j<x; j++){
                    if(flag[j]==1) ar[i] += value[j];
                    else if(flag[j]==2) ar[i] *= value[j];
                    else if(flag[j]==3) ar[i] /= value[j];
                }
                printf("%d",ar[i]);
                if(i!=n-1) printf(" ");
            }
        }
        else{
            for(int i=n-1; i>=0; i--){
                for(int j=0; j<x; j++){
                    if(flag[j]==1) ar[i] += value[j];
                    else if(flag[j]==2) ar[i] *= value[j];
                    else if(flag[j]==3) ar[i] /= value[j];
                }
                printf("%d",ar[i]);
                if(i) printf(" ");
            }
        }
        printf("\n");
    }
    return 0;
}
 
