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

double val;
int n,d,x,y,z;
int favA[40];
int favB[40];
int done[102][102][102 ],cc=1;
double dp[102][102][102 ];

double re(int p,int cA,int cB){
    if(p==d){
        return (cA*2==cB) * val;
    }
    double &res = dp[p][cA][cB];
    if(done[p][cA][cB]==cc ) return res;
    done[p][cA][cB]= cc;
    
    res = 0;

    res += x*re(p+1,cA+1,cB) ;
    res += y*re(p+1,cA,cB+1) ;
    res += z*re(p+1,cA+1,cB+1) ;
    res += (n-x-y-z) *re(p+1,cA,cB) ;


    return res;


}

int main()
{
//     std::ios_base::sync_with_stdio(false);

    #ifdef kimbbakar
        freopen ( "E:/Code/in.txt", "r", stdin );
//        freopen ( "E:/Code/out.txt", "w", stdout );
    #endif

    int t,tcase= 1;

    while(1){
        in(n);

        if(n==0) break;  

        int var;
        reset(favA,0);
        reset(favB,0);


        in(d);
        x = d;


        while(d--){
            in(var);

            favA[var] =1;
        }

        in(d);
        y = d;

        while(d--){
            in(var);

            favB[var] =1;
        }

        z = 0;

        for(int i=1;i<=n;i++)
            if(favA[i] and favB[i])
                x--,y--,z++;


        in(d);

        val = 1.0;

        for(int i=0;i<d;i++)
            val/=double(n);

        double res = re(0,0,0);

        if(equalTo(0,res))
            res = 0;

        pf("Case %d: %.5f\n",tcase++, res);

        cc++;

    }



    return 0;
}

