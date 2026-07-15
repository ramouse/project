#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define endl '\n'

const ll INF = 1e18;
const ll MAXN = 2e5 * 32;
const ll MOD = 1e9+7;

void solve()
{   
    ll n;
    cin>>n;
    vector<vector<ll>> adj(n+1);

    for(int i = 1;i<=n;i++){
        ll u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    ll ans = 0;
    for(int i = 1;i<=n;i++){
        if(adj[i].size() == 1){
            cout<<i<<" "<<adj[i][0]<<endl;
            return;
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