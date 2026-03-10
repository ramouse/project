#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define endl '\n'

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    ll n;
    cin>>n;
    vector<vector<ll>> adj(n+1);
    vector<ll> a(n+1,0);
    for(int i = 1;i<=n;i++)
    {
        cin>>a[i];
    }
    for(int i = 1;i<=n-1;i++){
        ll u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    set<ll> pre;
    vector<bool> ans(n+1,1);

    auto dfs = [&](auto &&self,ll u,ll fa,bool cha) -> void{
        bool xin = false;
        if(pre.count(a[u])){
            cha = true;
        }else{
            pre.insert(a[u]);
            xin = true;
        }

        if(cha) ans[u] = 0;

        for(ll &v : adj[u]){
            if(v == fa) continue;
            self(self,v,u,cha);
        }
        if(xin) pre.erase(a[u]);
    };


    dfs(dfs,1,0,false);
    cout<<"No"<<endl;
    for(int i = 2;i<=n;i++){
        if(ans[i]) cout<<"No"<<endl;
        else{
            cout<<"Yes"<<endl;
        }
    }

    return 0;
}