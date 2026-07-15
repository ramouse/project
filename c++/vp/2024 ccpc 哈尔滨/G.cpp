#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define endl '\n'

void solve()
{
    ll n, m, k;
    cin >> n >> m >> k;
    vector<bool> val(n + 1, 0);
    for (int i = 1; i <= k; i++)
    {
        ll x;
        cin >> x;
        val[x] = 1;
    }

    vector<vector<ll>> adj(n + 1);
    for (int i = 1; i <= m; i++)
    {
        ll u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<bool> vis(n + 1, 0);
    ll index = -1;
    for (int i = 1; i <= n; i++)
    {
        if (!val[i])
        {
            index = i;
            break;
        }
    }

    if (index == -1)
    {
        cout << "No" << endl;
        return;
    }

    vector<vector<ll>> ans;
    queue<ll> q;
    q.push(index);
    vis[index] = 1;
    ll tot = 1;
    while (!q.empty())
    {
        ll u = q.front();
        q.pop();

        vector<ll> step;
        for (ll v : adj[u])
        {
            if (!vis[v] && !val[u])
            {
                q.push(v);
                vis[v] = 1;
                step.push_back(v);
                tot++;
            }
        }

        if (!step.empty())
        {
            vector<ll> t;
            t.push_back(u);
            t.push_back(step.size());
            for (ll x : step)
            {
                t.push_back(x);
            }
            ans.push_back(t);
        }
    }

    // cout<<tot<<endl;
    if (tot == n)
    {
        cout << "Yes" << endl;
        cout << ans.size() << endl;
        // cout<<index<<" ";
        for (auto f : ans)
        {
            for (auto s : f)
            {
                cout << s << " ";
            }
            cout << endl;
        }
    }
    else
    {
        cout << "No" << endl;
    }
}

int main()
{
    int t = 1;
    // cin>>t;
    while (t--)
        solve();
    return 0;
}