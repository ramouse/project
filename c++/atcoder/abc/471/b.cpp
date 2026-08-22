#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using i128 = __int128_t;
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
    ll n;
    cin>>n;
    map<string,ll> vec;
    ll ans = 0;
    for(int i = 1;i<=n;i++){
        string s;
        cin>>s;
        transform(all0(s),s.begin(),::tolower);
        vec[s]++;
        ans = max(ans,vec[s]);
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