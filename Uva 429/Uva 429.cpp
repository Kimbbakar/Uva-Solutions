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

map<string,int>maps;
int floyed[202][202];
int mark;

void clear(){

    maps.clear();
    mark=1;

    for(int i=1;i<=200;i++)
        for(int j=1;j<=200;j++){
            if(i==j)
                floyed[i][j]=0;
            else
                floyed[i][j]=12345678;
        }

}

void pre_cal(){
    for(int k=1;k<mark;k++){
        for(int i=1;i<mark;i++){
            for(int j=1;j<mark;j++)
                floyed[i][j]=min(floyed[i][j],floyed[i][k]+floyed[k][j]);
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

    in(t);
    string s; 
    while(t--){
        clear();

        while(cin>>s && s!="*"){
            if(!maps.count(s))
                maps[s]=mark++;
            
            int a=maps[s];
            
            for(int i=0;i<sz(s);i++){
                string tmp=s;

                for(char j='a';j<='z';j++){
                    if(s[i]==j)
                        continue;

                    tmp[i]=j;  

                    if(maps.count(tmp)){
                        int b= maps[tmp];
                        
                        floyed[a][b]=1;
                        floyed[b][a]=1;
                    }
                }
            }
        }
        pre_cal();

        cin.ignore(); 

        while(getline(cin,s) && s!=""){

            string a=s.substr(0,s.find(" "));
            string b=s.substr(s.find(" ")+1);
            
            cout<<a<<" "<<b<<" "<<floyed[maps[a]][maps[b]]<<"\n";
        }
  
        if(t)
            pf("\n") ; 

    }

    return 0;
}