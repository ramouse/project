#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define endl '\n'
#define pll pair<ll,ll>
#define T tuple<ll,ll,ll>

const ll INF = 1e18;

struct Node{
    ll to;
    ll w;
};

int main(){
    ll n,m,k;
    cin>>n>>m>>k;
    ll s,t;
    cin>>s>>t;
    vector<Node> adj[n];
    for(int i = 1;i<=m;i++){
        ll u,v,w;
        cin>>u>>v>>w;
        adj[u].push_back({v,w});
        adj[v].push_back({u,w});
    }

    vector<vector<ll>> dist(n,vector<ll>(k+1,INF));
    priority_queue<T,vector<T>,greater<T>> pq;
    pq.push({0,s,0});
    dist[s][0] = 0;

    while(!pq.empty()){
        auto [d,u,f] = pq.top();
        pq.pop();
        
        if(d>dist[u][f]) continue;

        for(auto &edge : adj[u]){
            ll v = edge.to;
            ll w = edge.w;

            if(dist[v][f]>dist[u][f]+w){
                dist[v][f] = dist[u][f] + w;
                pq.push({dist[v][f],v,f});
            }
            if(f<k){
                if (dist[v][f + 1] > dist[u][f])
                {
                    dist[v][f + 1] = dist[u][f];
                    pq.push({dist[v][f + 1], v, f + 1});
                }
            }
            
        }
    }

    ll ans = INF;
    for(int i = 0;i<=k;i++){
        ans = min(ans,dist[t][i]);
    }
    cout<<ans<<endl;

    return 0;
}