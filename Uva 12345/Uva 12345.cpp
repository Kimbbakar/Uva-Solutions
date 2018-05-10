#include <bits/stdc++.h>

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


class ABC{
public:
    int l,r,tm,  id;

    ABC(int id, int l,int r,int tm){
        this ->id =id;
        this ->l =l;
        this ->r =r;
        this ->tm =tm;
    }
};

int N,Q,B;
int mark[1000005];
int kp[100005];
map<int,int>compress; 
pair<int,int> update[100004];
vector<ABC>query;
int res[100005];

bool cmp(ABC a,ABC b ){
    if(a.l/B !=b.l/B )
        return (a.l/B < b.l/B);

    if(a.r/B !=b.r/B )
        return (a.r/B < b.r/B);

    return a.tm<b.tm;
}

bool cmp2(ABC a,ABC b ){
    return a.id<b.id;
}

void up(int p,int l,int r, int &cnt){
 
    if(l<=update[p].F and update[p].F<=r){
     
        mark[kp[update[p].F]]--;
         
        if(!mark[kp[update[p].F]] )              
            cnt--;
        
        if(!mark[update[p].S])
            cnt++;
        mark[update[p].S]++;
    }

    swap(kp[update[p].F],update[p].S ); 
}

int main()
{
//     std::ios_base::sync_with_stdio(false);

    #ifdef kimbbakar
        freopen ( "E:/Code/in.txt", "r", stdin );
//        freopen ( "E:/Code/out.txt", "w", stdout );
    #endif

    int id = 1,var;

    in(N),in(Q);;

    for(int i=1;i<=N;i++){
        in(kp[i]); 
    }

    
    int l,r;
    char ch;

    for(int i=1,j=0;i<=Q;i++){
        scanf("%c %d %d\n",&ch,&l,&r);
         
        if(ch=='Q') {
            l++;
            query.pb({i,l,r,j});                         
        }

        
        else{
            j++; 
            l++;
            update[j] = {l,r};
        } 
    }

    B = 500;
    sort(all(query),cmp );

    int cnt = 0;
    int f =0;
    l = r = 0;
    for(auto i:query){

        while(f<i.tm) 
            up(++f,l,r,cnt);

        while(f>i.tm) 
            up(f--,l,r,cnt);
    

        while(l<i.l){
            mark[kp[l] ]--;  

            if(!mark[kp[l] ])
                cnt--;
            l++;
        } 

        while(i.l<l){
            l--;

            if(!mark[kp[l] ])
                cnt++;
            mark[kp[l] ]++;
        }  

        while(r<i.r){
            r++;

            if(!mark[kp[r] ])
                cnt++;

            mark[kp[r] ]++; 

        }

        while(i.r<r){
            mark[kp[r] ]--;

            if(!mark[kp[r] ])
                cnt--;
            r--;
        }

        res[i.id] = cnt;

    }


    sort(all(query),cmp2 );

    for(auto i: query)
        pf("%d\n",res[i.id] );

    return 0;
}



