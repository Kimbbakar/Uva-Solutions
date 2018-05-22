

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

#define MAX 500005

class PersistentSegTree{
public:
    int left,right;
    int v;

    void clr(){
        left = right = 0;
        v = -1;
    }
};

PersistentSegTree tree[4*MAX];
int start;
ll u,v;
int s,id;

//  [l,r] = range cover by tree
//  [u,v] = range you are looking for  

void update(int &node,ll l,ll r){

    if(v<l or r<u) return;

    if(!node)
        node = ++id;

    if(l==r){
    //    what_is(l) what_is(s)
        tree[node].v = s;
        return;
    }

    ll mid  = (l+r)>>1; 

    update(tree[node].left ,l,mid);
    update(tree[node].right,mid+1,r);

    tree[node].v = max( tree[tree[node].left].v,tree[tree[node].right].v );
}


void qu(int node,ll l,ll r){

    if(v<l or r<u  or !node ) return;

    if(u<=l and r<=v){
        s= max(tree[node].v,s);
        return;
    }

    ll mid  = (l+r)>>1; 

    qu(tree[node].left ,l,mid);
    qu(tree[node].right,mid+1,r);
}

void clearTree(){
    for(int i=0;i<=id;i++)
        tree[i].clr();
    id = 0;
}
ll sum,d;
int n;
ll Limit = 500000LL*1e9 ;

int main()
{
//     std::ios_base::sync_with_stdio(false);

    #ifdef kimbbakar
        freopen ( "E:/Code/in.txt", "r", stdin );
     //   freopen ( "E:/Code/out.txt", "w", stdout );
    #endif
 
    int t,tcase=1;

    for(int i=0;i<4*MAX;i++)
        tree[i].clr();

 
    in(t); 

    while(t--){
        in(n),in(d);

 

        clearTree();

        start = id = 0;
        u=v=0;
        s = 0;
        update(start,-Limit,Limit);

        sum = 0;
        int res = -1;  
        for(int i=1;i<=n;i++){
            in(v);
            sum+=v;

            s = -1;
            u = -Limit;
            v = sum-d; 
            qu(start,-Limit,Limit);
           // debug(i,sum,v,s)
            if(s!=-1){
                if(res==-1) res = i-s;
                else res = min(res,i-s );                
            }


            u=v=sum;
            s = i;
            update(start,-Limit,Limit);

        }
        pf("%d\n",res);
    }


    return 0;
}



