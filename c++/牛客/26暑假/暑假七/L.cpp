#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define endl '\n'
#define pll pair<ll, ll>
#define T tuple<ll, ll, ll>
#define all1(x) x.begin() + 1, x.end()
#define all0(x) x.begin(), x.end()
#define pb(x) push_back(x)

const ll MOD = 10000;
const ll INF = 1e18;

void solve()
{
    ll n;
    cin>>n;
    ll ans = 0;
    for(int b = 1;b * b<= n;b++){
        ll cur = 0;
        // for(int i = 0;i<b;i++){
        //         cur++;
        //     if(i==n%(b*(b+1))-b*b){ans+=cur;cout<<i<<"#"<<cur<<endl;}
        // }
        ans += max(0LL, n % (b * (b + 1)) - b * b + 1);
        ll t = b*(b + 1);
        ans += n/t *b;
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
        solve();
}