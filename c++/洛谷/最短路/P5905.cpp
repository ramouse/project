#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define endl '\n'

const ll INF = 1e18;
struct node{
    ll to;
    ll w;
};

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    ll n,m;
    cin>>n>>m;
    vector<node> adj[n+1];

    for(int i = 1;i<=m;i++){
        ll u,v,w;
        cin>>u>>v>>w;
        adj[u].push_back({v,w});
    }

    vector<ll> cnt(n+1,0);
    vector<bool> vis(n+1,false);
    vector<ll> h(n+1,0);
    queue<ll> q;
    for(int i = 1;i<=n;i++){
        q.push(i);
        vis[i] = true;
        cnt[i] = 1;
    }

    while(!q.empty()){
        auto u = q.front();
        q.pop();

        vis[u] = false;

        for(auto &edge : adj[u]){
            ll v = edge.to;
            ll w = edge.w;

            if(h[v]>h[u]+w){
                h[v] = h[u] + w;
                if(!vis[v]){
                    vis[v] = true;
                    cnt[v]++;
                    if(cnt[v]>n){
                        cout<<-1<<endl;
                        return 0;
                    }
                    q.push(v);
                }
            }
        }
    }

    for(int i = 1;i<=n;i++){
        for(auto &edge : adj[i]){
            edge.w = edge.w + h[i] - h[edge.to];
        }
    }

    
    
    
    

    for(int i = 1;i<=n;i++){
        ll ans = 0;
        vector<ll> dist(n + 1, INF);
        priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>> pq;
        vis.resize(n + 1, false);
        pq.push({0,i});
        dist[i] = 0;

        while(!pq.empty()){
            auto [d,u] = pq.top();
            pq.pop();


            if(d>dist[u]) continue;
            // if(vis[u]) continue;
            // vis[u] = true;

            for(auto &edge : adj[u]){
                ll v = edge.to;
                ll w = edge.w;

                if(dist[v] > dist[u]+w){
                    dist[v] = dist[u] + w;
                    pq.push({dist[v],v});
                }
            }
        }

        for(int j = 1;j<=n;j++){
            if(dist[j] == INF){
                ans+=(ll)j * 1000000000LL;
            }else{
                ans+=(ll)j*(dist[j] - h[i] + h[j]);
            }
        }
        cout<<ans<<endl;
    }

    
    
    return 0;
}