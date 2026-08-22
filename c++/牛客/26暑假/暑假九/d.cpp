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
const ll LOG = 30;

void solve()
{
    ll n,m;
    cin>>n>>m;
    vector<vector<ll>> adj(n+1);
    for(int i = 1;i<=n-1;i++){
        ll u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<ll> dep(n+1,0);
    vector<ll> in(n+1,0),out(n+1,0);
    vector<vector<ll>> up(n+1,vector<ll>(LOG+1,0));
    ll tim = 0;

    auto dfs1 = [&](auto &&self,ll u,ll fa,ll d) -> void{
        in[u] = ++tim;
        dep[u] = d;
        up[u][0] = fa;

        for(int i = 1;i<=LOG;i++){
            if(up[u][i-1] != 0){
                up[u][i] = up[up[u][i-1]][i-1];
            }else{
                up[u][i] = 0;
            }
        }

        for(ll v : adj[u]){
            if(v != fa){
                self(self,v,u,d+1);
            }
        }

        out[u] = ++tim;
    };

    dfs1(dfs1,1,0,1);

    vector<pll> people(m+1);
    map<ll,vector<ll>> group;
    for(int i = 1;i<=m;i++){
        ll x,s;
        cin>>x>>s;
        people[i] = {x,s};
        ll c = dep[x] + s;
        group[c].push_back(i);
    }

    auto isAncestor = [&](ll u,ll v) -> bool{
        return in[u] <= in[v] && out[v] <= out[u];
    };

    auto get_lca = [&](ll u,ll v){
        if(dep[u] < dep[v]){
            swap(u,v);
        }

        for(ll i = LOG;i>=0;i--){
            if(dep[up[u][i]] >= dep[v]){
                u = up[u][i];
            }
        }

        if(u == v){
            return u;
        }

        for(int i = LOG;i>=0;i--){
            if (up[u][i] != up[v][i])
            {
                u = up[u][i];
                v = up[v][i];
            }
        }

        return up[u][0];
    };



    vector<vector<ll>> vt_adj(n + 1);
    vector<ll> vis(n + 1, 0);
    string ans = string(m, '0');

    auto dfs2 = [&](auto &&self,ll u) -> ll{
        ll living = 0;
        ll id = -1;

        if(vis[u] == -1){
            living = 2;
        }else if(vis[u] > 0){
            living++;
            id = vis[u];
        }

        for(ll v : vt_adj[u]){
            ll res = self(self,v);
            if(res > 0){
                living++;
                id = res;
            }
        }

        if(living >= 2) return -1;
        if(living == 1) return id;
        return 0;
    };



    for(auto &[c,list] : group){
        map<ll,ll> start_cnt;
        map<ll,ll> start_id;

        for(ll id : list){
            ll u = people[id].first;
            start_cnt[u]++;
            start_id[u] = id;
        }

        vector<ll> node;
        for(auto [u,cnt] : start_cnt){
            node.push_back(u);
            if(cnt > 1){
                vis[u] = -1;
            }else{
                vis[u] = start_id[u];
            }
        }

        sort(all0(node),[&](ll x,ll y){
            return in[x] < in[y];
        });
        ll siz = node.size();
        for(int i = 0;i<siz-1;i++){
            node.push_back(get_lca(node[i],node[i+1]));
        }
        sort(all0(node),[&](ll x,ll y){
            return in[x] < in[y];
        });
        node.erase(unique(all0(node)),node.end());


        vector<ll> st;
        for(ll u : node){
            if(st.empty()){
                st.pb(u);
                continue;
            }

            while(!st.empty() && get_lca(st.back(),u) != st.back()){
                st.pop_back();
            }

            if(!st.empty()){
                vt_adj[st.back()].pb(u);
            }
            st.push_back(u);
        }

        ll root = node[0];
        ll id = dfs2(dfs2,root);

        if(id > 0) ans[id - 1] = '1';

        for(ll u : node){
            vt_adj[u].clear();
            vis[u] = 0;
        }
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