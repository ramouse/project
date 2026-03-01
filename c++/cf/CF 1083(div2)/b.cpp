#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define endl '\n'

void solve()
{
    ll n;
    cin>>n;
    
    ll ans = 1;
    ll t = n;
    for(int i = 2;i*i<=n;i++){
        if(t%i == 0) ans*=i;
        while(t%i==0) t/=i;
    }

    if(t>1) ans*=t;
    cout<<ans<<endl;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}