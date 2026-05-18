#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define endl '\n'

void solve()
{
    ll n,m,k;
    cin>>n>>m>>k;
    vector<int> a(n+1,0);
    vector<vector<ll>> adj(n+1);
    for(int i = 1;i<=k;i++){
        ll t;
        cin>>t;
        a[t] = 1;
    }

    for(int i = 1;i<=m;i++){
        ll u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    if(k == n){
        cout<<"No"<<endl;
        return;
    }

    queue<ll> q;
    vector<bool> vis(n+1,0);
    ll index = -1;
    for(int i = 1;i<=n;i++){
        if(!a[i]){
            index = i;
            break;
        }
    }

    q.push(index);
    vis[index] = 1;
    ll coun = 1;
    vector<vector<ll>> ans;

    while(!q.empty()){
        ll u = q.front();
        q.pop();

        vector<ll> vec;

        for(ll v : adj[u]){
            if(!vis[v]){
                coun++;
                vis[v] = 1;
                vec.push_back(v);
                if(!a[v]){
                    q.push(v);
                }
            }
        }

        if(!vec.empty()){
            vector<ll> step;
            step.push_back(u),step.push_back(vec.size());
            for(auto v : vec){
                step.push_back(v);
            }
            ans.push_back(step);
        }
    }

    if(coun != n){
        cout<<"No"<<endl;
    }else{
        cout<<"Yes"<<endl;
        cout<<ans.size()<<endl;
        for(auto &vec : ans){
            for(auto v : vec){
                cout<<v<<" ";
            }
            cout<<endl;
        }
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t = 1;
    // cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}