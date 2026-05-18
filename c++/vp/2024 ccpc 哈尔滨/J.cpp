#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve()
{
    ll n,m;
    cin>>n>>m;

    vector<ll> a(n+1,0),pre(n+1,0);
    ll sum = 0;
    for(int i = 1;i<=n;i++){
        cin>>a[i];
        pre[i] = pre[i-1] + a[i];
        sum+=a[i];
    }
    map<ll,ll> mp;
    vector<pair<ll,ll>> vec;
    for(int i = 1;i<=m;i++){
        ll x,j;
        cin>>x>>j;
        vec.push_back({x,j});
    }
    sort(vec.begin(),vec.end());

    ll ans = 0;
    for(int i = 0;i<vec.size();i++){
        ll s = vec[i].first;
        ll index = vec[i].second;
        

    }

}
int main()
{
    ll t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}