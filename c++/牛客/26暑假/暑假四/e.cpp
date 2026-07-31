#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define endl '\n'

const ll INF = 1e18;

struct Node{
    ll u,v,w;
};

void solve()
{
    ll n,m,q;
    cin>>n>>m>>q;
    vector<Node> edge(m+1);
    vector<vector<pair<ll,ll>>> adj(n+1);
    for(int i = 1;i<=m;i++){
        cin>>edge[i].u>>edge[i].v>>edge[i].w;
        adj[edge[i].u].push_back({edge[i].v,edge[i].w});
    }

    vector<vector<ll>> dist(n+1,vector<ll>(n+1,INF));
    priority_queue<pair<ll,ll>,vector<pair<ll,ll>>,greater<pair<ll,ll>>> pq;

    for(int i = 1;i<=n;i++){
        pq.push({0,i});
        dist[i][i] = 0;

        while(!pq.empty()){
            auto [d,u] = pq.top();
            pq.pop();

            for(auto [v,w] : adj[u]){
                if(dist[i][u] + w < dist[i][v]){
                    dist[i][v] = d + w;
                    pq.push({dist[i][v],v});
                }
            }
        }
    }


    while(q--){
        ll k,x;
        cin>>k>>x;

        ll uk = edge[k].u;
        ll vk = edge[k].v;

        double ans = 0.0;
        for(int i = 1;i<=m;i++){
            ll u = edge[i].u;
            ll v = edge[i].v;

            ll ba = min(dist[v][u],dist[v][uk] + x + dist[vk][u]);
            ll ab = min(dist[u][v],dist[u][uk] + x + dist[vk][v]);

            ans = max(ans,(double)ba/ab);
        }

        cout<<fixed<<setprecision(12)<<ans<<endl;
    }

}

int main()
{
    int t = 1;
    cin >> t;
    while (t--)
        solve();
}