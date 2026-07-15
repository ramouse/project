#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define endl '\n'

const ll N = 1e9;
const ll MOD = 676767677;

void solve()
{
    ll n;
    cin>>n;

    // vector<pair<pair<ll,ll>,ll>> vec;
    // for(int i = 1;i<=n;i++){
    //     for(int j = 1;j<=n;j++){
    //         for(int k = 1;k<=n;k++){
    //             if(gcd(lcm(i,j),lcm(j,k)) == gcd(i,k)){
    //                 vec.push_back({{i,j},k});
    //             }
    //         }
    //     }
    // }
    // cout<<vec.size()<<endl;
    // for(auto f : vec){
    //     cout<<f.first.first<<" "<<f.first.second<<" "<<f.second<<endl;
    // }

    ll ans = 0;

    for(int i = 1;i<=n;i++){
        ans += (ll)(n/i) * (ll)(n/i);
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