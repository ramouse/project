#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define endl '\n'

const ll N = 1e9;
const ll MOD = 676767677;
const ll INF = 1e18;


void solve()
{
    ll n,m;
    cin>>n>>m;
    vector<ll> a(n+1,0),b(n,0);
    for(int i = 1;i<=n;i++) cin>>a[i];
    for(int i = 1;i<n;i++){
        cin>>b[i];
    }

    ll ans = 0;
    ll last = -1;
    // if(a[1] + a[2] == 1) last = 1;
    // else last = 2;
    // if(last == 1){
    //     if(b[1] == 0){
    //         ans++;
    //         last = 2;
    //     }
    // }else{
    //     if(b[1] == 1){
    //         ans++;
    //         last = 1;
    //     }
    // }

    vector<vector<ll>> dp(n+1,vector<ll>(2,INF));

    dp[0][0] = 0,dp[0][1] = 1;

    for(int i = 1;i<n;i++){
        if(b[i] == 0){
            if(a[i] == 0){
                if(a[i+1] == 0)
                {//000
                    dp[i][0] = dp[i-1][0];
                    dp[i][1] = dp[i-1][1] + 1;
                }else{
                    //001
                    dp[i][0] = dp[i-1][1];
                    dp[i][1] = dp[i-1][0] + 1;
                }
            }else{
                if(a[i+1] == 0){
                    //010
                    dp[i][0] = dp[i-1][1];
                    dp[i][1] = dp[i-1][0] + 1;
                }else{
                    //011
                    dp[i][0] = dp[i-1][0];
                    dp[i][1] = dp[i-1][1] + 1;
                }
            }
        }else{
            if(a[i] == 0){
                if(a[i + 1] == 0){
                    //100
                    dp[i][0] = dp[i-1][1];
                    dp[i][1] = dp[i-1][0] + 1;
                }else{
                    //101
                    dp[i][0] = dp[i-1][0];
                    dp[i][1] = dp[i-1][1] + 1;
                }
            }else{
                if(a[i + 1] == 0){
                    //110
                    dp[i][0] = dp[i-1][0];
                    dp[i][1] = dp[i-1][1] + 1;
                }else{
                    //111
                    dp[i][0] = dp[i-1][1];
                    dp[i][1] = dp[i-1][0] + 1;
                }
            }
        }
    }

    cout<<min(dp[n-1][0],dp[n-1][1])<<endl;
    
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t = 1;
    // cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}