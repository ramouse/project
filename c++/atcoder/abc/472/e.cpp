#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using i128 = __int128_t;
#define endl '\n'
#define pll pair<ll, ll>
#define T tuple<ll, ll, ll>
#define all1(x) x.begin() + 1, x.end()
#define all0(x) x.begin(), x.end()
#define pb push_back
#define fir first
#define sec second

const ll MOD = 998244353;
const ll INF = 1e18;

void solve()
{
    ll n,m;
    cin>>n>>m;
    vector<vector<ll>> adj(n+1);

    for(int i = 1;i<=m;i++){
        ll u,v;
        cin>>u>>v;
        adj[u].pb(v);
        adj[v].pb(u);
    }

    vector<int> vis(n+1,-1);
    ll a = -1,b = -1;

    vector<ll> fat(n+1,0);
    vector<ll> dep(n+1,0);

    auto dfs = [&](auto &&self,ll u,ll fa,ll d,ll t) -> void{
        if(a != -1) return;
        fat[u] = fa;
        dep[u] = d;

        for(ll v : adj[u]){
            if(v != fa){
                if(vis[v] == -1){
                    vis[v] = t^1;
                }else if(vis[v] == vis[u]){
                    a = u;
                    b = v;
                    return;
                }
                self(self, v, u, d + 1, t ^ 1);
            }
        }
    };

    vis[1] = 0;
    dfs(dfs,1,0,0,0);
    if(a == -1 && b == -1){
        cout<<-1<<endl;
        return;
    }

    vector<ll> ans1,ans2;
    if(dep[a] < dep[b]) swap(a,b);

    while(dep[a] != dep[b]){
        ans1.pb(a);
        a = fat[a];
    }

    while(a != b){
        ans1.pb(a);
        ans2.pb(b);

        a = fat[a];
        b = fat[b];
    }
    ans1.pb(a);

    cout<<ans1.size() + ans2.size()<<endl;
    for(ll u : ans1){
        cout<<u<<" ";
    }
    reverse(all0(ans2));
    for(ll u : ans2){
        cout<<u<<" ";
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