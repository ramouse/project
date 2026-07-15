#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define endl '\n'

const ll INF = 1e18;
const ll MAXN = 1e6+5;
const ll MOD = 1e9+7;

void solve()
{   
    ll n,d;
    cin>>n>>d;

    ll ans = 1;
    if(d == 1){
        for(int i = 1;i<=2*n;i++){
            ans = ans*2%MOD;
        }
        cout<<ans<<endl;
        return;
    }

    vector<ll> dp(n+1,0);
    dp[0] = 1;
    for(int i = 1;i<=n;i++){
        dp[i] = (dp[i-1] + dp[max(i-d,0LL)] + dp[max(i-d+1,0LL)]) % MOD;
    }
    
    cout<<dp[n]<<endl;

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