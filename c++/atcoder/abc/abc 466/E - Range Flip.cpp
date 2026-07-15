#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define endl '\n'

const ll N = 1e9;
const ll MOD = 676767677;
const ll INF = 1e18;


void solve()
{
    ll n,k;
    cin>>n>>k;
    vector<ll> diff(n+1,0);
    ll sum = 0;
    for(int i = 1;i<=n;i++){
        ll a,b;
        cin>>a>>b;
        sum+=a;
        diff[i] = b-a;
    }

    vector<vector<ll>> dp(k+1,vector<ll>(2,-INF));
    dp[0][0] = 0;

    for(int i = 1;i<=n;i++){
        vector<vector<ll>> nexdp(k+1,vector<ll>(2,-INF));
        for(int j = 0;j<=k;j++){
            if(j == 0){
                nexdp[j][0] = 0;
            }else{
                nexdp[j][0] = max(dp[j][1],dp[j][0]);

                nexdp[j][1] = max(dp[j][1],max(dp[j-1][0],dp[j-1][1])) + diff[i];
            }
        }
        dp = nexdp;
    }

    ll ma = 0;
    for(auto v : dp){
        ma = max({ma,v[0],v[1]});
    }

    cout<<sum + ma<<endl;
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