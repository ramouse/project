#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define endl '\n'

const ll N = 1e9;
const ll MOD = 676767677;

void solve()
{
    ll n,m;
    cin>>n>>m;
    vector<ll> vec(m+1,0);
    for(int i = 1;i<=n;i++){
        ll c,s;
        cin>>c>>s;
        vec[c] = max(vec[c],s);
    }

    for(int i = 1;i<=m;i++){
        if(vec[i] == 0) cout<<-1<<" ";
        else cout<<vec[i]<<" ";
    }
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