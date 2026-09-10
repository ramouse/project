#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using i128 = __int128_t;
#define endl '\n'
#define pll pair<ll, ll>
#define T tuple<ll, ll, ll>
#define all1(x) x.begin() + 1, x.end()
#define all0(x) x.begin(), x.end()
#define pb push_back
#define fir first
#define sec second

const ll MOD = 998244353;
const ll INF = 1e18;


ll qpow(ll a,ll b){
    ll res = 1;
    while(b){
        if(b & 1) res = res * a % MOD;
        a = a * a % MOD;
        b >>=1;
    }
    return res;
}


void solve()
{
    ll x,y;
    cin>>x>>y;
    ll a0,a1,b;
    cin>>a0>>a1>>b;


    ll p0 = a0 * qpow(b,MOD-2);
    ll p1 = a1 * qpow(b,MOD-2);

    if(x >= y){
        ll t = x- y;
        cout<<0<<endl;
    }else{
        ll t = y - x;
        t++;
        // cout<<qpow(p0 + p1,MOD-2)<<endl;
        ll ans = qpow(p0 * qpow((p0 + p1) % MOD,MOD-2) % MOD,t);
        cout<<ans<<endl;
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t = 1;
    cin >> t;
    while (t--)
        solve();
}