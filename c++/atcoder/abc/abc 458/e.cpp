#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define endl '\n'
#define T tuple<ll, ll, ll>
#define pll pair<ll, ll>

const ll MOD = 998244353;
const ll INF = 1e18;
const ll N = 3e6+1;

vector<ll> inv(N+1,0),fact(N+1,0);

ll qpow(ll a, ll b){
    ll res = 1;
    while(b){
        if(b&1) res = res * a % MOD;
        a = a * a % MOD;
        b>>=1;
    }
    return res;
}

void init(){
    fact[0] = 1;
    for(int i = 1;i<=N;i++){
        fact[i] = (fact[i-1] * i) % MOD;
    }
    inv[N] = qpow(fact[N],MOD-2);
    for(int i = N-1;i>=0;i--){
        inv[i] = inv[i+1] * (i + 1) % MOD;
    }
}

ll C(ll n,ll k){
    if(k<0 || k>n) return 0;
    return fact[n] * inv[k] % MOD * inv[n-k] % MOD;
}

void solve()
{
    ll x1,x2,x3;
    cin>>x1>>x2>>x3;
    init();

    ll ans = 0;
    
    //1..3..1
    for(int i = 2;i<=x1;i++){
        ans = (ans + C(x1-1,i-1) * C(x3-1,i-2) % MOD * C(x1 + x3 + x2 - (2 * i -2),x1 + x3) % MOD) % MOD;
    }
    //3..1..3
    for(int i = 2;i<=x3;i++){
        ans = (ans + C(x3-1,i-1) * C(x1 - 1,i - 2) % MOD * C(x1 + x3 + x2 - (2 * i - 2),x1 + x3) % MOD) % MOD;
    }

    //1..3..1..3 && 3..1..3..1
    for(int i = 1;i<=min(x1,x3);i++){
        ans = (ans + 2 * (C(x1-1,i-1) * C(x3 - 1,i-1) % MOD * C(x1 + x3 + x2 - (2*i - 1),x1 + x3) % MOD) % MOD) % MOD;
    }
    

    cout<<ans<<endl;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t = 1;
    // cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}