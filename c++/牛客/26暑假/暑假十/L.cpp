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
    ll m,r,c;
    cin>>m>>r>>c;

    // if(c <= m){
    //     cout<<1.000000000000<<endl;
    //     return;
    // }

    // if (r >= c)
    // {
    //     cout << fixed << setprecision(12) << (double)(m) / c << endl;
    //     return;
    // }

    // // if(c <= 2*m + r){
    // //     cout<<fixed<<setprecision(12)<<(double)(2*m)/(2*m+r)<<endl;
    // //     return;
    // // }

    // ll sh = c/(m+r);
    // cout<<fixed<<setprecision(12)<<(double)((sh + 1) * m)/max((sh + 1)*m + (sh) * r,c)<<endl;

    cout<<fixed<<setprecision(12);

    double ans = 0.0;

    for(int i = 0;i<=2*c;i++){

        ans = max(ans,(double)(i * m + m)/max(c,i*(m+r) + m));
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