 #include <stdio.h>
 #include <stdlib.h>
 #include <string.h>
 
 #define ll long long
 #define mod 15000000000000
 ll ans[15010];
 
void fibo(ll s,ll f,ll range)
{
    ans[0]=s;
    ans[1]=f;
    ll sum=1%mod,ii;
    for(ii=2; ii<=range; ii++)
    {
        sum=(s%mod+f%mod)%mod;
        s=f;
        f=sum;
        ans[ii]=f;
    }
}
 
int main()
{
    ll x,y,l,k,ca=0;
    ll digit,t,i,DIGIT[5],flag;
    scanf("%lld",&t);
    while(t--)
    {
        scanf("%lld %lld %lld %lld",&x,&y,&l,&digit);
        if(digit==4){
            fibo(x,y,15000);
            k=ans[l%15000];
        }
        else if(digit==3){
            fibo(x,y,1500);
            k=ans[l%1500];
        }
        else if(digit==2){
            fibo(x,y,300);
            k=ans[l%300];
        }
        else if(digit==1){
            fibo(x,y,60);
            k=ans[l%60];
        }
        for(i=0; i<digit; i++){
                DIGIT[i]=k%10;
                k=k/10;
        }
        flag=0;
        printf("Case %lld: ",++ca);
        for(i=digit-1; i>=0; i--){
                if(DIGIT[i]==0 && flag==0)
                    continue;
                printf("%lld",DIGIT[i]);
                flag=1;
        }
        if(flag==0){
            printf("0");
        }
        printf("\n");
    }
    return 0;
}
 
