#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define endl '\n'
#define pll pair<ll,ll>
#define T tuple<ll,ll,int>

// int dx[] = {-2,-1,1,2,2,1,-1,-2};
// int dy[] = {1,2,2,1,-1,-2,-2,-1};


const ll MOD = 998244353;


void solve()
{
    ll n,h;
    cin>>n>>h;
    vector<ll> a(n+1,0);
    for(int i = 1;i<=n;i++){
        cin>>a[i];
    }

    vector<ll> v(n+1,0);
    for(int i = 1;i<=n;i++){
        ll cur = a[i];
        v[i] = h - cur;
        for(int j = i+1;j<=n;j++){
            cur = max(a[j],cur);
            v[i] += h - cur;
        }
        cur = a[i];
        for(int j = i-1;j;--j){
            cur = max(a[j],cur);
            v[i] += h - cur;
        }
    }

    ll ans = 0;
    for(int i = 1;i<=n;i++){
        ll idx = i;
        ll cur = a[i];
        for(int j = i;j<=n;j++){
            if(a[j]>cur){
                idx = j;
                cur = a[j];
            }
            ans = max(ans,v[i]+v[j]-v[idx]);
        }
    }
    cout<<ans<<endl;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t = 1;
    cin >> t;

    while (t--)
    {
        solve();
    }
    return 0;
}