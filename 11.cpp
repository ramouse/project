#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define endl '\n'
#define T tuple<ll,ll,ll>
#define pll pair<ll,ll>

const ll MOD = 998244353;
const ll INF = 1e18;

struct Node{
    ll to;
    ll w;
};

void solve()
{
    ll n,m;
    cin>>n>>m;
    vector<vector<Node>> adj(n+1);
    for(int i = 1;i<=m;i++){
        ll u,v,w;
        cin>>u>>v>>w;
        adj[u].push_back({v,w});
        adj[v].push_back({u,w});
    }

    ll k;
    cin>>k;
    vector<ll> a(k+1,0);
    vector<ll> dist(n+1,INF);
    vector<ll> vis(n+1,-1);
    priority_queue<pll,vector<pll>,greater<pll>> pq;
    for(int i = 1;i<=k;i++){
        cin>>a[i];
        pq.push({0,a[i]});
        dist[a[i]] = 0;
        vis[a[i]] = a[i];
    }

    ll ans = INF;
    while(!pq.empty()){
        ll d = pq.top().first;
        ll u = pq.top().second;
        pq.pop();

        if(d>dist[u]) continue;

        for(Node &edge : adj[u]){
            ll to = edge.to;
            ll w = edge.w;

            if(vis[to] != -1 || vis[to] != vis[u]){
                ans = min(ans, dist[to] + dist[u] + w);
            }
            if (dist[to] > dist[u] + w)
            {
                dist[to] = dist[u] + w;
                vis[to] = vis[u];
                pq.push({dist[to], to});
            }
        }
    }

    cout<<ans<<endl;
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