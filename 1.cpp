#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const ll MOD = 10000;

void solve()
{
    ll n,k;
    cin>>n>>k;

    vector<vector<ll>> dp(n+1,vector<ll>(k+1,0));

    for(int i = 1;i<=n;i++){
        dp[i][0] = 1;
        for(int j = 1;j<=k;j++){
            if(i > 1){
                for (int m = 0; m <= i - 1; m++)
                {
                    if (j - m >= 0)
                    {                                                   
                        dp[i][j] = (dp[i][j] + dp[i - 1][j - m]) % MOD;
                    }
                }
            }
        }
    }

    cout<<dp[n][k]<<endl;

}

int main()
{
    int t = 1;
    // cin >> t;
    while (t--)
        solve();
}