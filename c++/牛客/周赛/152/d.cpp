#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define endl '\n'

const ll INF = 1e18;
const ll MAXN = 2e5 * 32;
const ll MOD = 1e9+7;

void solve()
{       
    ll k;
    cin>>k;
    ll a,b,c,d;
    cin>>a>>b>>c>>d;

    ll d1 = abs(c-a);
    ll d2 = abs(d-b);

    if(d2 == 0){
        double ans = d1 * k + k * k;
        cout<<fixed<<setprecision(8)<<ans;
        return;
    }

    if(d1 == 0){
        double ans = d2 * k + k * k;
        cout<<fixed<<setprecision(8)<<ans;
        return;
    }


    // double ans = sqrt(d1 * d1 + d2 * d2) * sqrt(k * k * 2) + k * k;
    double ans = k * k + k * (d1 + d2);
    cout<<fixed<<setprecision(8)<<ans;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t = 1;
    // cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}