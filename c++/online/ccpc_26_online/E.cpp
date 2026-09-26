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
    vector<vector<ll>> vec(4,vector<ll>(n+1,0));

    for(int i = 1;i<=3;i++){
        for(int j = 1;j<=n;j++){
            cin>>vec[i][j];
        }
    }

    vector<ll> v1,v2,v3;

    ll ans = 0;
    for(int i = 1;i<=n;i++){
        v1.pb(vec[1][i]);
        v2.pb(vec[2][i]);
        v3.pb(vec[3][i]);
        sort(all0(v1));
        sort(all0(v2));
        sort(all0(v3));
        if(v1 == v2 || v1 == v3 || v2 == v3){
            ans++;
        }
    }

    cout<<ans<<endl;

}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t = 1;
    cin >> t;
    while (t--)
        solve();
}