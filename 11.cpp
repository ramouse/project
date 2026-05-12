#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define endl '\n'
#define T tuple<ll,ll,ll>
#define pll pair<ll,ll>

const ll MOD = 998244353;
const ll INF = 1e18;
const ll LOG = 30;

void solve()
{
    ll n,k;
    cin>>n>>k;
    vector<ll> a(n+1);
    for(int i = 1;i<=n;i++){
        cin>>a[i];
    }

    auto check = [&](ll x){
        ll cur = 0;
        for(int i = 1;i<=n;i++){
            if(a[i]<x){
                ll t = (x-a[i]+i-1)/i;
                cur += t;
            }
            if(cur>k){
                return false;
            }
        }
        return true;
    };

    ll l = 1,r = 2*INF;
    ll ans = 1;
    while(l<=r){
        ll mid = (l+r)>>1;
        if(check(mid)){
            l = mid+1;
            ans = mid;
        }else{
            r = mid -1;
        }
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