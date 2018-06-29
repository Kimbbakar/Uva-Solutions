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

string res[10];
string s[10];
string a,b;
int posA,posB;
ll wA,wB;
string tmp =   "" ;


ll getval(char x){

    ll v = 0;
    while(x){

        if(x%2==0)
            v+=250;
        else v+=500;

        x/=2;
    }

    return v;

}

void store(){

    posA = posA = 0;
    a.clear();
    b.clear();
    wA = wB = 0;

    for(int i=0;i<7;i++){
        for(int j=0;j<8;j++){
            if(isalpha(s[i][j] )){
                wA+=getval(s[i][j]) ;
                posA = i;
                a.pb(s[i][j] );
            }
        }
    }


    for(int i=0;i<7;i++){
        for(int j=10;j<=17;j++){
            if(isalpha(s[i][j] )){
                wB+=getval(s[i][j]) ;
                posB = i;
                b.pb(s[i][j] );
            }
        }
    }

    while(sz(a)<6)
        a.pb('.');

    while(sz(b)<6)
        b.pb('.');

}

void placetoleft(){


    res[0] = "........||.../"+ tmp+  "...";

    res[1] = "........||../.."+ tmp+  "..";
    res[2] = ".../"+ tmp+  "...||./...."+ tmp+  ".";
    res[3] = "../.."+ tmp+  "..||/......"+ tmp+  "";
    res[4] = "./...."+ tmp+  ".||"+ tmp+  "______/";
    res[5] = "/......"+ tmp+  "||........";
    res[6] = ""+ tmp+  "______/||........";
    res[7] = "------------------";


    res[3] = "../.."+ tmp+  "..||/" + b   + tmp ;
    res[5] = "/" + a + ""+ tmp+  "||........";



}

void placetoequel(){
    res[0] = "........||........";
    res[1] = ".../"+ tmp+  "...||.../"+ tmp+  "...";
    res[2] = "../.."+ tmp+  "..||../.."+ tmp+  "..";
    res[3] = "./...."+ tmp+  ".||./...."+ tmp+  ".";
    res[4] = "/......"+ tmp+  "||/......"+ tmp+  "";
    res[5] = ""+ tmp+  "______/||"+ tmp+  "______/";
    res[6] = "........||........";

    res[4] = "/" + a + ""+ tmp+  "||/"+ b + ""+ tmp+  "";

}


void placetoright(){
    res[0] = ".../"+ tmp+  "...||........";
    res[1] = "../.."+ tmp+  "..||........";
    res[2] = "./...."+ tmp+  ".||.../"+ tmp+  "...";
    res[3] = "/......"+ tmp+  "||../.."+ tmp+  "..";
    res[4] = ""+ tmp+  "______/||./...."+ tmp+  ".";
    res[5] = "........||/......"+ tmp+  "";
    res[6] = "........||"+ tmp+  "______/";

    res[3] = "/" + a + ""+ tmp+  "||../.."+ tmp+  "..";
    res[5] = "........||/" + b + ""+ tmp+  "";

}

bool checkTheGrid(){
    for(int i=0;i<7;i++)
        if(s[i]!=res[i])
        return false;
    return true;
}



int main()
{
//     std::ios_base::sync_with_stdio(false);

    #ifdef kimbbakar
        freopen ( "in.txt", "r", stdin );
   //     freopen ( "out.txt", "w", stdout );
    #endif


    tmp.pb(92);

    int t,tcase=1;


    in(t);


    while(t--){
        for(int i=0;i<8;i++)
            cin>>s[i];

        store();


      //  debug(wA,wB,posA,posB,a,b);

        pf("Case %d:\n",tcase++);
 
        if(wA==wB)
            placetoequel();
        else if(wA<wB)
            placetoright();
        else placetoleft();

        if(checkTheGrid())
            pf("The figure is correct.\n");
        else{

            if(wA==wB)
                placetoequel();
            else if(wA>wB)
                placetoleft();
            else placetoright();
         for(int i=0;i<7;i++)
            cout<<res[i]<<endl;

        }


    }




    return 0;
}


