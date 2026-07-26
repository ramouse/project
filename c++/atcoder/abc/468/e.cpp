#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define endl '\n'

const ll N = 1e6+5;
const ll MOD = 998244353;

ll qpow(ll a, ll b)
{
    ll res = 1;
    while (b != 0)
    {
        if (b % 2 == 1)
            res = res * a % MOD;
        a = a * a % MOD;
        b /= 2;
    }
    return res;
}

void solve(){
    ll n;
    cin>>n;
    vector<ll> a(n+1,0),pre(n+1,0),ppre(n+1,0);
    ll ans = 0;
    for(int i = 1;i<=n;i++){
        cin>>a[i];
        pre[i] = (pre[i-1] + qpow(i,MOD-2)) % MOD;
        ppre[i] = (ppre[i-1] + pre[i]) % MOD;
    }
    
    for(int i = 1;i<=n;i++){
        ll op1 = ((ppre[n] - ppre[n - i] + MOD) % MOD - ppre[i-1] + MOD) % MOD;
        ans = (ans + a[i] * op1 % MOD) % MOD;
    }

    cout<<ans<<endl;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t = 1;
    // cout<<'j'-'0'-'0'<<endl;
    // cin>>t;
    while(t--){
        solve();
    }
    return 0;
}