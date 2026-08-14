#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define endl '\n'
#define pll pair<ll, ll>
#define T tuple<ll, ll, ll>
#define all1(x) x.begin() + 1, x.end()
#define all0(x) x.begin(), x.end()
#define pb(x) push_back(x)
#define fir first
#define sec second

const ll MOD = 10000;
const ll INF = 1e18;

void solve()
{
    ll n;
    cin>>n;
    vector<bool> vis(n+1,0);
    vector<vector<ll>> adj(n+1);

    string s;
    cin>>s;
    s = " " + s;
    ll idx1 = -1;
    for(int i = 1;i<=n;i++){
        vis[i] = s[i] - '0';
        if(vis[i]) idx1 = i;
    }

    for(int i = 1;i<n;i++){
        ll u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    ll idx2 = -1;
    ll cur = 0;
    auto dfs1 = [&](auto &&self,ll u,ll fa,ll d) -> void{
        for(ll v : adj[u]){
            if(v != fa){
                if(vis[v]){
                    if(d + 1 > cur){
                        cur = d+1;
                        idx2 = v;
                    }
                }
                self(self,v,u,d+1);
            }
        }
    };
    dfs1(dfs1,idx1,-1,0);

    ll idx3 = -1;
    cur = 0;
    vector<ll> d1(n+1,0);
    auto dfs2 = [&](auto &&self, ll u, ll fa, ll d) -> void
    {
        d1[u] = d;
        for (ll v : adj[u])
        {
            if (v != fa)
            {
                if (vis[v])
                {
                    if (d + 1 > cur)
                    {
                        cur = d + 1;
                        idx3 = v;
                    }
                }
                self(self, v, u, d + 1);
            }
        }
    };
    dfs2(dfs2,idx2,-1,0);

    vector<ll> d2(n+1,0);
    auto dfs3 = [&](auto &&self, ll u, ll fa, ll d) -> void
    {
        d2[u] = d;
        for (ll v : adj[u])
        {
            if (v != fa)
            {
                self(self, v, u, d + 1);
            }
        }
    };
    dfs3(dfs3,idx3,-1,0);

    for(int i = 1;i<=n;i++){
        cout<<max({d1[i],d2[i],d1[idx3]})<<endl;
    }
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