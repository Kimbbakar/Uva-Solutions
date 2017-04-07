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
vector<char>grp[104];
int mark[104][104];
int mx[104]; 
int n,m,id;
string s;

void clear(){
    id=1;
    reset(mark,0);
    reset(mx,0);

    for(int i=0;i<104;i++)
        grp[i].clear();
    n = 0;
}

int x[]={0,1,-1,0,1,-1,1,-1};
int y[]={1,0,0,-1,1,-1,-1,1};

void dfs(){

    m = sz(grp[0]);
  
    for(int i=0;i<n;i++){  
        for(int j=0;j<m;j++){
             
            if(mark[i][j] ) continue;
           // pf("** %d %d\n",i,j);
            mark[i][j] = id;
            mx[j]=max(mx[j],id);

            queue<pair<int,int> > q;
            q.push(mp(i,j));

            while(!q.empty()){
                pair<int,int>nw = q.front();
                q.pop();
               // printf("%d %d\n",nw.F,nw.S );
                 
                for(int k=0;k<8;k++){
                    pair<int,int>tmp=mp(x[k]+nw.F,y[k]+nw.S);
                        
                    if(tmp.F<0 || tmp.S<0 || tmp.F>=n || tmp.S>=m) continue;
                    //pf("%d %d,(%d,%d) %c\n",tmp.F,tmp.S,nw.F,nw.S,grp[tmp.F][tmp.S]);

                    if(mark[tmp.F][tmp.S] || grp[i][j]!=grp[tmp.F][tmp.S])
                        continue;
                    

                    mark[tmp.F][tmp.S] = id;
                    mx[tmp.S]=max(mx[tmp.S],id);
                    q.push(tmp);
                } 
            }

            id++;            
        }  
    }  
}

void space(){
    for(int i=0;i<m;i++){
        int xx =0 ;

        while(mx[i]/10 ){
            mx[i]/=10;
            xx++;
        }
        mx[i] = xx;
    }    
}

void print(){
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(j)
                pf(" ");

            int tmp = mark[i][j];

            int xx = 0 ;

            while(tmp/10>0){
                tmp/=10;
                xx++;
            }

            for(int k=0;k<mx[j]-xx;k++)
                pf(" ");
            

            pf("%d",mark[i][j]);
        }
        pf("\n");
    }    
}


int main()
{
//     std::ios_base::sync_with_stdio(false);

    #ifdef kimbbakar
        freopen ( "in.txt", "r", stdin );
        freopen ( "out.txt", "w", stdout );
    #endif
    clear();
    char dd = '%';

    while(getline(cin,s)){
        if(s[0] ==dd){
            dfs();
            space();
            print();
            clear();
            pf("%c\n",dd);
        }
        else{
            stringstream ss(s);
            char ch;

            while(ss>>ch){ 
                grp[n].pb(ch);
            }
            n++;
        }

    } 
    dfs(); 
    space();
    print();
    pf("%c\n",dd);

    return 0;
}