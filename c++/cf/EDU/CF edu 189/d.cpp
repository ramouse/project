#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define endl '\n'

const ll MOD = 998244353;
const ll MAXN = 2e5 + 5;
const ll INF = 1e18;

void solve()
{
    ll n,x;
    cin>>n>>x;

    vector<ll> pre(n+1,0);
    for(int i = 1;i<=n;i++){
        pre[i] = pre[i-1]^i;
    }

    
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t = 1;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}