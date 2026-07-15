#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define endl '\n'

int main(){
    ll n;
    cin>>n;
    vector<vector<ll>> pre(n+1,vector<ll>(n+1,0));
    for(int i = 1;i<=n;i++){
        string s;
        cin>>s;
        for(int j = 1;j<=n;j++){
            pre[i][j] = pre[i][j-1] + (s[j-1] == '.');
        }
    }


    vector<vector<ll>> d(n + 1, vector<ll>(n + 1, 0));
    for(int i = 1;i<=n;i++){
        for(int j = 0;j<=n;j++){
            d[i][j] = (j - pre[i][j]) + (pre[i][n] - pre[i][j]);
        }
    }

    vector<vector<ll>> dp(n+1,vector<ll>(n+1,1e9));
    vector<vector<ll>> p(n + 1, vector<ll>(n + 2, 1e9));
    

    // for(int i = 1;i<=n;i++){
    //     for(int j = n;j>=0;j--){
    //         p[i-1][j] = min(p[i-1][j+1],dp[i-1][j]);
    //     }
    // }
    for (int j = 0; j <= n; j++)
    {
        dp[0][j] = 0;
    }
    for(int i = 1;i<=n;i++){
        for (int j = n; j >= 0; j--)
        {
            p[i-1][j] = min(p[i-1][j+1],dp[i-1][j]);
        }
        for(int j = 0;j<=n;j++){
            dp[i][j] = d[i][j] + p[i-1][j];
        }
    }
    ll ans = 1e18;
    for(int i = 1;i<=n;i++) ans = min(ans,dp[n][i]);
    cout<<ans;
    return 0;
}