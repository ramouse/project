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
const ll N = 19;

void solve()
{
    ll n,q;
    cin>>n>>q;

    vector<ll> tree(1<<(n+1),1<<n);
    vector<ll> ls(1<<(n+1),0),rs(1<<(n+1),0);
    for(int i = 1;i<=(1<<n) - 1;i++){
        ls[i] = i<<1;
        rs[i] = i<<1 | 1;
    }

    vector<ll> req(1<<(n+1),0);
    bool ok = true;
    for(int i = 1;i<=q;i++){
        ll u,x;
        cin>>u>>x;
        if(req[u] != 0 && req[u] != x){
            ok = false;
        }
        req[u] = x;
        tree[u] = x;
    }

    if(!ok){
        cout<<0<<endl;
        return;
    }

    vector<ll> top(1<<n|1,0),bot(1<<n|1,0);
    vector<ll> in(1<<(n+1),0),out(1<<(n+1),0);
    vector<ll> dep(1<<(n+1),0);
    ll tim = 0;
    auto dfs1 = [&](auto &&self, ll u, ll lim,ll d) -> void
    {
        in[u] = ++tim;
        dep[u] = d;

        if(req[u] != 0){
            lim = min(lim,req[u]);
            ll x = req[u];

            if (top[x] == 0 || d < dep[top[x]])
                top[x] = u;
            if (bot[x] == 0 || d > dep[bot[x]])
                bot[x] = u;
        }
        tree[u] = lim;


        if(ls[u] == 0 && rs[u] == 0){
            out[u] = ++tim;
            return;
        }

        self(self,ls[u],lim,d+1);
        self(self,rs[u],lim,d+1);

        out[u] = ++tim;
    };

    auto is_an = [&](ll u,ll v) -> bool{
        return in[u] <= in[v] && out[v] <= out[u];
    };

    dfs1(dfs1,1,1<<n,1);

    for(int i = 1;i<(1<<(n+1));i++){
        if(!req[i]) continue;

        ll x = req[i];

        if(!is_an(top[x],i) || !is_an(i,bot[x])){
            cout<<0<<endl;
            return;
        }
    }

    vector<ll> v(1<<n|1,0),c(1<<n|1,0);
    for(int i = (1<<n);i<(1<<(n+1));i++){
        ll x = tree[i];
        v[x]++;
        if(bot[x] != 0 && is_an(bot[x],i)){
            c[x]++;
        }
    }


    ll ans = 1;

    ll pre = 0;

    for(int i = 1<<n;i>=1;i--){
        pre += v[i];
        ll part = 0;

        if(bot[i] != 0){
            part = c[i];
        }else{
            part = pre;
        }

        if(part == 0){
            cout<<0<<endl;
            return;
        }

        ans = ans * part % MOD;
        pre--;
    }
    cout<<ans<<endl;
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