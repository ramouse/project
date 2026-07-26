#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define endl '\n'

const ll INF = 1e18;

void solve()
{   
    ll n;
    cin>>n;
    vector<ll> a(n+1,0);
    ll ans = 0;
    for(int i = 0;i<n;i++){
        cin>>a[i];
        ans += (n-i-1) * (-1*a[i]) + (i) * a[i];
    }
    cout<<ans<<endl;
}

int main()
{
    int t = 1;
    // cin >> t;
    while (t--)
        solve();
    return 0;
}