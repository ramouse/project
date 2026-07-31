#include <bits/stdc++.h>
using ll = long long;
using namespace std;
#define endl '\n'

const ll MOD = 998244353;
const ll INF = 1e18;
const ll N = 72;

struct Node
{
    ll x1, x2, p, q;
};

void solve()
{
    // ll p;
    // cin>>p;

    vector<Node> vec;
    vector<bool> vis(N + 1, 0);
    for (int p = 2; p <= N; p++)
    {
        for (int q = 1; q <= N; q++)
        {
            for (int x1 = 1; x1 < q; x1++)
            {
                for (int x2 = 1; x2 < p; x2++)
                {
                    if ((x1 * x1 % q) == p % q && (x2 * x2 % p) == q % p)
                    {
                        vec.push_back({x1, x2, p, q});
                        vis[p] = 1;
                    }
                }
            }
        }
    }

    for (auto [a, b, c, d] : vec)
    {
        // cout << a << " " << b << " " << c << " " << d << " " << gcd(c, b) << " " << gcd(a, c) << " " << gcd(gcd(c, b),gcd(a, c))<<" ";
        // cout<<gcd(a,b)<<" "<<gcd(c,d)<<" "<<gcd(gcd(a,b),gcd(c,d))<<endl;
        // cout << lcm(a, b) << " " << lcm(c, d) << " " << a * a << " " << b * b << " " << c << " " << d << endl;
        cout << a << " " << b << " " << c << " " << d << " " << endl;
    }

    // for(int i = 2;i<=N;i++){
    //     if(!vis[i]) cout<<i<<endl;
    // }
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