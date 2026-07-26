#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define endl '\n'

const ll N = 1e9;
const ll MOD = 676767677;
const ll INF = 1e18;


void solve()
{
    ll n;
    cin>>n;
    ll ans = 0;
    for(int i = 1;i<=n;i++){
        ll a,b;
        cin>>a>>b;
        string s;
        cin>>s;

        if(s == "keep"){
            ans += b-a;
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
    {
        solve();
    }
    return 0;
}