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
    }

    vector<ll> dfn(n+1,0),low(n+1,0);
    vector<ll> bel(n+1,0);
    vector<ll> scc_sz(n+1,0);
    vector<ll> stk;
    vector<int> instk(n+1,0);
    
    ll tim = 0;
    ll cnt = 0;

    auto tarjan = [&](auto &&self,ll u) -> void{
        dfn[u] = low[u] = ++tim;

        stk.pb(u);
        instk[u] = 1;

        for(ll v : adj[u]){
            if(dfn[v] == 0){
                self(self,v);
                low[u] = min(low[u],low[v]);
            }else if(instk[v]){
                low[u] = min(low[u],dfn[v]);
            }
        }

        if(dfn[u] == low[u]){
            cnt++;
            while(1){
                ll x = stk.back();
                stk.pop_back();
                instk[x] = 0;
                bel[x] = cnt;
                scc_sz[cnt]++;

                if(x == u){
                    break;
                }
            }
        }
    };

    for(int i = 1;i<=n;i++){
        if(dfn[i] == 0){
            tarjan(tarjan,i);
        }
    }

    vector<vector<ll>> g(cnt+1);

    
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