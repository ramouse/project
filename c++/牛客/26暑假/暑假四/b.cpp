#include <bits/stdc++.h>
using ll = long long;
using namespace std;
#define endl '\n'

const ll MOD = 998244353;
const ll INF = 1e18;
const ll N = 250;

struct Node
{
    ll x1, x2, p, q;
};

void solve()
{
    ll p;
    cin >> p;
    if (p == 2)
    {
        cout << "12 1 71" << '\n';
    }
    else if (p == 3)
    {
        cout << "4 1 13" << '\n';
    }
    else
    {
        ll x, q;
        x = sqrt(p);
        for (;;)
        {
            if (x * x - p <= x)
                x++;
            else
                break;
        }
        q = x * x - p;
        cout << x << " " << x << " " << q << '\n';
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

    return 0;
}