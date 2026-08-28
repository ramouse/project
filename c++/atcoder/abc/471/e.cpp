#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using i128 = __int128_t;
#define endl '\n'
#define pll pair<ll, ll>
#define T tuple<ll, ll, ll>
#define all1(x) x.begin() + 1, x.end()
#define all0(x) x.begin(), x.end()
#define pb(x) push_back(x)
#define fir first
#define sec second

const ll MOD = 998244353;
const ll INF = 1e18;
const ll N = 2e5+5;

vector<ll> inv(N+1,0),fact(N+1,0);

ll qpow(ll a,ll b){
    ll res = 1;
    while(b){
        if(b&1) res = res * a % MOD;
        a = a * a % MOD;
        b/=2;
    }
    return res;
}

void init(){
    fact[0] = 1;
    for(int i = 1;i<=N;i++){
        fact[i] = fact[i-1] * i % MOD;
    }
    inv[N] = qpow(fact[N],MOD-2);
    for(int i = N-1;i>=0;i--){
        inv[i] = inv[i+1] * (i+1) % MOD;
    }
}

ll C(ll n,ll k){
    if(k < 0 || k > n) return 0;
    return fact[n] * inv[k] % MOD * inv[n-k] % MOD;
}

void solve()
{
    ll n,k;
    cin>>n>>k;
    
    vector<ll> a(n+1,0),pre(n+1,0),ppre(n+1,0);
    for(int i = 1;i<=n;i++){
        cin>>a[i];
        pre[i] = (pre[i-1] + a[i]) % MOD;
        ppre[i] = (ppre[i-1] + (a[i] * a[i]) % MOD) % MOD;
    }

    // ans=C(n - 1, k - 1) * ∑Ai^2 ​+ C(n - 2, k - 2) * [(∑Ai​)^2 − ∑Ai^2​]
    ll ans = 0;
    ll part2 = (pre[n] * pre[n] % MOD - ppre[n] + MOD) % MOD;

    ans = (ans + (C(n - 1, k - 1) * ppre[n] % MOD + C(n - 2, k - 2) * part2 % MOD) % MOD) % MOD;

    cout<<ans<<endl;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    init();
    int t = 1;
    // cin >> t;
    while (t--)
        solve();
}