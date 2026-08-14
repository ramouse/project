#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define endl '\n'
#define pll pair<ll, ll>
#define T tuple<ll, ll, ll>
#define all1(x) x.begin() + 1, x.end()
#define all0(x) x.begin(), x.end()
#define pb(x) push_back(x)
#define fir first
#define sec second

const ll MOD = 998244353;
const ll INF = 1e18;

void solve()
{
    ll n,m;
    cin>>n>>m;
    vector<ll> a(m+1,0);
    vector<bool> vis(2*n+1,0);
    set<ll> se;
    bool ok = false;
    for(int i = 1;i<=m;i++){
        ll x;
        cin>>x;
        if(x <= 2*n){
            vis[x] = 1;
        }else{
            ok = true;
        }
    }
    if(ok){
        cout<<0<<endl;
        return;
    }
    ll cnt = 0;
    vector<vector<ll>> dp(2*n+2,vector<ll>(2*n+1,0));
    dp[0][0] = 1;

    for(int i = 1;i<=2*n;i++){
        for(int j = 0;j<=n;j++){
            if (vis[i])
            {
                if(j > 0) dp[i][j] = dp[i-1][j-1];
            }else{
                if(j > 0) dp[i][j] = (dp[i-1][j-1] + dp[i][j]) % MOD;
                if(j + 1 <= n) dp[i][j] = (dp[i-1][j+1] + dp[i][j]) % MOD;
            }
        }
        
    }

    ll ans = 0;

    
    cout<<dp[2*n][0]<<endl;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t = 1;
    cin >> t;
    while (t--)
        solve();
}