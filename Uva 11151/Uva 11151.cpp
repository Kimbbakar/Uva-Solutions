#include <bits/stdc++.h>

using namespace std;

string s;

int dp[1005][1005];

int call(int a, int b){
    if (a==b)
        return 1;
    if (a>b)
        return 0;

    if (dp[a][b]!=-1)
        return dp[a][b];

    int ret1,ret2,ret3;

    ret1=call(a+1,b);
    ret2=call(a,b-1);

    dp[a][b]=max(ret1,ret2);

    if (s[a]==s[b] /*&& isalpha(s[a])*/)
    dp[a][b]=max(dp[a][b],2+call(a+1,b-1));

    return dp[a][b];


}

int main(){
    int t;
    scanf("%d",&t);

    cin.ignore();

    for(int tc=0;tc<t;tc++){
        getline(cin,s);

        /*
        for(int i=0;i<s.length();i++){
            s[i]=tolower(s[i]);
        }*/


        memset(dp,-1,sizeof(dp));
        cout<<max(0,call(0,s.length()-1))<<endl;

    }

}