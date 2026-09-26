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
    ll n,s,l;
    cin>>n>>s>>l;
    vector<vector<ll>> a(n+1,vector<ll>(n+1,0));
    vector<ll> pre(n+1,0);
    for(int i = 1;i<n;i++){
        ll x;
        cin>>x;
        pre[i] = pre[i-1] + x;
        a[i][i+1] = a[i+1][i] = x;
    }

    ll ans = 1;
    for(int i = 1;i<=s;i++){
        for(int j = s;j<=n;j++){
            ll x = pre[s-1] - pre[i - 1];
            ll y = pre[j-1] - pre[s-1];

            ll t = min(2*x + y,2*y + x);
            if(t <= l){
                ans = max(ans,(ll)j - i + 1);
            }
        }
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