#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define endl '\n'

const ll INF = 1e18;
const ll MAXN = 2e5 * 32;
const ll MOD = 1e9+7;

void solve()
{       
    ll n;
    cin>>n;
    vector<ll> a(n+1,0),b(n+1,0);
    for(int i = 1;i<=n;i++){
        cin>>a[i];
    }
    for(int i = 1;i<=n;i++){
        cin>>b[i];
    }

    vector<vector<ll>> dp(n+1,vector<ll>(3,0));//0-拿不 1-拿影 2-不拿
    dp[0][0] = 0;
    dp[0][1] = 0;
    dp[0][2] = 0;

    for(int i = 1;i<=n;i++){
        ll cur = a[i];
        ll tot = b[i];
        
        if(tot == 1){
            dp[i][0] = max({dp[i-1][1],dp[i-1][2],dp[i-1][1]});
            dp[i][1] = max(dp[i-1][0],dp[i-1][2]) + cur;
            dp[i][2] = max({dp[i-1][0],dp[i-1][1],dp[i-1][2]});
        }else if(tot & 1){
            ll o = tot/2;
            ll t = tot - o;
            dp[i][0] = max({dp[i-1][0],dp[i-1][2],dp[i-1][1]}) + o * cur;
            dp[i][1] = max(dp[i-1][0],dp[i-1][2]) + t * cur;
            dp[i][2] = max({dp[i-1][0],dp[i-1][1],dp[i-1][2]});
        }else{
            ll o = tot/2;
            dp[i][0] = max({dp[i-1][0] + o * cur,dp[i-1][1] + (o - 1) * cur,dp[i-1][2] + o * cur});
            dp[i][1] = max({dp[i-1][0],dp[i-1][2],dp[i-1][1]}) + o * cur;
            dp[i][2] = max({dp[i-1][0],dp[i-1][1],dp[i-1][2]});
        }

    }   

    ll ans = max({dp[n][0],dp[n][1],dp[n][2]});
    cout<<ans<<endl;
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