#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define endl '\n'

const ll INF = 1e18;
const ll LOG = 31;
const ll MOD = 998244353;
const ll N = 2e6 + 6;

vector<ll> fact(N + 1), inv(N + 1); // 阶乘和逆元

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

void init()
{
    fact[0] = 1;
    for (int i = 1; i <= N; i++)
    {
        fact[i] = (fact[i - 1] * i) % MOD;
    }
    inv[N] = qpow(fact[N], MOD - 2);
    for (int i = N - 1; i >= 0; i--)
    {
        inv[i] = inv[i + 1] * (i + 1) % MOD;
    }
}

ll C(ll n, ll k)
{ // n中选k
    if (k < 0 || k > n)
        return 0;
    return fact[n] * inv[k] % MOD * inv[n - k] % MOD;
}


void solve()
{ 
    ll n,m,c,a,b;
    cin>>n>>m>>c>>a>>b;

    if(n > m){
        cout<<0<<endl;
        return;
    }
    // if(n == m){
    //     cout << qpow((b - a + MOD) % MOD,m) * qpow(qpow(b,m),MOD-2) % MOD<<endl;
    //     return;
    // }

    if((m - n) % c != 0){
        cout<<0<<endl;
        return;
    }

    ll t = (m - n) / c;
    // if(t > n){
    //     cout<<0<<endl;
    //     return;
    // }

    // if(t == n){
    //     cout<<qpow((a),m) * qpow(qpow(b,m),MOD-2) % MOD<<endl;
    //     return;
    // }

    ll ans = C(m,t) * qpow((b - a + MOD) % MOD,(m - t + MOD) % MOD) % MOD * qpow(qpow(b,(m-t + MOD) % MOD),MOD-2) % MOD;
    ans = ans * qpow(a,t) % MOD * qpow(qpow(b,t),MOD-2) % MOD * n % MOD * qpow(m,MOD-2) % MOD;
    cout<<ans<<endl;

}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t = 1;
    init();
    cin>>t;
    while (t--)
        solve();
    return 0;
}