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
 
char permutation[30];
int check[30]={0};
int K,KK;
 
void P(int k,char w[],int ln)
{
    if(K == KK)
        return;
    if(k == ln)
    {
        permutation[k] = '\0';
        printf("%s\n",permutation);
        KK++;
        return;
    }
    else
    {
        for(int x=0; x<strlen(w); x++)
        {
            if(check[x] == 0)
            {
                check[x] = 1;
                permutation[k] = w[x];
                k++;
                P(k,w,ln);
                check[x] = 0;
                k--;
            }
        }
    }
}
 
int main()
{
    int t,ca=0;
    scanf("%d",&t);
    while(t--)
    {
        int N;
        char word[]={"ABCDEFGHIJKLMNOPQRSTUVWXYZ"};
        scanf("%d %d",&N,&K);
        word[N] = '\0';
        KK = 0;
        printf("Case %d:\n",++ca);
        P(0,word,N);
    }
    return 0;
}
