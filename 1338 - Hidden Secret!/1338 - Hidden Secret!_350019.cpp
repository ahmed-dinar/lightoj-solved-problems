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
 
void mx(char X[],char Y[])
{
    if(strlen(X) < strlen(Y))
    {
        char temp[102];
        strcpy(temp,X);
        strcpy(X,Y);
        strcpy(Y,temp);
    }
}
 
char Xchange(char XX)
{
    if(isupper(XX))
        return tolower(XX);
    else
        return toupper(XX);
}
 
int main()
{
    char test[5];
    gets(test);
    int t = atoi(test),ca=0;
    while(t--)
    {
        char N[102],M[102],T,P[102];
        gets(N);
        gets(M);
        mx(M,N);
        int flag,k = 0 ;
        for(int i=0; i<strlen(N); i++)
        {
            flag = 0;
            for(int j=0; j<strlen(M); j++)
            {
                if(M[j] != '.')
                {
                    T = M[j];
                    M[j] = Xchange(M[j]);
                    if(N[i] == T || M[j] == N[i])
                    {
                        P[k] = N[i];
                        flag = 1;
                        M[j] = '.';
                        k++;
                        break;
                    }
                }
            }
            if(flag == 0)
            {
                break;
            }
        }
        P[k] = '\0';
        if(strcmp(P,N) == 0)
            printf("Case %d: Yes\n",++ca);
        else
            printf("Case %d: No\n",++ca);
    }
    return 0;
}
 
