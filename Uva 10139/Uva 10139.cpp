 /*
 Problem name : 10139 - Factovisors
 Algorithm : Sieve + Prime Factor
 Contest/Practice :
 Source : Uva   
 Comment : Whenever you start to believe  yourself, people also start to believe in you
 Date : 10-Apr-18
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

#define MAX 1000000
vector<int>prime;
int mark[MAX+5];

void sieve()
{
    prime.pb(2);

    for(int i=4;i<=MAX;i+=2)
        mark[i]=1;

    mark[1]=1;

    for(int i=3;i<=MAX;i+=2)
    {
        if(!mark[i])
        {
            prime.pb(i);

            for(ll j=(ll)i*i;j<=MAX;j+=(2*i))
                mark[j]=1;
        }
    }
}

bool solve(int n,int m){

    if(!n)
        n = 1;

    int lm = sqrt(m);

    for(int i=0;i<sz(prime) and prime[i]<=lm;i++ ){
        int p = prime[i];

        if(m%p==0){
            int cnt = 0;
            while(m%p==0){
                m/=p;
                cnt++;
            }

            for(int j=p;j<=n and cnt;j+=p){
                int tmp = j;
                  while(tmp%p==0 and cnt){
                    cnt--;
                    tmp/=p;
                }
            }

            if(cnt) return false;

            lm = sqrt(m);
        }

    }

    if(m>n) return false;

    return true;

} 


int main()
{
//     std::ios_base::sync_with_stdio(false);

    #ifdef kimbbakar
        freopen ( "E:/Code/in.txt", "r", stdin );
        freopen ( "E:/Code/out.txt", "w", stdout );
    #endif

    sieve();

    int n,m;

    while(scanf("%d %d",&n,&m)==2){

        if(solve(n,m))
            pf("%d divides %d!\n",m,n);
        else 
            pf("%d does not divide %d!\n",m,n);
    }

    return 0;
}



