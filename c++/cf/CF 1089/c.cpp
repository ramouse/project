#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define endl '\n'

const ll MOD = 998244353;

void solve()
{
    ll n;
    cin>>n;
    vector<ll> a(n+1,0),b(n+1,0);
    ll ans = 0;
    for(int i = 1;i<=n;i++){
        cin>>a[i];
    }
    for (int i = 1; i <= n; i++)
    {
        cin >> b[i];
    }

    if(a[1]>gcd(a[1],a[2])){
        a[1] = gcd(a[1],a[2]);
        ans++;
    }
    if(a[n]>gcd(a[n],a[n-1])){
        a[n] = gcd(a[n],a[n-1]);
        ans++;
    }
    for(int i = 2;i<n;i++){
        ll u = gcd(a[i],a[i+1]);
        ll v = gcd(a[i],a[i-1]);
        ll t = lcm(u,v);
        if(t<a[i]){
            a[i] = t;
            ans++;
        }
    }
    cout<<ans<<endl;
}   

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t = 1;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}