#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define endl '\n'

const ll INF = 1e18;
const ll MAXN = 3e5+5;
const ll MOD = 998244353;

struct Node{
    ll u,v,w;
};

struct DSU
{
    vector<ll> par;
    vector<ll> siz;
    ll count;

    DSU(ll n) : par(n+1),siz(n+1,1),count(n){
        iota(par.begin(),par.end(),0);
    }

    ll find(ll x){
        return par[x] == x ? x : par[x] = find(par[x]);
    }

    bool mereg(ll x,ll y){
        ll rootx = find(x);
        ll rooty = find(y);

        if(rootx == rooty) return false;

        if(siz[rootx] < siz[rooty]) swap(rootx,rooty);

        par[rooty] = rootx;
        siz[rootx]+=siz[rooty];
        count--;
        return true;
    }

    void era(){
        iota(par.begin(),par.end(),0);
    }
};

void solve()
{   
    ll n,m,L;
    cin>>n>>m>>L;
    vector<vector<Node>> adj(3);
    ll fu = 0;
    for(int i = 1;i<=m;i++){
        ll u,v,b,k;
        cin>>u>>v>>b>>k;
        k++;
        adj[k].push_back({u,v,b});
    }

    DSU dsu(n);

    for(int i = 0;i<3;i++){
        sort(adj[i].begin(),adj[i].end(),[&](const auto&x,const auto&y){
            return x.w>y.w;
        });
    }
    
    auto check = [&](ll k) -> ll{
        ll cou = 0;
        ll res = 0;
        vector<ll> p(3);
        dsu.era();
        while(p[0] < adj[0].size() || p[1] < adj[1].size() || p[2] < adj[2].size()){
            ll cur = -INF;
            ll index = -1;
            if(p[0] < adj[0].size() && adj[0][p[0]].w - k > cur){
                cur = adj[0][p[0]].w - k;
                index = 0;
            }
            if(p[1] < adj[1].size() && adj[1][p[1]].w > cur){
                cur = adj[1][p[1]].w;
                index = 1;
            }
            if(p[2]<adj[2].size() && adj[2][p[2]].w + k > cur){
                cur = adj[2][p[2]].w + k;
                index = 2;
            }
            if(index == -1) break;
            if(dsu.mereg(adj[index][p[index]].u,adj[index][p[index]].v)){
                res += cur;
                cou++;
            }
            p[index]++;
            if(cou == n-1) break;
        }
        return res;
    };

    ll l = 0,r = L;
    while(r - l > 2){
        ll m1 = l + (r-l)/3;
        ll m2 = r - (r - l)/3;

        if(check(m1) <= check(m2)){
            r = m2;
        }else{
            l = m1;
        }
    }
    ll ans = INF;
    for(int i = l;i<=r;i++){
        ans = min(ans,check(i));
    }
    cout<<ans<<endl;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t = 1;
    // cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}