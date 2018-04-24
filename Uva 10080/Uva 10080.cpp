 /*
 Problem name :
 Algorithm : Not Sure Yet
 Contest/Practice :
 Source :
 Comment : Whenever you start to believe  yourself, people also start to believe in you
 Date : --
 Last Update : 25-Mar-2015
*/

#include<bits/stdc++.h>

#define pause           system("pause");
#define FOR(s,e,inc)    for(int i=s;i<=e;i+=inc)
#define mod             1000000007
#define UNIQUE(V) (V).erase(unique((V).begin(),(V).end()),(V).end())//vector must be sorted
#define inf             1<<30
#define pb              push_back
#define ppb             pop_back
#define mp              make_pair
#define F               first
#define S               second
#define sz(x)           ((int)x.size())
#define sqr(x)          ( (x)* (x) )
#define eps             1e-9
#define lcm(x,y)        (abs(x) /gcd(x,y))* abs(y)
#define on(x,w)         x|(1<<w)
#define check(x,w)      (x&(1<<w))
#define all(x)          (x).begin(),(x).end()
#define pf              printf
#define sf              scanf
#define pi              acos(-1.0)
#define reset(x,v)      memset(x,v,sizeof(x));
#define AND             &&
#define OR              ||
#define what_is(x)      cerr<<#x<<" is "<<x<<"\n";

typedef long long ll;
typedef unsigned long long llu;

using namespace std;


template<class T>
inline T mod_v(T num)
{
    if(num>=0)
        return num%mod;
    else
        return (num%mod+mod)%mod;
}
template<class T>
inline T gcd(T a,T b)
{
    a=abs(a);
    b=abs(b);

    while(b) b ^= a ^= b ^= a %= b;
    return a;
}

template<class T>
T fast_pow(T n , T p)
{
    if(p==0) return 1;
    if(p%2)
    {
        T g=mod_v ( mod_v(n) * mod_v(fast_pow(n,p-1)) );
        return g;
    }
    else
    {
        T g=fast_pow(n,p/2);
        g=mod_v( mod_v(g) * mod_v(g) ) ;
        return g;
    }
}

template<class T>
inline T modInverse(T n)
{
    return fast_pow(n,mod-2);
}
 

bool equalTo ( double a, double b ){ if ( fabs ( a - b ) <= eps ) return true; else return false; }
bool notEqual ( double a, double b ){if ( fabs ( a - b ) > eps ) return true; else return false; }
bool lessThan ( double a, double b ){ if ( a + eps < b ) return true; else return false; }
bool lessThanEqual ( double a, double b ){if ( a < b + eps ) return true;   else return false;}
bool greaterThan ( double a, double b ){if ( a > b + eps ) return true;else return false;}
bool greaterThanEqual ( double a, double b ){if ( a + eps > b ) return true;else return false;}

#define debug(args...) {dbg,args; cerr<<endl;}

struct debugger{
    template<typename T> debugger& operator , (const T& v){
        cerr<<v<<" ";
        return *this;
    }
}dbg;

int nextInt() { int n; scanf("%d", &n); return n; }
long long nextLong() { long long n; scanf("%lld", &n); return n; }
void print(int n){ printf("%d", n); }
void println(int n){ printf("%d\n", n); }
void println(long long n){ printf("%lld\n", n); }



template<class T>
inline int in(register T& num)
{
    register char c=0;
    num=0;
    bool n=false;
    while(c<33)c=getchar();
    while(c>33){
        if(c=='-')
            n=true;
        else num=num*10+c-'0';
        c=getchar();
    }
    num=n?-num:num;
    return 1;
}

/******* ! Code start from here ! *******/

#define INF inf
#define MAX 105

// Taken from Tarango Khan .

// Runtime O( sqrt(V) *E ) . For more details, look at wiki page

int N, M, E, R, C;
// N = Maximum number of matching possible from left set.

vector< int > Graph[MAX];
int Left[MAX];
int Right[MAX];
int dist[MAX];
int lCnt = 0,rCnt = 0;
// lCnt = is max number of elements in left set.
// rCnt = is max number of elements in right set.

bool BFS() {
    queue< int > Q;
    for(int i = 1; i<=N; i++) {
        if(Left[i] == 0) {
            dist[i] = 0;
            Q.push(i);
        } else {
            dist[i] = INF;
        }
    }
    dist[0] = INF;
    while(!Q.empty()) {
        int u = Q.front(); Q.pop();
        if(u != 0) {
            int len = Graph[u].size();
            for(int i = 0; i<len; i++) {
                int v = Graph[u][i];
                if(dist[Right[v]] == INF) {
                    dist[Right[v]] = dist[u] + 1;
                    Q.push(Right[v]);
                }
            }
        }
    }
    return (dist[0] != INF);
}

bool DFS(int u) {
    if(u != 0) {
        int len = Graph[u].size(); 
        for(int i = 0; i<len; i++) {
            int v = Graph[u][i]; 
            if(dist[Right[v]] == dist[u]+1) {
                if(DFS(Right[v])) {
                    Right[v] = u;
                    Left[u] = v;
                    return true;
                }
            }
        }
        dist[u] = INF;
        return false;
    }
    return true;
}

int hopcroft_karp() {
    int matching = 0;
    reset(Left,0);
    reset(Right,0);
    N = lCnt;
    while(BFS()){
        for(int i = 1; i<=N; i++){  
            if(Left[i] == 0 && DFS(i)){   
                matching++;
            }
        }
    }
    return matching;
}


pair<double,double> gopher[102],hole[102];

double distance(pair<double,double>a,pair<double,double>b ){

    return ( sqr(a.F-b.F) + sqr(a.S-b.S) );
}

int main()
{
//     std::ios_base::sync_with_stdio(false);

    #ifdef kimbbakar
        freopen ( "E:/Code/in.txt", "r", stdin );
//        freopen ( "E:/Code/out.txt", "w", stdout );
    #endif

    int t,tcase=1;

    int n,m,s,v;

    while(scanf("%d %d %d %d",&n,&m,&s,&v)==4){

        lCnt = n;
        rCnt = m;

        for(int i=1;i<=n;i++){
            scanf("%lf",&gopher[i].F );
            scanf("%lf",&gopher[i].S );
 
            Graph[i].clear();
        }

        for(int i=1;i<=m;i++){
            scanf("%lf",&hole[i].F );
            scanf("%lf",&hole[i].S );
        }

        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){

                if(lessThanEqual(distance( gopher[i],hole[j] ),sqr( s*v)  ) ) 
                    Graph[i].pb(j);                      
            }
        }

        pf("%d\n",n-hopcroft_karp() );

    }




    return 0;
}



