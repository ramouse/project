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
    ll n;
    cin>>n;
    vector<ll> a(n+1,0),pre(n+1,0);
    for(int i = 1;i<=n;i++){
        cin>>a[i];
        pre[i] = pre[i-1] + a[i];
    }

    ll ans = INF;
    for(int i = 1;i<=n-1;i++){
        ans = min(ans,abs(pre[n] - pre[i] - pre[i]));
    }

    cout<<ans<<endl;
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