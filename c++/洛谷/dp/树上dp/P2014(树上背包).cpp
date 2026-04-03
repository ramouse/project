#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define endl '\n'

const ll MOD = 998244353;

void solve()
{
    ll n, m;
    cin >> n >> m;
    vector<vector<ll>> adj(n + 1);
    vector<ll> a(n + 1, 0);
    vector<ll> vec;
    for (int i = 1; i <= n; i++)
    {
        ll k, s;
        cin >> k >> s;
        adj[i].push_back(k);
        adj[k].push_back(i);
        a[i] = s;
    }

    vector<vector<ll>> dp(n + 1, vector<ll>(m + 2, 0));
    auto dfs = [&](auto &&self, ll u, ll fa, ll tot) -> void
    {
        dp[u][1] = a[u];
        for (auto v : adj[u])
        {
            if (v != fa)
            {

                self(self, v, u, tot - 1);
                for (int j = m+1; j >= 0; j--)
                {
                    for (int k = 0; k < j; k++)
                    {
                        dp[u][j] = max(dp[u][j], dp[u][j - k] + dp[v][k]);
                    }
                }
            }
        }
    };

    dfs(dfs, 0, -1, m);
    cout << dp[0][m+1] << endl;
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