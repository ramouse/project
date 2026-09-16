#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using i128 = __int128_t;
#define endl '\n'
#define pll pair<ll, ll>
#define T tuple<ll, ll, ll>
#define all1(x) x.begin() + 1, x.end()
#define all0(x) x.begin(), x.end()
#define pb push_back
#define fir first
#define sec second

const ll MOD = 998244353;
const ll INF = 1e18;

void solve()
{
    ll n,m;
    cin>>n>>m;
    vector<ll> deg(n+1,0);
    vector<vector<ll>> adj(n+1);

    for(int i = 1;i<=m;i++){
        ll l,r;
        cin>>l>>r;
        ll u = 0;
        cin>>u;
        ll v = 0;
        for(int j = l;j<r;j++){
            cin>>v;
            adj[u].push_back(v);
            deg[v]++;
            u = v;
        }   
    }


    ll tot = 1;
    vector<ll> ans(n+1,0);
    vector<int> vis(n+1,0);
    priority_queue<ll,vector<ll>,greater<ll>> pq;
    for(int i = 1;i<=n;i++){
        if(deg[i] == 0){
            // cout<<i<<" ";
            pq.push(i);
        }
    }
    // cout<<endl;


    while(!pq.empty()){
        ll u = pq.top();
        pq.pop();


        ans[u] = tot++;
        vis[u] = 1;
        // cout<<u<<" "<<ans[u]<<endl;
        for(ll v : adj[u]){
            deg[v]--;

            if(deg[v] == 0) pq.push(v);
        }
    }

    if(tot != n+1){
        cout<<-1<<endl;
        return;
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