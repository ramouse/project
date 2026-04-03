#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define endl '\n'

const ll MOD = 998244353;

void solve()
{
    ll n;
    cin>>n;
    vector<ll> a(n+1,0);
    ll ans = 0;
    for(int i = 1;i<=n;i++){
        cin>>a[i];
        if(a[i]<=i){
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