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
const ll N = 5e5+1;

ll tire[N][26] = {0};
ll cnt[N] = {0};

void solve()
{
    ll n;
    cin>>n;

    ll tot = 0;

    vector<ll> f(n+1,0);
    ll ans = 0;
    for(int i = 1;i<=n;i++){
        string s;
        cin>>s;

        ll p = 0;
        ll d = 0;

        ans += i;

        for(char c : s){
            ll u = c - 'a';
            if(!tire[p][u]){
                tire[p][u] = ++tot;
            }
            p = tire[p][u];
            cnt[p]++;
            d++;


            if(d > f[cnt[p]]){
                ans -= f[cnt[p]] ^ cnt[p];
                f[cnt[p]] = d;
                ans += f[cnt[p]] ^ cnt[p];
            }

        }

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
        solve();
}