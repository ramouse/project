#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define endl '\n'

const ll MOD = 10000;
const ll INF = 1e18;

void solve()
{
    ll n,m,k;
    cin>>n>>m>>k;
    vector<vector<ll>> adj(n+1);
    for(int i = 1;i<=m;i++){
        ll u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<int> vis(n+1,0);
    for(int i = 1;i<=k;i++){
        ll x;
        cin>>x;
        // cout<<x<<endl;
        vis[x] = 2;
        for(ll v : adj[x]){
            if(vis[v] == 0) vis[v] = 1;
        }
    }

    // auto dfs = [&](auto &&self,ll u,ll fa) -> void{
    //     for(ll v : adj[u]){
    //         if(v != fa){
    //             if(vis[u] == 2 || vis[u] == 0){
    //                 vis[v] = 1;
    //             }
    //             self(self,v,u);
    //         }
    //     }
    // };

    // for(int i = 1;i<=n;i++){
    //     cout<<vis[i]<<" ";
    // }
    // cout<<endl;

    for(int i = 1;i<=n;i++){
        if(vis[i] == 1){
            ll cnt = 0;
            for(ll v : adj[i]){
                if(vis[v] == 2){
                    cnt++;
                }
            }
            // cout<<cnt<<endl;
            if(cnt>=2){
                for(ll v : adj[i]){
                    if(vis[v] == 0) {
                        vis[v] = 1;
                    }
                }
            }
        }
    }

    // for(int i = 1;i<=n;i++){
    //     if(vis[i] == 2){
    //         // cout<<i<<" "; 
    //         dfs(dfs,i,0);
    //     }
    // }
    ll ans = 0;
    for(int i = 1;i<=n;i++){
        if(vis[i] == 1){
            ans++;
        }
    }
    cout<<ans<<endl;
    for(int i = 1;i<=n;i++){
        if(vis[i] == 1){
            cout<<i<<" ";
        }
    }
    cout<<endl;
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