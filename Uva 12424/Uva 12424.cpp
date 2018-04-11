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

int kp[100005];
int table[100005][20];
int child[100005];
int dep[100005];
int PosId[100005];
int IdPos[100005];
vector<int>lst[100004];
int u,v,s,n,m,id;

void dfs(int node,int heigh,int par){
    
    child[node] = 0;
    PosId [node] = id++; 
    dep[PosId [node]] = heigh;
    table[PosId [node]][0] = (par==-1?-1: PosId[par]);
  

    for(auto i: lst[node] ){
        if(i==par) continue; 
        dfs(i,heigh+1,node);
        child[node]+=1+child[i];
    }                        
}

class SegmentTree{
public:
    int tree[4*100003]; 
    int color;

    SegmentTree(){ 
    }

    SegmentTree(int color){
        this->color = color;
    }

    void clear(int col){
        reset(tree,0);
        color = col ;
    }

    void update(int node,int l,int r){
        if(v<l or r<u) return;
 //debug("->>> ",color,l,r,tree[node],s)
        if(u<=l and r<=v){
            tree[node] += s;
            return;
        }

        int mid = (l+r)>>1;
        int left = node<<1;
        int right = left |1;

        if(tree[node]){

            tree[left] += tree[node];
            tree[right] += tree[node];

            tree[node] = 0;
        }

        update(left,l,mid);
        update(right,mid+1,r);
 
    }

    void query(int node,int l,int r){  
        if(v<l or r<u) return;

        if(u<=l and r<=v){ //debug("->>> ",l,r,tree[node])
            s+=tree[node];
            return;
        }

        int mid = (l+r)>>1;
        int left = node<<1;
        int right = left |1;

        if(tree[node]){

            tree[left] += tree[node];
            tree[right] += tree[node];

            tree[node] = 0;
        }

        query(left,l,mid);
        query(right,mid+1,r); 
    }
};


 
void build()
{
    for(int i=1;i<=log2(n);i++)
    {
        for(int j=1;j<=n;j++)
        {
            if(table[j][i-1]!=-1 )
            {
               table[j][i]=table[table[j][i-1] ][i-1];
            }
        }
    }
}

int qu(int a,int b)
{
    if(dep[a]<dep[b] )
        swap(a,b); 
    int lg;
    for(lg = 1; (1 << lg) <= dep[a]; lg++); lg--;
    for(int i=lg;i>=0;i--)
    {
        if(dep[a]-(1<<i)>=dep[b])
        {
            a=table[a][i];
        }
    }
    if(a==b) return a;

    int k;

    for(int i=lg;i>=0;i--)
    {
        if(table[a][i]!=-1 && table[a][i]!=table[b] [i] )
        {
            a=table[a][i];
            b=table[b][i];
        }
    }

    

    return table[a][0] ;
}

SegmentTree tree[11];


int main()
{
//     std::ios_base::sync_with_stdio(false);

    #ifdef kimbbakar
        freopen ( "E:/Code/in.txt", "r", stdin );
        freopen ( "E:/Code/out.txt", "w", stdout );
    #endif

    int t,tcase=1;
    lst[0].pb(1);

    in(t);

    while(t--){
        in(n),in(m);
        

        for(int i=1;i<=n;i++){
            lst[i].clear();
            in(kp[i]) ; 
        }

        reset(table,-1);

        for(int i=1;i<n;i++){
            in(u),in(v);
            lst[u].pb(v);
            lst[v].pb(u);  
        }



        id = 0;
        dfs(0,1, -1);
        build();  

        for(int i=1;i<=10;i++) 
            tree[i].clear(i);  

        
        for(int i=1;i<=n;i++){
           // debug(i,PosId[i],child[i] )
            u = PosId[i];
            v = u+child[i] ;
            s = 1;
            tree[kp[i] ].update(1,1,n);
        }

        int a,b,c;
 
        while(m--){
            in(a);
            if(a==0){
               in(b),in(c);

                u = PosId[b];
                v = u+child[b] ;
                s = -1;
                tree[kp[b] ].update(1,1,n);

                kp[b] = c;

                u = PosId[b];
                v = u+child[b] ;
                s = 1;//debug(u,v,kp[b]) what_is(c)
                tree[kp[b] ].update(1,1,n);
            }
            else{
                int res = 0;
                in(b),in(c);
                int par = qu(PosId[b],PosId[c] ); //debug("** ",par,b,c)
               
                for(int i=1;i<=10;i++) {
                    s= 0;

                    u=v=PosId[b];
                    tree[i].query(1,1,n);

                    u=v=PosId[c];
                    tree[i].query(1,1,n);

                    s = -s;  
 
                    u=v=par;
                    tree[i].query(1,1,n);
 
                    u=v=table[par][0] ;
                    tree[i].query(1,1,n); //what_is(s)

                    res = max(res,-s); 
                }

                pf("%d\n",res);


            } 
        } 

    }

    return 0;
}



