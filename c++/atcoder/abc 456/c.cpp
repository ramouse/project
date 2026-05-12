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

    ll ans = s.length();

    vector<ll> vec(s.length()+1,0);
    ll len = 1;
    for(int i = 1;i<s.length();i++){
        if(s[i] == s[i-1]){
            if(len!=1){
                ans = (ans + len*(len+1)%MOD*qpow(2,MOD-2)%MOD)%MOD;
                ans = (ans-len+MOD)%MOD;
            }
            len=1;
        }else len++;

    }
    if (len != 1)
    {
        ans = (ans + len * (len + 1) % MOD * qpow(2, MOD - 2) % MOD) % MOD;
        ans = (ans - len + MOD) % MOD;
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