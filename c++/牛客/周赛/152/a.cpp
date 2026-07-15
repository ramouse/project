#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define endl '\n'

const ll INF = 1e18;
const ll MAXN = 2e5 * 32;
const ll MOD = 1e9+7;

void solve()
{   
    ll x;
    cin>>x;
    ll len = 0;
    ll t = x;
    ll ans = 1;
    while(t){
        t/=10;
        len++;
        ans*=10;
    }
    cout<<ans * x + x<<endl;
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