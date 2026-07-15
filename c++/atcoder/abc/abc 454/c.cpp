#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define endl '\n'

void solve(){
    ll n,m;
    cin>>n>>m;
    vector<vector<ll>> adj(n+1);

    ll ans = 1;
    vector<bool> vis(n + 1, 0);
    set<ll> se;
    for(int i = 1;i<=m;i++){
        ll u,v;
        cin>>u>>v;
        adj[u].emplace_back(v);
    }
    vis[1] = 1;



    queue<ll> q;
    q.push(1);
    while(!q.empty()){
        ll u = q.front();
        q.pop();

        for(ll v : adj[u]){
            if(!vis[v]){
                ans++;
                q.push(v);
            }
            vis[v] = 1;
        }
    }

    cout << ans << endl;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    ll t = 1;
    while(t--){
        solve();
    }
    return 0;
}