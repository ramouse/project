#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define endl '\n'

const int N = 2e5;
const ll INF = 1e18;

vector<ll> adj[N];

void solve(){
    ll n,m;
    cin>>n>>m;
    vector<ll> deg(n+1,0);
    for(int i = 1;i<=m;i++){
        ll u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
        deg[u]++;
        deg[v]++;
    }

    vector<vector<ll>> group(n+1);
    for(int i =1;i<=n;i++){
        group[deg[i]].push_back(i);
    }
    vector<ll> un;
    for(int i = 0;i<=n;i++){
        if(!group[i].empty()){
            un.push_back(i);
        }
    }
    ll k = un.size();
    vector<ll> dist(n+1,INF);
    vector<ll> ans(n+1,-1);
    queue<ll> q;

    for(ll i = k-1;i>=1;i--){
        for(ll u : group[un[i]]){
            q.push(u);
            dist[u] = 0;
        }

        while(!q.empty()){
            auto d = q.front();
            q.pop();

            for(ll e : adj[d]){
                if(dist[e]>dist[d]+1){
                    dist[e] = dist[d]+1;
                    q.push(e);
                }
            }
        }

        for(ll u : group[un[i-1]]){
            if(dist[u] != INF){
                ans[u] = dist[u];
            }
        }
    }

    for(int i = 1;i<=n;i++) cout<<ans[i]<<" ";

}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t = 1;
    while(t--){
        solve();
    }
    return 0;
}