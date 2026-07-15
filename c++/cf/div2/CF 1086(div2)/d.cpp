#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define endl '\n'

struct DSU{
    vector<ll> parent;
    vector<ll> siz;
    ll count;
    DSU(ll n) : parent(n+1),siz(n+1,1),count(n){
        iota(parent.begin(),parent.end(),0);
    }

    ll find(ll x){
        return parent[x] == x ? x : parent[x] = find(parent[x]);
    }

    bool merge(ll x,ll y){
        ll root_x = find(x);
        ll root_y = find(y);

        if(root_x == root_y) return false;

        if(siz[root_x]<siz[root_y]) swap(root_x,root_y);

        parent[root_y] = root_x;
        siz[root_x]+=siz[root_y];
        count--;
        return true;
    }

    bool connected(ll x,ll y){
        return find(x) == find(y);
    }
};

void solve(){
    ll n;
    cin>>n;
    vector<vector<ll>> vec(n+1,vector<ll>(n+1,0));
    for(int i = 1;i<=n;i++){
        string s;
        cin>>s;
        for(int j = 0;j<n;j++){
            vec[i][j + 1] = s[j]-'0';
        }
    }


    vector<pair<ll,ll>> ans;
    for(int i = 1;i<=n;i++){
        for(int j = 1;j<=n;j++){
            if(i == j || vec[i][j] == 0) continue;
            bool ok = true;
            for(int k = 1;k<=n;k++){
                if(i == k || j == k) continue;
                if(vec[i][k] && vec[k][j]){
                    ok = false;
                    break;
                }
                
            }

            if(ok){
                ans.push_back({i,j});
            }
            
        }
    }

    DSU dsu(n);
    ll co = 0;
    for(auto [u,v] : ans){
        if(dsu.merge(u,v)){
            co++;
        }else{
            cout<<"NO"<<endl;
            return;
        }
    }
    if(ans.size() != n-1){
        cout<<"NO"<<endl;
        return;
    }

    vector<vector<ll>> adj(n+1,vector<ll>(n+1,0));
    for(auto [u,v] : ans)
    {
        adj[u].push_back(v);
    }
    vector<bool> vis(n+1,false);
    queue<ll> q;
    for(int i = 1;i<=n;i++){
        q.push(i);
        vis[i] = true;
        while(!q.empty()){
            auto u = q.front();
            q.pop();
            for (auto v : adj[u])
            {
                if(!vis[v]){
                    vis[v] = true;
                    q.push(v);
                }
                
            }
        }
        
        for(int j = 1;j<=n;j++){
            if(vec[i][j] && !vis[j]){
                cout<<"NO"<<endl;
                return;
            }
            if(!vec[i][j] && vis[j]){
                cout<<"NO"<<endl;
                return;
            }
        }

        for(int j = 1;j<=n;j++){
            vis[j] = false;
        }
        
    }

    cout<<"YES"<<endl;
    for(auto [u,v] : ans){
        cout<<u<<" "<<v<<endl;
    }
}

int main(){
    int t;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}