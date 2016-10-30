#include<stdio.h>
#include<stdlib.h>
#include<string.h>
 
void strr(char ch[],char chrr[])
{
    int x,y;
    y = 0;
    for(x=strlen(ch)-1; x>=0; x--)
    {
        chrr[y] = ch[x];
        y++;
    }
    chrr[y] = '\0';
}
 
int main()
{
    long long amount,nam;
    int n,i,j,m,cas=0;
    char k[15],ts[5],report[8]={"report"},am[15],newn[15],tst[7];
    gets(ts);
    n = atoi(ts);
    while(n--)
    {
 
        gets(tst);
        m = atoi(tst);
        printf("Case %d:\n",++cas);
        amount = 0;
        while(m--)
        {
            gets(k);
            if( strcmp(k,report) == 0)
            {
                printf("%lld\n",amount);
            }
            else
            {
                for(i=strlen(k)-1,j=0; k[i] != ' '; i--,j++)
                {
                    am[j] = k[i];
                }
                am[j] = '\0';
                strr(am,newn);
                nam = atoi(newn);
                amount = amount + nam;
            }
        }
    }
    return 0;
}
 
