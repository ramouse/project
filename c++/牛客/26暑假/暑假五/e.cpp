#include <bits/stdc++.h>
using ll = long long;
using namespace std;
#define endl '\n'

const ll MOD = 998244353;
const ll INF = 1e18;
const ll N = 1e4;

const ll maxn = 1e7;
vector<ll> prime;
vector<bool> vis(maxn + 1, 0);
vector<ll> o(maxn + 1,0);

ll qpow(ll a, ll b)
{
    ll res = 1;
    while (b)
    {
        if (b & 1)
            res = res * a % MOD;
        a = a * a % MOD;
        b >>= 1;
    }
    res = res % MOD;
    return res;
}

void init()
{
    vis[1] = 1;
    for (ll i = 2; i <= maxn; ++i)
    {
        if (!vis[i])
        {
            prime.emplace_back(i);
            o[i] = 1;
        }
        for (int j = 0; j < prime.size(); ++j)
        {
            ll p = prime[j];

            if (p * i > maxn)
                break;
            vis[p * i] = true;
            o[i * p] = o[i] + 1;
            if (i % p == 0)
            {
                break;
            }
        }
    }
}

void solve()
{
    init();
    ll n, c;
    cin >> n >> c;

    vector<ll> g(n + 1, 0);

    g[1] = 1;
    // g[2] = 1;
    // g[3] = 1;
    // g[4] = 2;

    ll ans = 0;
    vector<ll> h(n+1,0);
    h[1] = c;
    for (int i = 2; i <= n; i++)
    {
        h[i] = h[i-1] * c % MOD;
        g[i] = (o[i] == 1 ? 1 : prime[o[i] - 2]);
    }

    // for(int i = 1;i<=n;i++){
    //     cout<<"i: "<<i<<" "<<g[i]<<endl;
    // }
    // cout<<endl;

    for (int i = 1; i <= n; i++)
    {
        ans = (ans + g[i] * h[i] % MOD) % MOD;
    }
    cout << ans << endl;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    int t = 1;
    // cin>>t;
    while (t--)
        solve();

    return 0;
}