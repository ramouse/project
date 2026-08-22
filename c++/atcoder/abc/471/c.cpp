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

const ll MOD = 10000;
const ll INF = 1e18;

void solve()
{
    ll n;
    cin>>n;
    set<ll> a;
    set<ll, greater<ll>> b;
    for(int i = 1;i<=n;i++){
        ll x;
        cin>>x;
        a.insert(x);
        b.insert(x);
    }

    ll ans = 0;
    ll pos = 0;
    
    
    for(int i = 1;i<=n;i++){
        ll ma = (a.upper_bound(pos) != a.end() ? *a.upper_bound(pos) : INF);
        ll mi = (b.upper_bound(pos) != b.end() ? *b.upper_bound(pos) : INF);

        if(ma == INF){
            ans += abs(pos - mi);
            pos = mi;
            a.erase(mi);
            b.erase(mi);
            continue;
        }

        if(mi == INF){
            ans += abs(pos - ma);
            pos = ma;
            a.erase(ma);
            b.erase(ma);
            continue;
        }

        if(abs(ma - pos) == abs(mi - pos)){
            ans += abs(pos - mi);
            pos = mi;
            a.erase(mi);
            b.erase(mi);
            continue;
        }else{
            if(abs(mi - pos) < abs(ma - pos)){
                ans += abs(pos - mi);
                pos = mi;
                a.erase(mi);
                b.erase(mi);
            }else{
                ans += abs(pos - ma);
                pos = ma;
                a.erase(ma);
                b.erase(ma);
            }
        }
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
        solve();
}