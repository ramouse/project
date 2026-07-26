#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define endl '\n'

const ll N = 1e9;
const ll MOD = 676767677;

void solve()
{
    ll n;
    cin>>n;
    bool ok = true;
    for(int i = 1;i<=n;i++){
        ll x;
        cin>>x;
        if(x >= 0 ) ok = false;
    }

    if(ok) cout<<"Yes"<<endl;
    else cout<<"No"<<endl;
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