#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define endl '\n'
#define T tuple<ll,ll,ll>
#define pll pair<ll,ll>

const ll MOD = 998244353;
const ll INF = 1e18;
const ll LOG = 30;
const ll N = 1e6+10;

struct Node{
    ll l,r,id;
};

void solve()
{
    ll a,b,c;
    cin>>a>>b>>c;

    ll ans = 0;
    ll zu = a/3;
    ll sh = a%3;
    ll zu1 = zu;
    if(sh!=0) zu++;
    ans = b*a;
    ans = min(ans,c*zu);
    cout<<min(ans,c*zu1 + sh*b)<<endl;
}   

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t = 1;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}