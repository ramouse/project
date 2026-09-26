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
    ll n;
    cin>>n;
    vector<ll> a(n+1,0);
    for(int i = 1;i<=n;i++){
        cin>>a[i];
    }

    ll c_pre = 0,c_suf = INF;
    vector<ll> pre(n+1,0),suf(n+3,INF);
    for(int i = n;i>=1;i--){
        suf[i] = min(suf[i+1],a[i]);
    }
    for(int i = 1;i<=n;i++){
        pre[i] = max(pre[i-1],a[i]);
    }

    ll ans = 0;

    // for(int i = 1;i<=n;i++){
    //     cout<<pre[i]<<" ";
    // }
    // cout<<endl;
    // for(int i = 1;i<=n;i++){
    //     cout<<suf[i]<<" ";
    // }
    // cout<<endl;

    ll r = 1;
    for(ll l = 1;l<=n;l++){
        while(r <= n && (c_pre <= pre[r] || c_suf >= suf[r])){
            r++;
            c_pre = max(c_pre,a[r]);
            c_suf = min(c_suf,suf[r]);
        }
        ans += r - l + 1;
    }

    cout<<ans<<endl;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t = 1;
    // cin >> t; 
    while (t--){
        solve();
    }
        
}