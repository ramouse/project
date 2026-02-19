#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n;
    cin >> n;

    vector<vector<int>> adj(n + 1);
    for (int i = 0; i < n - 1; ++i)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<int> depth_cnt(n + 1, 0);
    int max_star_size = 0;

    queue<pair<int, int>> q;
    q.push({1, 0});

    vector<bool> visited(n + 1, false);
    visited[1] = true;

    int max_width = 0;

    while (!q.empty())
    {
        auto [u, d] = q.front();
        q.pop();

        depth_cnt[d]++;
        max_width = max(max_width, depth_cnt[d]);

        int children = 0;
        for (int v : adj[u])
        {
            if (!visited[v])
            {
                visited[v] = true;
                q.push({v, d + 1});
                children++;
            }
        }

        max_star_size = max(max_star_size, children + 1);
    }

    cout << max(max_width, max_star_size) << endl;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    if (cin >> t)
    {
        while (t--)
        {
            solve();
        }
    }
    return 0;
}