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
#include<cstring>
 
using namespace std;
 
char land[50][50];
int row,column,cont,visit[50][50];
 
void path(int raw,int col){
 
    if(col >= column || col < 0 || raw >= row || raw <0)
    {
        return;
    }
    else if(visit[raw][col] == 1){
        return;
    }
    else
    {
            cont++;
            visit[raw][col] = 1;
            path(raw,col+1);
            path(raw+1,col);
            path(raw-1,col);
            path(raw,col-1);
 
    }
}
 
int main()
{
    char cas[5];
    int t,ca=0;
    gets(cas);
    t = atoi(cas);
    while(t--){
 
        scanf("%d %d",&column,&row);
        for(int i=0; i<row; i++ ){
            char ch[50];
            scanf("%s",ch);
            strcpy(land[i],ch);
        }
        int r,c;
        cont=0;
        for(int i=0; i<row; i++){
            for(int j=0; j<column;j++){
 
                if(land[i][j] == '#'){
                    visit[i][j] = 1;
                }
                else{
                    visit[i][j]=0;
                }
                if(land[i][j] == '@'){
                    r = i;
                    c = j;
                }
            }
        }
        path(r,c);
        printf("Case %d: %d\n",++ca,cont);
    }
    return 0;
}
 
