#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define endl '\n'
#define pll pair<ll, ll>
#define T tuple<ll, ll, ll>
#define all1(x) x.begin() + 1, x.end()
#define all0(x) x.begin(), x.end()
#define pb(x) push_back(x)
#define fir first
#define sec second

const ll MOD = 10000;
const ll INF = 1e18;

void solve()
{
    ll n,m;
    cin>>n>>m;
    vector<ll> h(n+1,0),lie(n+1,0);
    for (int j = 1; j <= m; j++)
    {
        ll x, y;
        cin >> x >> y;
        h[x]++;
        lie[y]++;
    }
    ll ans = INF;
    for(int i = 1;i<=n;i++){
        ans = min(ans,n - h[i]);
    }
    for(int i = 1;i<=n;i++){
        ans = min(ans,n-lie[i]);
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