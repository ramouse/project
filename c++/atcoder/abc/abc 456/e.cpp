#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define endl '\n'

const ll MOD = 998244353;
const ll MAXN = 2e5 + 5;

void solve()
{
    ll n,m;
    cin>>n>>m;
    map<ll,ll> mp;
    prev(mp.upper_bound(n));
    vector<vector<ll>> adj(n+1);
    vector<string> s(n+1);
    for(int i = 1;i<=m;i++){
        ll u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    ll w;
    cin>>w;
    for(int i = 1;i<=n;i++){
        cin>>s[i];
        // s[i] = " "+s[i];
    }

    vector<vector<ll>> vis(n+1,vector<ll>(w+1,0));

    auto check = [&](auto &&self,ll u,ll dd) -> bool{
        vis[u][dd] = 1;
        ll d = (dd+1)%w;

        if(s[u][d]=='o'){
            if(vis[u][d]==1) return 1;
            if(vis[u][d]==0 && self(self,u,d)) return 1;
        }

        for(ll &v : adj[u]){
            if(s[v][d]=='o'){
                if(vis[v][d]==1) return 1;
                if(vis[v][d]==0 && self(self,v,d)) return 1;
            }
        }

        vis[u][dd] = 2;
        return 0;

    };

    for(int i = 1;i<=n;i++){
        if(s[i][0]=='o' && vis[i][0] == 0){
            if(check(check,i,0)){
                cout<<"Yes"<<endl;
                return;
            }
        }
    }

    cout<<"No"<<endl;

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