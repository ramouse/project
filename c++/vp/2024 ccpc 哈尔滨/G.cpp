#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define endl '\n'

const ll N = 1e9+5;
const ll MOD = 10007;

void solve(){
    ll n,m,k;
    cin>>n>>m>>k;
    vector<ll> a(n+1,0);
    for(int i = 1;i<=k;i++){
        ll t;
        cin>>t;
        a[t] = 1;
    }
    vector<vector<ll>> adj(n+1);
    for(int i = 1;i<=m;i++){
        ll u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<int> vis(n+1,0);
    bool ok = true;
    auto dfs = [&](auto &&self,ll u,ll fa) -> void{
        vis[u] = 1;

        if(!a[u]){
            for (auto v : adj[u])
            {
                if (v != fa)
                {
                    self(self,v,u);
                }
            }
        }
        
    };

    dfs(dfs, 1, 0);
    for(int i = 1;i<=n;i++){
        if(!vis[i]){
            ok = false;
            break;
        }
    }
    

    
    if (ok)
    {
        cout << "Yes" << endl;
    }
    else
    {
        cout << "No" << endl;
        return;
    }

    for(int i = 2;i<=n;i++) vis[i] = 0;
    queue<ll> q;
    vector<vector<ll>> ans;
    vector<ll> te;

    // cout<<1<<" "<<adj[1].size()<<" ";
    te.push_back(1),te.push_back(adj[1].size());
    for(ll v : adj[1]){
        if(v != 1){
            // cout<<v<<" ";
            te.push_back(v);
            vis[v] = 1;
        }
        if(!a[v]) q.push(v);
    }
    // cout<<endl;
    ans.push_back(te);
    while(!te.empty()) te.pop_back();

    while(!q.empty()){
        ll u = q.front();
        q.pop();
        vector<ll> vec;
        
        for(ll v : adj[u]){
            if(vis[v] != 1){
                vec.push_back(v);
                if(!a[v]) q.push(v); 
            }
        }
        bool ok = true;
        if(vis[u] == 1){
            // cout << u << " " << vec.size() << " ";
            te.push_back(u),te.push_back(vec.size());
            for (auto v : vec)
            {
                // cout << v << " ";
                if(vis[v] != 2){
                    te.push_back(v);
                    vis[v] = 2;
                }else{
                    ok = false;
                }
                
            }
            if(ok) ans.push_back(te);
            // cout << endl;
        }
        while(!te.empty()) te.pop_back();
        
    }

    cout<<ans.size()<<endl;
    for(auto temp : ans){
        for(auto u : temp){
            cout<<u<<" ";
        }
        cout<<endl;
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