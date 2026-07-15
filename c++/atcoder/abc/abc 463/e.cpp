#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define endl '\n'

const ll N = 1e9+5;
const ll MOD = 676767677;
const ll INF = 1e18;

struct Node{
    ll to,w;
};

void solve(){
    ll n,m,y;
    cin>>n>>m>>y;
    vector<vector<Node>> adj(n+1);
    for(int i = 1;i<=m;i++){
        ll u,v,w;
        cin>>u>>v>>w;
        adj[u].push_back({v,w});
        adj[v].push_back({u,w});
    }

    vector<ll> c(n+1,0);
    for(int i = 1;i<=n;i++){
        cin>>c[i];

        adj[i].push_back({0,c[i] + y});
        adj[0].push_back({i,c[i]});
    }

    vector<ll> dist(n+1,INF);
    priority_queue<pair<ll,ll>,vector<pair<ll,ll>>,greater<pair<ll,ll>>> pq;
    pq.push({0,1});
    dist[1] = 0;


    while(!pq.empty()){
        auto [d,u] = pq.top();
        pq.pop();
        if(d > dist[u]) continue;

        for(auto &[v,w] : adj[u]){
            if(w + d < dist[v]){
                dist[v] = w + d;
                pq.push({dist[v],v});
            }
        }
    }

    for(int i = 2;i<=n;i++){
        cout<<dist[i]<<" ";
    }

}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t = 1;
    // cin>>t;
    while(t--){
        solve();
    }
    return 0;
}