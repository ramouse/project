#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define endl '\n'
#define pll pair<ll,ll>
#define T tuple<ll,ll,ll>

// ll dx[] = {-2,-1,1,2,2,1,-1,-2};
// ll dy[] = {1,2,2,1,-1,-2,-2,-1};


const ll MOD = 998244353;
const ll INF = 1e18;

struct Node{
    ll to;
    ll w;
};

void solve()
{
    ll n,q,s;
    cin>>n>>q>>s;
    vector<vector<Node>> adj(4*n);
    vector<ll> in(4*n,0);
    vector<ll> out(4*n,0);
    ll cnt = n;

    auto build = [&](auto &&self,ll p,ll l,ll r) -> void{
        if(l == r){
            in[p] = l;
            out[p] = l;
            return;
        }

        ll ls = p<<1;
        ll rs = p<<1 | 1;
        ll mid = (l+r)>>1;

        in[p] = ++cnt;
        out[p] = ++cnt;

        self(self,ls,l,mid);
        self(self,rs,mid+1,r);

        adj[in[p]].push_back({in[ls],0});
        adj[in[p]].push_back({in[rs],0});

        adj[out[ls]].push_back({out[p],0});
        adj[out[rs]].push_back({out[p],0});
    };

    auto v_to_range = [&](auto &&self,ll p,ll v,ll w,ll l,ll r,ll ql,ll qr) ->void{
        if(ql<=l && r<=qr){
            adj[v].push_back({in[p],w});
            return;
        }

        ll ls = p << 1;
        ll rs = p << 1 | 1;
        ll mid = (l + r) >> 1;

        if(ql<=mid) self(self,ls,v,w,l,mid,ql,qr);
        if(qr>mid) self(self,rs,v,w,mid+1,r,ql,qr);
    };

    auto range_to_v = [&](auto &&self,ll p,ll v,ll w,ll l,ll r,ll ql,ll qr) -> void{
        if(ql<=l && r<=qr){
            adj[out[p]].push_back({v,w});
            return;
        }

        ll ls = p << 1;
        ll rs = p << 1 | 1;
        ll mid = (l + r) >> 1;

        if(ql<=mid) self(self,ls,v,w,l,mid,ql,qr);
        if(qr>mid) self(self,rs,v,w,mid+1,r,ql,qr);
    };

    build(build,1,1,n);
    
    while(q--){
        ll t;
        cin>>t;
        if(t==1){
            ll v,u,w;
            cin>>v>>u>>w;
            adj[v].push_back({u,w});
        }else{
            ll v,l,r,w;
            cin>>v>>l>>r>>w;
            if(t==2){
                v_to_range(v_to_range,1,v,w,1,n,l,r);
            }else if(t == 3){
                range_to_v(range_to_v,1,v,w,1,n,l,r);
            }
        }
    }

    vector<ll> dist(cnt+1,INF);
    priority_queue<pll,vector<pll>,greater<pll>> pq;
    pq.push({0,s});
    dist[s] = 0;

    while(!pq.empty()){
        auto [d,u] = pq.top();
        pq.pop();

        if(d>dist[u]) continue;

        for(auto &edge : adj[u]){
            ll v = edge.to;
            ll w = edge.w;
            if(dist[v]>dist[u]+w){
                dist[v] = dist[u] + w;
                pq.push({dist[v],v});
            }
        }
    }

    for(ll i = 1;i<=n;i++){
        if(dist[i] == INF){
            cout<<-1<<" ";
        }else{
            cout<<dist[i]<<" ";
        }
    }

}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t = 1;
    // cin >> t;

    while (t--)
    {
        solve();
    }
    return 0;
}