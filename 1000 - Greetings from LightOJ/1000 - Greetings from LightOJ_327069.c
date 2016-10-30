#include <stdio.h>
 
int main()
{
    int c,a,b,s,cas=1;
    scanf("%d",&c);
    while(c--)
    {
        scanf("%d %d",&a,&b);
        s = a+b;
        printf("Case %d: %d\n",cas++,s);
    }
    return 0;
}
