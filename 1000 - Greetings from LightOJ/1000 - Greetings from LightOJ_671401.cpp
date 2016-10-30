#include<bits/stdc++.h>
 
using namespace std;
 
 
 
 
int main(){
    int tt[1000000];
    int a[125],b[125],t,result[125]={0},i,j;
    scanf("%d",&t);
 
        for(i=0;i<t;i++){
            scanf("%d",&a[i]);
            scanf("%d",&b[i]);
            result[i]=a[i]+b[i];
            printf("Case %d: %d\n",i+1,result[i]);
        }
 
    return 0;
}
 
