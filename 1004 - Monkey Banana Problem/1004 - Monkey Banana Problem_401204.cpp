#include<bits/stdc++.h>
 
using namespace std;
 
#define inf 2147483646
 
int ar[205][205];
int row,N;
int col[205];
int dp[205][205];
 
int monkey(int i,int j){
 
    if( (i>=1&&i<=row) && (j>=0&&j<col[i]) ){
 
        if(dp[i][j] != -1) return dp[i][j];
 
        int bananas = -inf;
        if(i<N){
            bananas = max(bananas,monkey(i+1,j)+ar[i][j]);
            bananas = max(bananas,monkey(i+1,j+1)+ar[i][j]);
        }
        else{
            bananas = max(bananas,monkey(i+1,j-1)+ar[i][j]);
            bananas = max(bananas,monkey(i+1,j)+ar[i][j]);
        }
        return dp[i][j] = bananas;
    }
    else
        return 0;
}
 
int main(){
 
    //freopen("in.txt","r",stdin);
 
    int t;
    scanf("%d",&t);
    for(int T=1; T<=t; T++){
        scanf("%d",&N);
        row = N*2-1;
        for(int i=1; i<=N; i++){
            col[i] = i;
            for(int j=0; j<i; j++)
                scanf("%d",&ar[i][j]);
        }
        for(int i=N+1,k=1; i<=row; i++,k++){
            col[i] = (N-k);
            for(int j=0; j<(N-k); j++)
                scanf("%d",&ar[i][j]);
        }
        memset(dp,-1,sizeof(dp));
        printf("Case %d: %d\n",T,monkey(1,0));
    }
    return 0;
}
 
