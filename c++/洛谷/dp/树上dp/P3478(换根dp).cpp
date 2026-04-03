#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define endl '\n'

const ll MOD = 998244353;




void solve()
{
    ll n;
    cin>>n;
    vector<vector<ll>> adj(n+1);
    for(int i= 1;i<=n-1;i++){
        ll u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<ll> dept(n+1,0);
    vector<ll> sz(n+1,0);
    vector<ll> p(n+1,0);
    auto dfs1 = [&](auto &&self,ll u,ll fa,ll d) ->void{
        dept[u] = d;
        sz[u] = 1;
        for(ll v : adj[u]){
            if(v != fa){
                self(self,v,u,d+1);
                sz[u]+=sz[v];
            }
        }
    };
    dfs1(dfs1,1,0,1);

    for(int i = 1;i<=n;i++){
        p[1]+=dept[i];
    }
    auto dfs2 = [&](auto &&self,ll u,ll fa) ->void{
        for(ll v : adj[u]){
            if(v != fa){
                p[v] = p[u] - sz[v] + n - sz[v];
                self(self,v,u);
            }
        }
    };
    dfs2(dfs2,1,0);

    ll ans = -1;
    ll id = -1;
    for(int i = 1;i<=n;i++){
        if(p[i]>ans){
            ans = p[i];
            id = i;
        }
    }
    cout<<id<<endl;
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