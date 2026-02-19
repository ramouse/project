#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define endl '\n'

const int MOD = 998244353;

ll qpow(ll a, ll b)
{
    ll res = 1;
    while (b != 0)
    {
        if (b % 2 == 1)
            res  = res * a % MOD;
        a  = a * a  % MOD;
        b /= 2;
    }
    return res;
}

void solve(){
    ll n,m,x,y;
    cin>>n>>m>>x>>y;

    ll ans = 1;
    ll k = n+m-x-y;
    ans = qpow(2,k);

    if(x == 0) ans = (ans - 1 + MOD)%MOD;
    cout<<ans<<endl;
}

int main(){
    int t;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}