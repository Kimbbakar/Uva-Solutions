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

int tree[4*10003];
int u,v,s;

void update(int node,int l,int r){

    if(r<v or v<l) return ;

    if(v<=l and r<=v){
        tree[node]+=s;
        return;
    }

    int mid = (l+r)>>1;
    int left = node<<1;
    int right = left |1;

    update(left,l,mid);
    update(right,mid+1,r);

    tree[node] = tree[left] + tree[right];
}

void query(int node,int l,int r){

    if(tree[node]==0 or l>v ) return;
     if(l==r){
        s = max(l,s);
        return ;
    }

    int mid = (l+r)>>1;
    int left = node<<1;
    int right = left |1;
    if(tree[right] and  mid+1<=v  )
        query(right,mid+1,r);
    if(tree[left] and s==-1)
        query(left,l,mid );
}


vector<int>lst[100004];
int n;

int solve(){

    int c = 0;
    reset(tree,0);

    for(int i=1;i<=10000;i++ ){
        if(sz(lst[i])==0 ) continue;

        sort(all(lst[i] ) );



        for(auto j:lst[i] ){
            s = -1;
            v = j-1;

            query(1,1,10000);
              //  debug(i,s,j)

            if(s>-1){
                v = s;
                s = -1;
                update(1,1,10000);

            }
            else c++;
        }

        for(auto j:lst[i] ){
            v = j;
            s = 1;
            update(1,1,10000);
        }

    }


//    for(int i=0;i<sz(lis);i++)
//        cout<<lis[i]<<" ";
//    cout<<endl;

    return c;

}


int main()
{
//     std::ios_base::sync_with_stdio(false);

    #ifdef kimbbakar
        freopen ( "in.txt", "r", stdin );
//        freopen ( "out.txt", "w", stdout );
    #endif

    int t,tcase=1;
    int a,b;

    in(t);


    while(t--){
        in(n);

        for(int i=0;i<=10000;i++)
            lst[i].clear();

        for(int i=0;i<n;i++){
            in(a),in(b);

            lst[a].pb(b);
        }

        pf("%d\n",solve() );
    }

    return 0;
}


