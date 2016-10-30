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
#define inf 10000.0
#define MAX 20002
 
 
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
 
map<int,int>id;
map<int,int>is;
vector<int>g[MAX];
vector<int>node;
 
int bfs(){
    int sz = node.size();
    int res=0;
    for(int i=0;i<sz;i++){
        int ele=node[i];
        int s=g[ele].size();
        if(id[ele]==0 && s>0){
            queue<int>q;
            q.push(ele);
            id[ele]=1;
            int vampires=1,lykans=0;
            while(!q.empty()){
                int u=q.front();
                q.pop();
                s=g[u].size();
                for(int j=0;j<s;j++){
                    int v=g[u][j];
                    if(id[v]==0){
                        if(id[u]==1){
                            lykans++;
                            id[v]=2;
                        }
                        else{
                            vampires++;
                            id[v]=1;
                        }
                        q.push(v);
                    }
                }
                g[u].clear();
            }
            res += Max(vampires,lykans);
        }
    }
    return res;
}
 
int main()
{
    //filein;
 
    int t;
    sc(t);
    for(int T=1;T<=t; T++){
        int n,va=0,ly=0;
        sc(n);
        for(int i=0;i<n;i++){
            int u,v;
            scd(u,v);
            g[u].pb(v);
            g[v].pb(u);
            if(!is[u]){
                is[u]=1;
                node.pb(u);
            }
            if(!is[v]){
                is[v]=1;
                node.pb(v);
            }
        }
        printf("Case %d: %d\n",T,bfs());
        id.clear();
        node.clear();
        is.clear();
    }
    return 0;
}
 
 
/*
 
ans = 7 1 3 1 2 3  9 7 5 2 10  3 4 7 5 6 6 7 4 6 11
 
21
8
1 2
2 3
3 4
3 5
6 7
7 8
7 9
7 10
1
100 200
3
1 10
10 20
5 40
1
5 40
4
1 2
2 3
3 4
1 4
4
30 35
30 40
10 20
5 40
10
171 113
48 146
37 166
176 113
182 42
48 42
153 131
133 167
127 86
27 64
8
39 61
26 19
2 75
65 19
51 84
26 41
83 37
36 66
7
12 11
15 9
5 14
10 8
5 8
15 6
12 6
4
1 2
2 3
3 4
1 4
10
1 11
1 12
1 13
1 14
1 15
21 31
21 32
21 33
21 34
21 35
5
1 4
1 5
6 2
3 6
2 5
6
11 7
3 10
3 6
2 6
10 2
11 4
9
11 8
2 8
7 4
8 3
8 9
3 4
2 4
4 6
5 4
14
5 4
1 6
12 9
4 10
5 2
1 10
8 6
12 8
10 2
8 10
8 3
2 12
5 9
10 9
10
11 3
1 12
10 9
10 8
3 9
5 6
7 8
6 12
10 6
4 5
9
7 12
3 9
11 4
1 11
8 11
5 8
9 5
9 11
7 6
14
2 3
9 2
12 6
1 11
9 6
1 10
12 2
8 11
1 9
9 8
2 7
8 3
2 11
6 4
6
2 10
7 3
10 5
7 2
9 12
2 12
14
1 11
12 7
6 11
11 5
1 8
6 12
9 7
2 12
4 6
2 9
7 8
8 6
8 3
9 3
18
2 7
5 17
14 13
9 6
19 14
16 20
13 11
10 18
14 6
7 20
3 19
11 6
1 19
16 8
12 17
3 7
14 16
12 4
*/
 
