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
#define MAX 1005

// Taken from Tarango Khan .

// Runtime O( sqrt(V) *E ) . For more details, look at wiki page

int N, M, E, R, C;
// N = Maximum number of matching possible from Left set.

vector< int > Graph[MAX];
int Left[MAX];
int Right[MAX];
int dist[MAX];
int lCnt = 0,rCnt = 0;
// lCnt = is max number of elements in Left set.
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

int lcover[2*MAX]; // If lcover[i] is 1, then ith node of Left side is a member of vertex cover
int rcover[2*MAX]; // If rcover[i] is 1, then ith node of right side is a member of vertex cover
int vis[2*MAX],cc;
void findVertexCover ( int n,int m ) {
    queue<int> q;
    cc++;
    for(int i=1;i<=n;i++){
        if ( Left[i] == 0 ) {
            q.push ( i ); 
            vis[i] = cc;  
        }
    };

    while ( !q.empty() ) {
        int s = q.front(); q.pop();
        for(auto i:Graph[s] ) {
            int t =i;
            if ( t == Left[s] ) continue;

            int xt = t + n;
            if ( vis[xt] == cc ) continue;

            vis[xt] = cc;  
            xt = Right[t];

            if ( xt != 0 && vis[xt] != cc ) {
                vis[xt] = cc;
                q.push ( xt );
            }

        };
    }

    for(int i=1;i<=n;i++){
        if ( vis[i] != cc ) lcover[i] = 1;
        else lcover[i] = 0;
    };
    for(int i=1;i<=m;i++){ 
        if ( vis[i+n] == cc ) rcover[i] = 1;
        else rcover[i] = 0;

         
    };

}


int main()
{
//     std::ios_base::sync_with_stdio(false);

    #ifdef kimbbakar
        freopen ( "E:/Code/in.txt", "r", stdin );
        freopen ( "E:/Code/out.txt", "w", stdout );
    #endif

    int n,m,z,x,y;

    while(1){

        in(n),in(m),in(z);

        if(n+m+z==0) break;

        lCnt = n;
        rCnt = m;

        for(int i=1;i<=n;i++) 
            Graph[i].clear();
 
        for(int i=1;i<=z;i++){
            in(x),in(y);
            Graph[x].pb(y);
        }

        pf("%d",hopcroft_karp());

        findVertexCover(n,m);

        for(int i=1;i<=n;i++) 
            if(lcover[i] )
                pf(" r%d",i);
        for(int i=1;i<=m;i++) 
            if(rcover[i] )
                pf(" c%d",i); 
 
          

        pf("\n");


    }




    return 0;
}



