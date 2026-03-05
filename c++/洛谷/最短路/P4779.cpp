#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define endl '\n'

const ll INF = 1e18;
struct node
{
    ll to;
    ll w;
};

int main()
{
    ll n, m, s;
    cin >> n >> m >> s;
    vector<node> adj[n + 1];
    for (int i = 1; i <= m; i++)
    {
        ll u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
    }

    vector<ll> dist(n + 1, INF);
    priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>> pq;
    pq.push({0, s});
    dist[s] = 0;

    while (!pq.empty())
    {
        auto [d, u] = pq.top();
        pq.pop();

        if (d > dist[u])
            continue;
        for (auto &e : adj[u])
        {
            ll v = e.to;
            ll w = e.w;
            if (dist[u] + w < dist[v])
            {
                dist[v] = dist[u] + w;
                pq.push({dist[v], v});
            }
        }
    }

    for (int i = 1; i <= n; i++)
    {
        if (dist[i] != INF)
        {
            cout << dist[i] << " ";
        }
    }
    return 0;
}