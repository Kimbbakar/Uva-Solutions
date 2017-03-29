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

int floyed[302][302];
vector<int >path[302][302];
int mark[301],id;
int n;

void clear(){
    reset(mark,0);
    id=1;

    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++){
            path[i][j].clear();

            if(i==j)
                floyed[i][j]=0;                   
            else
                floyed[i][j]=12345678;
        }
}

void pre_cal(){
    for(int k=1;k<=n;k++){
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                if(floyed[i][j]>floyed[i][k] + floyed[k][j] ){
                    floyed[i][j]=floyed[i][k] + floyed[k][j];
                    path[i][j]=path[i][k];

                    for(int l=0;l<sz(path[k][j]);l++)
                        path[i][j].pb(path[k][j][l]);
                }
            }
        }
    }
}

int main()
{
//     std::ios_base::sync_with_stdio(false);

    #ifdef kimbbakar
        freopen ( "in.txt", "r", stdin );
//        freopen ( "out.txt", "w", stdout );
    #endif

    int t,tcase=1;
 

    while(scanf("%d",&n)==1){ 
        clear();
        pf("-----\n");
        int a,b; 

        for(int x=0;x<n;x++){
             
            a=0;
            string s; 
            cin>>s; 
            int y=0;
            
            while(s[y]!='-'){
                a=a*10+s[y++]-'0';
            }
            
            y++;

            if(!mark[a])
                mark[a]=id++;

            b=0; 

            for(;y<sz(s);y++){
                char i = s[y];
                if(i==','){
                    if(!mark[b])
                        mark[b]=id++;  

                         
                    floyed[mark[a]][mark[b]]=1;
                    path[mark[a]][mark[b]].pb(b);
 

                    b=0;
                }
                else
                    b = b*10 + (i -'0');
            }

            if(b){
                if(!mark[b]) 
                    mark[b]=id++;  


                floyed[mark[a]][mark[b]]=1;
                path[mark[a]][mark[b]].pb(b);
        
            }
        }

        int q;
        in(q); 

        pre_cal();  

        while(q--){
            in(a),in(b);
       
            if(!mark[a])
                mark[a]=id++;

            if(!mark[b])
                mark[b]=id++;

            if(floyed[mark[a] ][mark[b] ]==12345678){
                pf("connection impossible\n");
                continue;
            }

           // pf("%d\n",floyed[mark[a] ][mark[b] ] );
            pf("%d",a);
            for(int i=0;i<sz(path[mark[a] ][mark[b] ]);i++){
                pf(" %d",path[mark[a] ][mark[b] ][i] );
            }  
            pf("\n");
        }



    }


    return 0;
}