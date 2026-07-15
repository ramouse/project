#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define endl '\n'

const ll N = 1e9;
const ll MOD = 676767677;

void solve(){
    ll n;
    cin>>n;
    vector<ll> a(n+1,0),sz(n+1,0);
    for(int i = 1;i<=n;i++){
        cin>>a[i];
    }

    vector<vector<ll>> adj(n+1);
    for(int i = 1;i<n;i++){
        ll u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    ll ans = 0;
    vector<ll> sum1(n+1,0),sum2(n+1,0);

    auto dfs = [&](auto &&self,ll u,ll fa) -> void{
        sz[u] = 1;
        ll s = 0,su1 = 0,su2 = 0;
        for(ll v : adj[u]){
            if(fa == v) continue;
            self(self,v,u);

            su2 += sz[v] * su1;
            su1 += sz[v] * s;
            s += sz[v];

            sz[u] += sz[v];
        }

        if(fa != 0){
            su2 += (n - sz[u]) * su1;
            su1 += (n - sz[u]) * s;
        }

        ll num = (ll)sqrt(a[u]);
        if(num * num == a[u]){
            ans += su1 + su2;
        }
    };
    dfs(dfs,1,0);

    cout<<ans<<endl;

}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t = 1;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}