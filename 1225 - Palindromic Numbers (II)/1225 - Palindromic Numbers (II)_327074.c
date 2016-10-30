#include <stdio.h>
 
int main()
{
    long long a,c,b,cas;
    int ca = 1;
    scanf("%lld",&cas);
    while(cas--)
    {
        scanf("%lld",&a);
        if( a < 10)
        {
            printf("Case %d: Yes\n",ca++);
            continue;
        }
        c = a;
        b=0;
        while( c%10 == 0)
            {
                c = c/10;
            }
        while(c%10 != 0)
        {
                b = b*10 + c%10;
                c = c/ 10;
                while ( c != 0 && c%10 == 0 )
                {
                    c = c/10;
                    b = b*10;
                }
        }
        if( b == a)
        {
             printf("Case %d: Yes\n",ca++);
        }
        else
        {
            printf("Case %d: No\n",ca++);
        }
    }
    return 0;
}
 
