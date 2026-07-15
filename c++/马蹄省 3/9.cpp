#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define endl '\n'

const ll INF = 1e18;
const ll MAXN = 3e5+5;
const ll MOD = 1e9 + 7;

void solve()
{   
    ll n,q;
    cin>>n>>q;

    vector<ll> vec(n+1,0),pre(n+1,0);

    for(int i = 1;i<=n;i++){
        vec[i] = (n/i) % i;
        pre[i] = (pre[i-1] + vec[i]) % MOD;
    }

    while(q--){
        ll l,r;
        cin>>l>>r;

        ll ans = (pre[r] - pre[l-1] + MOD) % MOD;
        cout<<ans<<endl;
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