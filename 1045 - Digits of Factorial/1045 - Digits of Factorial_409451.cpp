#include<bits/stdc++.h>
 
using namespace std;
 
double Log[1000001];
 
int main(){
    Log[1] = log(1);
    for(int i=2; i<=1000000; i++) Log[i]=log(i)+Log[i-1];
    int t;
    scanf("%d",&t);
    for(int T=1; T<=t;T++){
        int n,b;
        scanf("%d %d",&n,&b);
        printf("Case %d: %d\n",T,int(floor(Log[n]/log(b))+1));
    }
    return 0;
}
