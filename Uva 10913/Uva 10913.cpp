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

class node
{
public:
    pair<int,int>par;
    pair<int,int>pos;
    ll val;
    int neg;

    node(pair<int,int>pos,pair<int,int>par,ll val,int neg ){
        this->par = par;
        this->pos =pos;
        this->val = val;
        this->neg = neg;
    }

    bool operator < (const node& abc) const{
        return val<abc.val;

    }

};


int given[100][100];
ll dp[100][100][7][4] ;
int n,k;
int x[] = {0,1,0};
int y[] = {1,0,-1};

ll dijkstra(){
    priority_queue<node>q;

    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
            for(int _k=0;_k<=k+1;_k++)
                for(int l=0;l<=3;l++)
                    dp[i][j][_k][l]  = -(1LL<<40);


    dp[1][1][(given[1][1]<0)][0] = given[1][1];

    q.push( node({1,1},{-1,-1},dp[1][1][(given[1][1]<0)][0] ,(given[1][1]<0)) );

    ll res = -(1LL<<50);

    while(!q.empty() ){
        node nw = q.top();
        q.pop();



       // if(nw.neg>k ) continue;
           //  debug(nw.pos.F,nw.pos.S,nw.val,nw.neg)

        if(nw.pos==mp(n,n) ) {
            res = max(nw.val,res);
            continue;
        }

        for(int i=0;i<3;i++){
            pair<int,int> tmp = {nw.pos .F+x[i],nw.pos.S+y[i] };

            
/*            debug(tmp.F,tmp.S,(given[tmp.F][tmp.S] + nw.val ) )
            debug("Par: ",nw.par.F,nw.par.S)
  
*/

            if(tmp.F<1 or tmp.S<1 or tmp.F>n or tmp.S>n or tmp==nw.par) continue;


            if((given[tmp.F][tmp.S]<0 ) + nw.neg>k or dp[tmp.F][tmp.S ][ (given[tmp.F][tmp.S]<0 ) + nw.neg ][i] >=(given[tmp.F][tmp.S] + nw.val ) )
                continue;

            dp[tmp.F][tmp.S ] [ (given[tmp.F][tmp.S]<0 ) + nw.neg ][i] = (given[tmp.F][tmp.S] + nw.val ) ;                
                
            q.push(node(tmp,nw.pos, dp[tmp.F][tmp.S ] [ (given[tmp.F][tmp.S]<0 ) + nw.neg ][i] ,(given[tmp.F][tmp.S]<0 ) + nw.neg  ) );
        }   

    }

    return res;
}


int main()
{
//     std::ios_base::sync_with_stdio(false);

    #ifdef kimbbakar
        freopen ( "E:/Code/in.txt", "r", stdin );
        freopen ( "E:/Code/out.txt", "w", stdout );
    #endif

    int tcase=1;

    while(1){
        in(n),in(k);

        if(n==0 and k==0) break;

        for(int i=1;i<=n;i++)
            for(int j=1;j<=n;j++)
                in(given[i][j] );

        ll res = dijkstra();

        pf("Case %d: ",tcase++);

        if(res==-(1LL<<50))
            pf("impossible\n");
        else pf("%lld\n",res);

    }


    return 0;
}


