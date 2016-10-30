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
     int t,ca=0;
    char test[5];
    char month[15],month2[15];
    int day,day2;
    long year,year2,co,i;
    char ch;
    scanf("%d",&t);
 
    while(t--){
 
        scanf("%s %d, %ld",month,&day,&year);
        scanf("%s %d, %ld",month2,&day2,&year2);
 
        if( strcmp(month,"January")!=0 && strcmp(month,"February")!=0)
            year++;
 
        if ( (strcmp(month2,"January")==0 ) || (strcmp(month2,"February")==0 && day2<29) )
            year2--;
 
        co = (year2/4)-((year-1)/4);
        co -= (year2/100)-((year-1)/100);
        co += (year2/400)-((year-1)/400);
        printf("Case %d: %ld\n",++ca,co);
    }
    return 0;
}
 
