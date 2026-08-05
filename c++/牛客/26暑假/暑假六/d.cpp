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
        if(u == v){
            can[u] = 1;
            continue;
        }

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<vector<ll>> val(n+1);
    vector<int> vis(n+1,0);

    queue<tuple<ll,ll,ll>> q;
    q.push({1,0,0});
    vis[1]++;
    if(can[1]){
        q.push({1,1,0});
    }
    while(!q.empty()){
        auto [u,d,fa] = q.front();
        q.pop();

        for(ll v : adj[u]){
            if(v != fa){
                // cout<<v<<" "<<u<<endl;
                if(vis[v] < 5){
                    vis[v]++;
                    val[v].push_back(d+1);
                    q.push({v,d+1,u});
                    if(can[v]){
                        q.push({v,d+2,u});
                        val[v].push_back(d+2);
                    }
                }
            }
        }
    }

    // for(int i = 2;i<=n;i++){
    //     for (ll u : val[i])
    //     {
    //         cout << u << " ";
    //     }
    //     cout << endl;
    // }
   

    vector<ll> ans(n+1,INF);
    ans[1] = 0;
    for(int i = 2;i<=n;i++){
        bool ok = false;
        sort(val[i].begin(),val[i].end());
        val[i].erase(unique(val[i].begin(),val[i].end()),val[i].end());
        for(ll u : val[i]){
            if(!((u ^ k) & 1)){
                ok = true;
                ans[i] = min(ans[i],lcm(u,k));
            }
        }
        if(!ok){
            ans[i] = -1;
        }
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