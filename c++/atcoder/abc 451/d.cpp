#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define endl '\n'

const ll MOD = 998244353;
const ll MAXN = 2e5 + 5;

void solve()
{
    ll n;
    cin >> n;

    vector<ll> vec;
    queue<ll> q;
    vector<ll> ans;
    ll a = 1;
    while (1)
    {
        vec.push_back(a);
        q.push(a);
        a <<= 1;
        if (a >= 1e9)
            break;
    }

    while (!q.empty())
    {
        ll u = q.front();
        q.pop();
        ans.push_back(u);
        for (ll v : vec)
        {
            string s = to_string(u) + to_string(v);
            if (s.length() >= 10)
                continue;
            q.push(stoll(s));
        }
    }

    sort(ans.begin(), ans.end());
    ans.erase(unique(ans.begin(), ans.end()), ans.end());
    cout << ans[n - 1] << endl;
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