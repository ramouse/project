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

ll qpow(ll a, ll b)
{
    ll res = 1;
    while (b)
    {
        if (b & 1)
            res *= a;
        a *= a;
        b /= 2;
    }
    return res;
}

void solve()
{
    ll n;
    cin>>n;
    vector<vector<ll>> adj(n+1);
    for(int i = 1;i<=n;i++){
        ll x;
        while(1){
            cin>>x;
            if(x == 0) break;
            adj[i].pb(x);
        }
    }

    vector<ll> dfn(n+1,0),low(n+1,0);
    vector<ll> bel(n+1,0);
    vector<ll> scc_sz(n+1,0);
    vector<ll> stk;
    vector<int> instk(n+1,0);

    ll cnt = 0;
    ll tim = 0;

    auto tarjan = [&](auto &&self,ll u) -> void{
        dfn[u] = low[u] = ++tim;
        stk.pb(u);
        instk[u] = 1;

        for(ll v : adj[u]){
            if(!dfn[v]){
                self(self,v);
                low[u] = min(low[u],low[v]);
            }else if(instk[v]){
                low[u] = min(low[u],dfn[v]);
            }
        }

        if(low[u] == dfn[u]){
            cnt++;

            while(1){
                ll x = stk.back();
                stk.pop_back();
                instk[x] = 0;

                bel[x] = cnt;
                scc_sz[cnt]++;

                if(x == u) break;
            }
        }
    };

    for(int i = 1;i<=n;i++){
        if(!dfn[i]){
            tarjan(tarjan,i);
        }
    }

    vector<vector<ll>> dag(cnt+1);

    for(int i = 1;i<=n;i++){
        for(ll j : adj[i]){
            if(bel[i] != bel[j]) dag[bel[i]].pb(bel[j]);
        }
    }

    for(int i = 1;i<=cnt;i++){
        sort(all0(dag[i]));
        dag[i].erase(unique(all0(dag[i])),dag[i].end());
    }

    vector<ll> in(cnt+1,0),out(cnt+1,0);
    for(int i = 1;i<=cnt;i++){
        for(ll v : dag[i]){
            out[i]++;
            in[v]++;
        }
    }

    ll ans1 = 0;
    for(int i = 1;i<=cnt;i++){
        if(in[i] == 0) ans1++;
    }

    if(cnt == 1){
        cout<<ans1<<endl<<0<<endl;
        return;
    }
    
    ll ans2 = 0;
    ll cnt1 = 0,cnt2 = 0;
    for(int i =1;i<=cnt;i++){
        if(in[i] == 0) cnt1++;
        if(out[i] == 0) cnt2++;
    }

    ans2 = max(cnt1,cnt2);
    cout<<ans1<<endl<<ans2<<endl;

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