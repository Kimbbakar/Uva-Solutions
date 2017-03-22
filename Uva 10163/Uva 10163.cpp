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

pair<int,int>dp[33][103];
int cost[103];

pair<int,int> re(int p,int n){  
    if(p==0){
        if(n)
            return mp(-inf,inf);
        else return mp(inf,0);
    }

    if(dp[p][n].F!=-1) return dp[p][n];

    pair<int,int>&res=dp[p][n];

    res=re(p-1,n);

    for(int i=1;i<=n;i++){
        pair<int,int>tmp=re(p-1,n-i);

        tmp.F=min(tmp.F,cost[p]/i);            
        tmp.S=tmp.S+cost[p];            
        

        if((tmp.F>res.F) || (tmp.F==res.F && tmp.S<=res.S) )
            res=tmp;

    }

    return res;
}

int g;

pair<int,int> re1(int p,int n){  
    
    if(p==0){
        if(n)
            return mp(-inf,inf);
        else return mp(inf,0);
    }

    if(dp[p][n].F!=-1) return dp[p][n];  

    pair<int,int>&res=dp[p][n];
     
    res=re1(p-1,n);

    for(int i=1;i<=n;i++){
        pair<int,int>tmp=re1(p-1,n-i);

        tmp.F=min(tmp.F,cost[p]/i);            
        tmp.S=tmp.S+cost[p];            
        

        if((tmp.F>=g && tmp.S<=res.S) ){
           
            res=tmp;

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

    int n,m;

    while(scanf("%d %d",&n,&m)==2){
        if(n==m && n==0) break;
        for(int i=1;i<=m;i++)
            in(cost[i]);

        reset(dp,-1);

        g=re(m,n).F;
        reset(dp,-1);
        
        pf("%d %d\n",g,(re1(m,n).F==0?0:re1(m,n).S) );


    }


    return 0;
}