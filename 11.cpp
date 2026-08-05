#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define endl '\n'

const ll MOD = 10000;
const ll INF = 1e18;

struct Node
{
    ll lx, ly, rx, ry;
};

void solve()
{
    ll n;
    cin>>n;
    ll B = 131;
    set<ll> se;
    ll ans = 0;
    for(int i = 1;i<=n;i++){
        string s;
        cin>>s;
        ll cur = 0;
        for(int i = 0;i<s.length();i++){
            cur = cur * B + s[i];
        }
        if(!se.count(cur)){
            ans++;
            se.insert(cur);
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
        solve();
}