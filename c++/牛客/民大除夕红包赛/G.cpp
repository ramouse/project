#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define endl '\n'

const int N = 2e5+5;

vector<ll> adj[N];
vector<ll> val(N);
vector<ll> di;
vector<ll> sz(N,0);
bool ok = true;


void dfs(int u,int fa){
    sz[u] = val[u];


    if(adj[u].size() == 1) di.push_back(u);
    if(adj[u].size()>2) ok = false;

    for(int v : adj[u]){
        if(v == fa) continue;
        
        dfs(v,u);
        sz[u] += sz[v];
    }
}

int main(){
    ll n,k;
    cin>>n>>k;

    for(int i = 1;i<=n;i++){
        cin>>val[i];
    }

    for(int i = 1;i<=n-1;i++){
        ll u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    dfs(1,0);
    
    // for(int u : di){
    //     if(sz[u]<k) ok = false;
    // }

    for(int u = 1;u<=n;u++){
        cout<<sz[u]<<" ";
    }
    if(ok) cout<<"Yes"<<endl;
    else cout<<"No"<<endl;

    return 0;
}