#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define endl '\n'
#define T tuple<ll, ll, ll>
#define pll pair<ll, ll>

const ll MOD = 998244353;
const ll INF = 1e18;
const ll LOG = 30;

void solve()
{
    string s;
    cin>>s;
    s = " "+s;
    ll ans = 0;
    ll cur = 0;

    for(int i = 1;i<s.length();i++){
        if(s[i] == 'C'){
            ans += min((ll)i-1,(ll)s.length() - 1 - i) + 1;
            // cout<<ans<<" ";
        }
    }
    cout<<ans<<endl;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t = 1;
    // cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}