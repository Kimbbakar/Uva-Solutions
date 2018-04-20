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

class abc{
public:

    pair<int,int> pos ;
    int dir;
    int col,cost;

    abc(pair<int,int>pos,int col,int dir,int cost ){
        this ->pos= pos;
        this ->dir = dir;
        this -> col = col;
        this -> cost = cost;
    }

    bool operator < (const abc& x) const{
        cost>x.cost;
    }



};

int dp[30][30][5][4];
int n,m;
char grid[30][30];

int x [] = {-1,0,1,0};
int y[] =  {0,-1,0,1};

int solve(pair<int,int> s,pair<int,int>d ){

    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
            for(int _k=0;_k<5;_k++)
                for(int _l=0;_l<4;_l++)
                    dp[i][j][_k][_l] = inf;

    priority_queue<abc>q;

    dp[s.F][s.S][2][0] = 0;

    q.push(abc(s,2,0,0) );
    int res = inf;

    while(!q.empty()){
        abc nw = q.top();
        q.pop();
     //   what_is(nw.cost)
        if(nw.pos==d and nw.col==2){
             res = min(res,nw.cost );
             continue;
        }

        if(dp[nw.pos.F][nw.pos.S][nw.col][ (nw.dir+1+4)%4 ]>1 + nw.cost ){
            dp[nw.pos.F][nw.pos.S][nw.col][ (nw.dir+1+4)%4 ]  = 1 + nw.cost;
            q.push( abc(nw.pos,nw.col,(nw.dir+1+4)%4,1 + nw.cost ) );
        }

        if(dp[nw.pos.F][nw.pos.S][nw.col][ (nw.dir-1+4)%4 ]>1 + nw.cost ){
            dp[nw.pos.F][nw.pos.S][nw.col][ (nw.dir-1+4)%4 ]  = 1 + nw.cost;
            q.push( abc(nw.pos,nw.col,(nw.dir-1+4)%4,1 + nw.cost ) );
        }

        int xp = nw.pos.F+x[nw.dir];
        int yp = nw.pos.S+y[nw.dir];

        if(xp<n and yp<m and xp>=0 and yp>=0 and grid[xp][yp]!='#' and dp[xp][yp][ (nw.col+1)%5 ][nw.dir]>nw.cost+1  ){
            dp[xp][yp][ (nw.col+1)%5 ][nw.dir]=nw.cost+1;

            q.push(abc({xp,yp},(nw.col+1)%5,nw.dir,nw.cost+1  ) );
        }
    }


    return res;
}


int main()
{
//     std::ios_base::sync_with_stdio(false);

    #ifdef kimbbakar
        freopen ( "in.txt", "r", stdin );
//        freopen ( "out.txt", "w", stdout );
    #endif

    int t,tcase = 1;


    while(1){
        in(n),in(m);
        if(n==0 and m==0) break;

        if(tcase>1)
        pf("\n");


        pair<int,int>s,d;

        for(int i=0;i<n;i++){
            scanf("%s",grid[i] );

            for(int j=0;j<m;j++){
                if(grid[i][j]=='S' )
                s = {i,j};
                else if(grid[i][j]=='T' )
                d = {i,j};
            }
        }

        int res = (solve(s,d));

        pf("Case #%d\n",tcase++);

        if(res==inf)
            pf("destination not reachable\n");
        else pf("minimum time = %d sec\n",res);
    }

    return 0;
}

