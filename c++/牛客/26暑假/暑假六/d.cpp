#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define endl '\n'

const ll MOD = 10000;
const ll INF = 1e18;

void solve()
{
    ll n,m,k;
    cin>>n>>m>>k;
    vector<vector<ll>> adj(n+1);
    vector<bool> can(n+1,0);
    // set<pair<int,int>> se;
    for(int i = 1;i<=m;i++){
        ll u,v;
        cin>>u>>v;

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<vector<ll>> val(n+1,vector<ll>(2,INF));
    vector<int> vis(n+1,0);

    queue<tuple<ll,ll,ll>> q;
    q.push({1,0,0});
    val[1][0] = 0;
    vis[1]++;
 
    while(!q.empty()){
        auto [u,d,fa] = q.front();
        q.pop();

        for(ll v : adj[u]){
            ll nd = 1-d;
            if(val[v][nd] == INF){
                val[v][nd] = val[u][d] + 1;
                q.push({v,nd,fa});
            }
        }
    }

//    for(int i = 2;i<=n;i++){
//         cout<<val[i][0]<<" "<<val[i][1]<<endl;
//    }
   

    vector<ll> ans(n+1,INF);
    ans[1] = 0;
    for(int i = 2;i<=n;i++){
        bool ok = false;
        ll v2 = val[i][0];
        ll v1 = val[i][1];
        if(v1 == INF && v2 == INF){
            ans[i] = -1;
            continue;
        }
        if (k & 1)
        {
            if (v2 != INF)
            {
                ll c = (v2 + k - 1) / k;
                if (c & 1)
                    c++; 
                ans[i] = min(ans[i], c * k);
            }
            if (v1 != INF)
            {
                ll c = (v1 + k - 1) / k;
                if (!(c & 1))
                    c++; 
                ans[i] = min(ans[i], c * k);
            }
        }else
        {
            if(v2 != INF){
                ans[i] = (v2 + k - 1) / k * k;
            }
            
        }

        if(ans[i] == INF) ans[i] = -1;
        
        // if(!ok){
        //     ans[i] = -1;
        // }
    }

    for(int i = 1;i<=n;i++){
        cout<<ans[i]<<" ";
    }
    cout<<endl;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t = 1;
    cin >> t;
    while (t--)
        solve();
}