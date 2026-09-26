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

void solve()
{
    ll n,m,k;
    cin>>n>>m>>k;
    vector<ll> a(n+1,0),b(m+1,0);

    ll x,y;
    cin>>x>>y;
    vector<ll> pre(n+1,0),ppre(m+1,0);
    for(int i = 1;i<=n;i++){
        cin>>a[i];
    }
    for(int i = 1;i<=m;i++){
        cin>>b[i];
    }
    sort(all1(a));
    sort(all1(b));

    for(int i = 1;i<=n;i++){
        pre[i] = pre[i-1] + a[i];
    }
    // for(int i = 1;i<=m;i++){
    //     ppre[i] = ppre[i-1] + b[i];
    // }
    // cout<<ppre[14]<<" "<<y * k<<endl;


    ll ans = 0;

    ll idx = upper_bound(all1(pre), x + y * k) - pre.begin() - 1;
    ans = max(ans, idx);

    for(int i = 1;i<=m;i++){
        ll t = (b[i] + k - 1)/k;
        if(y < t) break;
        ll sh = t * k - b[i];
        y-=t;
        x+=sh;
        ll idx = upper_bound(all1(pre),x + y * k) - pre.begin() - 1;
        ans = max(ans, idx + i);
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