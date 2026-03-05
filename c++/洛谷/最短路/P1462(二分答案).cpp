#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define endl '\n'
#define pll pair<ll,ll>

const ll INF = 1e18;

struct node{
    ll to;
    ll w;
};


int main(){
    ll n,m,b;
    cin>>n>>m>>b;
    ll l = INF,r = 0;;
    vector<ll> f(n+1,0);
    for(int i = 1;i<=n;i++){
        cin>>f[i];
        r = max(r,f[i]);
    }
    l = max(f[1], f[n]); // 二分的下界必须是起点和终点费用的最大值

    vector<node> adj[n+1];
    for(int i = 1;i<=m;i++){
        ll u,v,w;
        cin>>u>>v>>w;
        adj[u].push_back({v,w});
        adj[v].push_back({u,w});
    }

    vector<ll> dist(n+1,INF);
    priority_queue<pll,vector<pll>,greater<pll>> pq;
    
    auto dij = [&](ll mid){
        for(int i = 1;i<=n;i++) dist[i] = INF;
        pq.push({0,1});
        dist[1] = 0;

        while(!pq.empty()){
            auto [d,u] = pq.top();
            pq.pop();

            if(d>dist[u]) continue;
            

            for(auto &edge : adj[u]){
                ll v = edge.to;
                ll w = edge.w;
                if(f[v]>mid) continue;
                if(dist[v]>dist[u]+w){
                    dist[v] = dist[u]+w;
                    pq.push({dist[v],v});
                }
            }
        }
        return dist[n]<=b;
    };

    if(!dij(INF)){
        cout<<"AFK"<<endl;
        return 0;
    }

    ll ans = 0;
    while(l<=r){
        ll mid = (l+r)>>1;
        if(dij(mid)){
            r = mid-1;
            ans = mid;
        }else{
            l = mid+1;
        }
    }
    cout<<ans<<endl;
    return 0;
}