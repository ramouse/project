#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define endl '\n'

const ll INF = 1e18;
const int MOD = 100003;

int main(){
    ll n,m;
    cin>>n>>m;
    vector<ll> adj[n+1];
    for(int i = 1;i<=m;i++){
        ll u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<ll> cnt(n+1,1);
    vector<ll> dist(n+1,INF);
    priority_queue<pair<ll,ll>,vector<pair<ll,ll>>,greater<pair<ll,ll>>> pq;
    pq.push({0,1});
    dist[1] = 0;

    while(!pq.empty()){
        auto [d,u] = pq.top();
        pq.pop();

        if(d>dist[u]) continue;

        for(ll v : adj[u]){
            if(dist[v] == dist[u]+1){
                cnt[v] = (cnt[v]+cnt[u]) % MOD;
            }
            if(dist[v]>dist[u]+1){
                dist[v] = dist[u]+1;
                cnt[v] = cnt[u];
                pq.push({dist[v],v});
            }
        }
    }

    

    for(int i = 1;i<=n;i++){
        if(dist[i] != INF){
            cout<<cnt[i]<<endl;
        }else{
            cout<<0<<endl;
        }
    }

    return 0;
}