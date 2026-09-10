#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using i128 = __int128_t;
#define endl '\n'
#define pll pair<ll, ll>
#define T tuple<ll, ll, ll>
#define all1(x) x.begin() + 1, x.end()
#define all0(x) x.begin(), x.end()
#define pb push_back
#define fir first
#define sec second

const ll MOD = 998244353;
const ll INF = 1e18;

struct Node{
    ll w,v,c;
};

void solve()
{
    ll n;
    cin>>n;

    vector<Node> vec(n+1);
    ll tot = 0;
    for(int i = 1;i<=n;i++){
        cin>>vec[i].w>>vec[i].v>>vec[i].c;
        tot += vec[i].w;
    }

    sort(all1(vec),[&](auto const&x,auto const&y){
        return x.c * y.w > y.c * x.w;
    });

    ll ans = 0;
    ll pre = 0;
    for(int i = 1;i<=n;i++){
        ans += vec[i].v;
        ans -= pre * vec[i].w;
        pre += vec[i].c;
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