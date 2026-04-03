#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define endl '\n'

const ll MOD = 998244353;




void solve()
{
    ll n,m;
    cin>>n>>m;
    vector<vector<ll>> adj(n+1);
    for(int i = 1;i<=n-1;i++){
        ll u,v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    vector<ll> dep(n+1,0);
    ll D = 0;
    auto dfs1 = [&](auto &&self,ll u,ll fa,ll d) ->void {
        dep[u] = d;
        D = max(D,d);
        for(auto v : adj[u]){
            if(v != fa){
                self(self,v,u,d+1);
            }
        }
    };
    dfs1(dfs1,1,0,0);

    vector<ll> f(n+1,0);
    f[1] = D+1;
    auto dfs2 = [&](auto &&self,ll u,ll fa) -> void{
        for(auto v : adj[u]){
            if(v != fa){
                f[v] = D-dep[v]+dep[u]+2;
                self(self,v,u);
            }
        }
    };
    dfs2(dfs2,1,0);
    for(int i = 1;i<=n;i++){
        cout<<f[i]<<" ";
    }

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