/*
Ahmed Dinar
CSE,JUST
*/
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
 
#define input( f ) freopen( f, "r", stdin )
#define PI 3.14159265358979323846264338327950
#define inf 2147483647
#define ll long long
#define FOR(i,n) for(int i=0;i<n;i++)
#define test(T,t) for(int T=1;T<=t;T++)
#define pb(v,n) v.push_back(n)
#define Size(n) n.size()
#define len(s) strlen(s)
#define all(n) n.begin(),n.end()
#define mem(n,v) memset(&n,v,sizeof(n))
#define Case(T) printf("Case %d: ",T)
 
struct all
{
    string name;
    long volume;
}stok[110];
 
int main()
{
    //input("i");
 
    int t;
    scanf("%d",&t);
    test(T,t)
    {
        int n;
        map<long,int>Count;
        long CON=-1;
        scanf("%d",&n);
        for(int i=0; i<n; i++)
        {
            string name;
            long a,b,c;
            cin >> stok[i].name;
            scanf("%ld %ld %ld",&a,&b,&c);
            stok[i].volume = a*b*c;
            Count[a*b*c]++;
        }
        string thief,victim;
        Case(T);
        if(n==2)
        {
            if( stok[0].volume == stok[1].volume ){
                 printf("no thief\n");
            }
            else{
                if(  stok[0].volume > stok[1].volume ){
                    thief = stok[0].name;
                    victim = stok[1].name;
                }
                else{
                    thief = stok[1].name;
                    victim = stok[0].name;
                }
                printf("%s took chocolate from %s\n",thief.c_str(),victim.c_str());
            }
            continue;
        }
        if(n==3)
        {
            if(stok[0].volume == stok[1].volume && stok[1].volume == stok[2].volume){
                printf("no thief\n");
            }
            else
            {
                long mx=stok[0].volume,mn=stok[0].volume;
                thief = stok[0].name;
                victim = stok[0].name;
                for(int i=1; i<n ; i++)
                {
                    if(mx<stok[i].volume){
                        mx = stok[i].volume;
                        thief = stok[i].name;
                    }
                    if(mn>stok[i].volume){
                        mn = stok[i].volume;
                        victim = stok[i].name;
                    }
                }
                printf("%s took chocolate from %s\n",thief.c_str(),victim.c_str());
            }
            continue;
        }
        bool is_thief = false;
        for(int i=0; i<n ; i++)
        {
             if(Count[stok[i].volume] == 1){
                is_thief = true;
                if(CON == -1){
                    CON = stok[i].volume;
                    thief = stok[i].name;
                }
                else{
                    if( CON < stok[i].volume ){
                        victim = thief;
                        thief = stok[i].name;
                    }
                    else{
                        victim = stok[i].name;
                    }
                    break;
                }
             }
        }
        if(is_thief)
            printf("%s took chocolate from %s\n",thief.c_str(),victim.c_str());
        else
            printf("no thief\n");
    }
    return 0;
}
 
