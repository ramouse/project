#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define endl '\n'

const ll N = 1e9;
const ll MOD = 676767677;

void solve()
{
    ll n;
    cin>>n;
    vector<vector<ll>> adj(n+1);
    for(int i = 2;i<=n;i++){
        ll x;
        cin>>x;
        adj[x].push_back(i);
    }
    
    vector<ll> dep(n+1,0);

    ll ans = n;
    auto dfs = [&](auto &&self,ll u,ll fa,ll d) -> ll{
        dep[u] = d;
        ll mx1 = -1,mx2 = -1;
        for(ll v : adj[u]){
            if(v == fa) continue;
            ll ma = self(self,v,u,d+1);
            if(ma > mx1){
                mx2 = mx1;
                mx1 = ma;
            }else if(ma > mx2){
                mx2 = ma;
            }
        }
        if(mx2 != -1) ans += mx2  - dep[u];

        return max(mx1,d);
    };
    dfs(dfs,1,0,1);
    // for(int i = 1;i<=n;i++){
    //     cout<<dep[i]<<" "; 
    // }
    cout<<ans<<endl;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t = 1;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}