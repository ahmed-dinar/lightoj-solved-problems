#include<bits/stdc++.h>
 
using namespace std;
 
#define all(x) x.begin(),x.end()
#define Find(x,n) find(all(x),n)
#define pi acos(-1.0)
#define i64 long long
#define pb(x) push_back(x)
#define mset(x,v) memset(x,v,sizeof(x))
#define sc(n) scanf("%d",&n)
#define scl(n) scanf("%ld",&n)
#define scll(n) scanf("%lld",&n)
#define scd(n,m) scanf("%d %d",&n,&m)
#define scdl(n,m) scanf("%ld %ld",&n,&m)
#define scdll(n,m) scanf("%lld %lld",&n,&m)
#define filein freopen("in.txt","r",stdin)
#define fileout freopen("my.txt","w",stdout)
#define FOR(i,n) for(int i=0;i<n; i++)
#define inf 2000000.0
 
 
bool isUpper(char ch){ if( ch>='A' && ch<='Z' ) return true; return false; }
bool isLower(char ch){ if( ch>='a' && ch<='z') return true; return false;}
bool isLetter(char ch){ if( ch>='A' && ch<='Z' || ch>='a' && ch<='z') return true; return false; }
bool isDigit(char ch){ if( ch>='0' && ch<='9') return true; return false; }
char toLower(char ch){ if (isUpper(ch)) return (ch+32); return ch; }
char toUpper(char ch){ if (isLower(ch)) return (ch-32); return ch; }
 
template<class T>bool isEven(T a){ return (a%2==0);}
template<class T>T sq(T a){ return a*a; }
template<class T>T gcd(T a,T b){ return b==0 ? a : gcd(b,a%b); }
template<class T>T lcm(T a,T b){ return (a/gcd(a,b))*b; }
template<class T>bool isPrime(T n){ for(T i=2; i*i<=n; i++){ if(n%i==0) return false; } return true; }
template<class T>T Pow(T n,T p) { T res=n; for(T i=1;i<p; i++){ res *= n; } return res; }
template<class T>T Max(T n,T p) { if(n>=p) return n; return p; }
 
 
struct node
{
    i64 complete_word;
    node *next[5];
    node() {
        complete_word = 0;
    for(int i=0;i<5; i++)
        next[i]=NULL;
    }
};
 
node *root;
 
int getInt(char ch){
    if(ch=='A') return 0;
    if(ch=='C') return 1;
    if(ch=='G') return 2;
    if(ch=='T') return 3;
}
 
i64 Insert(char *s,int sz){
    node *word = root;
    i64 res=0;
    for(int i=0;i<sz;i++){
        int w=getInt(s[i]);
        if(word->next[w]==NULL){
            word->next[w] = new node();
        }
        word = word->next[w];
        word->complete_word++;
        res = Max(res,word->complete_word*(i+1));
    }
    return res;
}
 
void Clear(node *n){
    for(int i=0;i<5; i++)
        if(n->next[i])
            Clear(n->next[i]);
    delete(n);
}
 
/*int Search(char *s,int sz){
    node *word = root;
    for(int i=0;i<sz;i++){
        int w=s[i]-'0';
        if(word->next[w]==NULL) return false;
        word = word->next[w];
    }
    return word->complete_word;
}
*/
 
int main()
{
  
    int t,T=0;
    sc(t);
    while(t--){
        int n;
        i64 res=0;
        char s[55];
        root = new node();
        sc(n);
        for(int i=0;i<n;i++){
            scanf("%s",s);
            int ln=strlen(s);
            i64 r = Insert(s,ln);
            res = Max(res,r);
        }
        printf("Case %d: %lld\n",++T,res);
        Clear(root);
    }
    return 0;
}
 
 
