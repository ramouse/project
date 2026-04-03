#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define endl '\n'
#define pll pair<ll, ll>
#define T tuple<ll, ll, ll>

// ll dx[] = {-2,-1,1,2,2,1,-1,-2};
// ll dy[] = {1,2,2,1,-1,-2,-2,-1};

const ll MOD = 998244353;
const ll INF = 1e18;

struct Node
{
    ll to;
    ll w;
};

ll gcd(ll a, ll b)
{
    if (a > b)
        swap(a, b);
    if (a == 0)
        return b;
    else
        return gcd(b % a, a);
}

void solve()
{
    ll n;
    cin>>n;
    ll ans = 1e18;
    ll l1 ,r1;
    cin>>l1>>r1;
    ans=min(ans,gcd(r1,l1));
    for(int i = 2;i<=n;i++){
        ll l,r;
        cin>>l>>r;
        ans = min(ans,gcd(r1,r));
        r1 = r;
    }
    cout<<ans<<endl;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t = 1;
    // cin >> t;

    while (t--)
    {
        solve();
    }
    return 0;
}