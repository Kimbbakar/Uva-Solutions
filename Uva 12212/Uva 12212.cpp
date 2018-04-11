 /*
 Problem name : 12212 - Password Remembering
 Algorithm : Digit DP + Inclusion-Exclusion 
 Contest/Practice :
 Source : UVa
 Comment : Whenever you start to believe  yourself, people also start to believe in you
 Date : 04-Apr-18
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


llu dp[25][25][2][2][2] ;
string s1,s2;

int abc(int f, char  a, char b ){
    if(a==b)
        return f;

    if(a>b)
        return 0;
    return 1;
}

string ToString(llu num){
    string s;
    while(num>0){
        s.pb(num%10+'0');
        num/=10;
    }


    while(sz(s)<23)
        s.pb('0');

    reverse(all(s) );

    return s;
}


int pos;


llu re(int l,int r ,int f1,int f4,int z){
  //  debug(l,r,f1,f4,z)
    if(l==sz(s1) ){ 
        if(z) return 0;
        if(r>=pos) return 1;
        return 1-f4;
    }
    
    llu &res = dp[l][r][f1][f4][z] ;
    
    if(res!=-1) return res;
    
    res = 0;
     

    int L = z,R=9;

    if(z){  
        int i = 0;        
        res += re(l+1,r,max(f1, int( s1[l]> i +'0' ) ) , f4,z  );                
    }


    if(!f1)
        R = min(R,s1[l]-'0' ); 
     
    for(int i=L;i<=R;i++) 
        res += re(l+1,r-1,max(f1, int( s1[l]> i +'0' ) ) , abc(f4,  s2[r],  i +'0' ),0  );        
    
    return res;
}

llu solve(llu a,llu b){
    s2 = ToString(b);
    s1 = ToString(a);
    reset(dp,-1); 
    pos = sz(s2);
    for(int i=0;i<sz(s2);i++)
        if(s2[i]!='0'){
            pos = i;
            break;
        }
   // what_is(re(0,sz(s1)-1 ,0 ,0,1))
    return  re(0,sz(s1)-1 ,0 ,0,1);    
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
    llu a,b;

    while(t--){
        in(a),in(b);

        llu res = 0;
 
        res+=solve(b,b);   
        res-=solve(a-1,b);
        res-=solve(b,a-1);
        res+=solve(a-1,a-1);
  
        
        pf("Case %d: %llu\n",tcase++,res);
    }


    return 0;
}

