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
    ll n, m, l, r, temp, last;
    cin >> n >> m;
    vector<vector<ll>> adj(n + 1);
    vector<ll> deg(n + 1, 0),deg1(n+1,0);
    for (ll i = 1; i <= m; i++)
    {
        cin >> l >> r;
        cin >> last;
        adj[0].push_back(last);
        deg[last]++;
        deg1[last]++;
        for (ll i = l; i < r; i++)
        {
            cin >> temp;
            deg[temp]++;
            deg1[temp]++;
            adj[last].push_back(temp);
            last = temp;
        }
    }
    queue<ll> q;
    priority_queue<ll, vector<ll>, greater<ll>> pq;
    ll count = 0;
    ll now = 0;
    ll ans[n + 1];
    for (ll i = 0; i <= n; i++)
    {
        if (deg[i] == 0)
        {
            q.push(i);
            pq.push(i);
        }
    }
    while (!q.empty())
    {
        temp = q.front();
        q.pop();
        count++;
        for (ll v : adj[temp])
        {
            deg[v]--;
            if (deg[v] == 0)
            {
                q.push(v);
            };
        }
    }
    if (count == n + 1)
    {
        while (!pq.empty())
        {
            temp = pq.top();
            pq.pop();
            ans[temp] = now;
            now++;
            for (ll v : adj[temp])
            {
                deg1[v]--;
                if (deg1[v] == 0)
                {
                    pq.push(v);
                };
            }
        }
        cout << ans[1];
        for (ll i = 2; i <= n; i++)
            cout << " " << ans[i];
        cout << endl;
    }
    else
    {
        cout << -1 << endl;
        return;
    }
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