#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using i128 = __int128_t;
#define endl '\n'
#define pll pair<ll,ll>
#define T tuple<ll,ll,ll>
#define all1(x) x.begin() + 1,x.end()
#define all0(x) x.begin(),x.end()
#define pb push_back
#define fir first
#define sec second

const ll MOD = 998244353;
const ll INF = 1e18;

void solve()
{   
    ll n,q;
    cin>>n>>q;
    vector<vector<pll>> adj(n+2);

    for(int i = 1;i<=n;i++){
        ll a;
        cin>>a;
        adj[i].push_back({i%n+1,a});
        adj[i%n+1].push_back({i,a});
    }

    for(int i = 1;i<=n;i++){
        ll b;
        cin>>b;
        adj[i].push_back({n+1,b});
        adj[n+1].push_back({i,b});
    }

    vector<vector<ll>> dist(n+2,vector<ll>(n+2,INF));

    for(int i = 1;i<=n+1;i++){
        priority_queue<pll,vector<pll>,greater<pll>> pq;
        pq.push({0,i});
        dist[i][i] = 0;

        while(!pq.empty()){
            auto [d,u] = pq.top();
            pq.pop();

            for(auto [v,cost] : adj[u]){
                if(u == v) continue;
                if(dist[i][v] > cost + d){
                    dist[i][v] = cost + d;
                    pq.push({dist[i][v],v});
                }
            }

        }
    }

    while(q--){
        ll l,r;
        cin>>l>>r;
        cout<<min(dist[l][r],dist[r][l])<<endl;
    }

}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t = 1;
    // cin >> t;
    while (t--)
        solve();
}