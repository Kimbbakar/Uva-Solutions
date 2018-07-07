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

struct rec{
    int idx;
    double x1,y1;
    double x2,y2;
};

struct cir{
    int idx;
    double x,y;
    double r;
};

struct tri{
    int idx;
    pair<double,double> p[3] ;

};


bool dis(cir z,pair<double,double>p ){
    return greaterThan(sqr(z.r),sqr(p.F-z.x) + sqr(p.S-z.y)   );
}

bool inside(rec z,pair<double,double>p ){
    return ( (z.x1<p.F and p.F<z.x2 ) and (z.y1<p.S and p.S<z.y2 ) );
}

double triarea(pair<double,double>a,pair<double,double>b,pair<double,double>c  ){
    vector<pair<double,double> > p;
    p.pb(a);
    p.pb(b);
    p.pb(c);

    double res = 0 ;

    for(int i=0;i<3;i++)
        res+=(p[i].F*p[(i+1)%3 ].S );
    for(int i=0;i<3;i++)
        res-=(p[i].S*p[(i+1)%3 ].F );

    return abs(res)*.5;
}


int main()
{
//     std::ios_base::sync_with_stdio(false);

    #ifdef kimbbakar
        freopen ( "in.txt", "r", stdin );
//        freopen ( "out.txt", "w", stdout );
    #endif

    char ch;

    vector<cir>circle;
    vector<rec>rect;
    vector<tri>triangle;
    int idx = 1;


    while(cin>>ch){
        if(ch=='*') break;

        if(ch=='t'){
            tri nw = tri();
            nw.idx=idx++;

            for(int i=0;i<3;i++)
                scanf("%lf %lf",&nw.p[i].F,&nw.p[i].S);
            triangle.pb(nw);
        }

        else if(ch=='r'){
            rec nw = rec();

            nw.idx=idx++;

            scanf("%lf %lf %lf %lf",&nw.x1,&nw.y1,&nw.x2,&nw.y2);

            if(nw.x1>nw.x2)
                swap(nw.x1,nw.x2);

            if(nw.y1>nw.y2)
                swap(nw.y1,nw.y2);

            rect.pb(nw);
        }

        else{
            cir nw = cir();

            nw.idx=idx++;

            scanf("%lf %lf %lf",&nw.x,&nw.y,&nw.r);

            circle .pb(nw);
        }

    }

    double x,y;

    idx =1;

    while(scanf("%lf %lf",&x,&y)==2){

        if(x==9999.9 and  y==9999.9) break;

        vector<int>res;

        for(auto i:rect)
            if( inside(i,mp(x,y) ) )
                res.pb(i.idx);

        for(auto i:circle)
            if( dis(i,mp(x,y) ) )
                res.pb(i.idx);

        for(auto i:triangle){
            double area1 = triarea({x,y},i.p[0],i.p[1]  );
            double area2 = triarea({x,y},i.p[1],i.p[2]  );
            double area3 = triarea({x,y},i.p[2],i.p[0]  );
            double area4 = triarea( i.p[0],i.p[1],i.p[2] );

 
            if( area1>0 and area2>0 and area3>0 and equalTo( area4,area1+area2+area3 ) )
                res.pb(i.idx);


        }
        sort(all(res) );

        if(sz(res)==0)
            pf("Point %d is not contained in any figure\n",idx);
        else{
            for(auto i:res)
                pf("Point %d is contained in figure %d\n",idx,i);
        }

        idx++;
    }

    return 0;
}



