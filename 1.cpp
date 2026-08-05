#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define endl '\n'

const ll MOD = 10000;
const ll INF = 1e18;
struct Node
{
    ll to, w, t;
};

void solve()
{
    ll n, k;
    cin >> n >> k;
    vector<vector<Node>> adj(n + 1);
    for (int i = 1; i <= n - 1; i++)
    {
        ll u, v, w, t;
        cin >> u >> v >> w >> t;
        adj[u].push_back({v, w, t});
        adj[v].push_back({u, w, t});
    }

    ll ans = 0;
    ll cur = 0;
    auto dfs = [&](auto &&self,ll u,ll fa,ll ma,ll mi,ll sum) -> void{
        for(auto [v,w,t] : adj[u]){
            if(v != fa){
                ma = max(ma,w);
                mi = min(mi,t);
                if(ma - mi <= k){
                    ans = max(ans,sum+w);
                }
                self(self, v, u, ma, mi,sum+w);
            }
        }
    };

    dfs(dfs,1,0,0,INF,0);
    cout<<ans<<endl;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t = 1;
    // cin >> t;
    while (t--)
        solve();
}