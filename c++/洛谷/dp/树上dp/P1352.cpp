#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define endl '\n'

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    ll n;
    cin>>n;
    vector<ll> h(n+1,0);
    for(int i = 1;i<=n;i++){
        cin>>h[i];
    }

    vector<vector<ll>> adj(n+1);
    vector<ll> F(n+1,0);
    for(int i = 1;i<=n-1;i++){
        ll u,v;
        cin>>v>>u;
        adj[u].push_back(v);
        F[v] = 1;
    }

    vector<vector<ll>> dp(n+1,vector<ll>(2,0));
    auto dfs = [&](auto &&self,ll u,ll fa) -> void{
        dp[u][1] += h[u];
        for(auto &v : adj[u]){
            if(v == fa) continue;
            self(self,v,u);
            dp[u][1] += dp[v][0];
            dp[u][0] += max(dp[v][0],dp[v][1]);
        }
        return;
    };

    for(int i = 1;i<=n;i++){
        if(!F[i]){
            dfs(dfs,i,0);
            cout<<max(dp[i][0],dp[i][1]);
            return 0;
        }
    }
    return 0;
}