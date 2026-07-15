#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define endl '\n'

const ll INF = 1e18;
const ll MAXN = 3e5+5;
const ll MOD = 998244353;

void solve()
{   
    ll n;
    cin>>n;
    vector<ll> a(n+1,0);
    ll sum = 0;
    for(int i = 1;i<=n;i++){
        cin>>a[i];
        sum += a[i];
    }
    ll t = sum/n;
    ll ans = 0;
    for(int i = 1;i<=n;i++){
        if(a[i]>t) ans++;
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
    {
        solve();
    }
    return 0;
}