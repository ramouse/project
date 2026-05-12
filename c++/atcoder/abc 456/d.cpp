#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define endl '\n'

const ll MOD = 998244353;
const ll MAXN = 2e5 + 5;

ll qpow(ll a,ll b){
    ll res = 1;
    while(b){
        if(b&1) res = res*a%MOD;
        b/=2;
        a=a*a%MOD;
    }
    return res;
}

void solve()
{
    string s;
    cin>>s;

    ll ans = 0;
    map<char,ll> dp;
    for(auto c : s){
        dp[c] = (dp['a']+dp['b']+dp['c']+1) %MOD;
    }
    for(auto[u,v] : dp){
        ans = (ans+v)%MOD;
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