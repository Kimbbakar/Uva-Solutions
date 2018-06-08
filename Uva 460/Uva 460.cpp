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


int rec1[4];
int rec2[4];
int Nrec[4];


void solve(int p1,int p2){

    if(rec1[p1]<=rec2[p1] and rec2[p2]<=rec1[p2] ){
        Nrec[p1] = rec2[p1];
        Nrec[p2] = rec2[p2];
    }

    else if(rec2[p1]<=rec1[p1] and rec1[p2]<=rec2[p2] ){
        Nrec[p1] = rec1[p1];
        Nrec[p2] = rec1[p2];
    }

    else if(rec2[p1]<=rec1[p2] and rec1[p2]<=rec2[p2] ){
        Nrec[p1] = rec2[p1];
        Nrec[p2] = rec1[p2];
    }
    else if(rec2[p1]<=rec1[p1] and rec1[p1]<=rec2[p2] ){
        Nrec[p1] = rec1[p1];
        Nrec[p2] = rec2[p2];
    }
    else{
        Nrec[p1] = 0;
        Nrec[p2] = -1;
    }

}

int main()
{
//     std::ios_base::sync_with_stdio(false);

    #ifdef kimbbakar
        freopen ( "in.txt", "r", stdin );
//        freopen ( "out.txt", "w", stdout );
    #endif

    int t,tcase=1;


    in(t);

    while(t--){

        for(int i=0;i<4;i++)
            in(rec1[i] );

        for(int i=0;i<4;i++)
            in(rec2[i] );

        solve(0,2);
        solve(1,3);

        ll area = (ll)(Nrec[2]-Nrec[0] + 1 ) * (ll)(Nrec[3]-Nrec[1] + 1 );

        if(area>=1 and !( (area== (Nrec[2]-Nrec[0] + 1) ) or (area== (Nrec[3]-Nrec[1] + 1) ) ))
            pf("%d %d %d %d\n",Nrec[0],Nrec[1],Nrec[2],Nrec[3] );
        else pf("No Overlap\n");

        if(t)
            pf("\n");

    }


    return 0;
}


