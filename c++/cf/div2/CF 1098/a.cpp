#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define endl '\n'

void solve()
{
    ll n;
    cin>>n;
    ll ans = 0;
    ll o = 0,t = 0;
    for(int i = 1;i<=n;i++){
        ll p;
        cin>>p;
        if(p == 0) ans++;
        if(p == 1) o++;
        if(p == 2) t++;
    }
    ll p = min(o,t);
    ans+=p;
    o-=p;
    t-=p;

    ans+=o/3;
    ans+=t/3;
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