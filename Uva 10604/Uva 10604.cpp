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

int kp[7][7][2];
int a[7];
int k;
int n;
int dp[10][10][10][10][10][10];
 
int re(int n1,int n2,int n3,int n4,int n5,int n6){

  //  pf("%d %d %d %d %d %d\n",n1,n2,n3,n4,n5,n6);

    if(n1+n2+n3+n4+n5+n6==max(n1,max(n2,max(n3,max(n4,max(n5,n6))))) ){
        return 0;
    }

    int &res=dp[n1][n2][n3][n4][n5][n6];

    if(res!=-1) return res;

    int rst[]={0,n1,n2,n3,n4,n5,n6};

    res=inf;

    for(int x=1;x<=n;x++){
        for(int y=1;y<=n && rst[x];y++){
            if((x==y && rst[x]<=1) || !rst [y] )
                continue;

            rst[x]--;
            rst[y]--;
            rst[kp[x][y][0] ]++; 

            res=min(res,kp[x][y][1]+re(rst[1],rst[2],rst[3],rst[4],rst[5],rst[6]) );
            rst[x]++;
            rst[y]++;
            rst[kp[x][y][0] ]--;


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

    int t,tcase=1;

    in(t);
    char ch;

    while(t--){
        in(n);

        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                in(kp[i][j][0]);
                in(kp[i][j][1]);
            }
        }

        in(k);

        reset(a,0);
        int v;

        for(int i=1;i<=k;i++){
            in(v);
            a[v]++;            
        }


        reset(dp,-1);

        int res=re(a[1],a[2],a[3],a[4],a[5],a[6]) ;


        pf("%d\n",res);

        cin>>ch;
    }


    return 0;
}