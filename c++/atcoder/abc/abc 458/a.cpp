#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define endl '\n'
#define T tuple<ll,ll,ll>
#define pll pair<ll,ll>

const ll MOD = 998244353;
const ll INF = 1e18;
const ll LOG = 30;

void solve()
{
    string s;
    cin>>s;
    s = " "+s;
    ll n;
    cin>>n;
    for(int i = n+1;i<s.length()-n;i++){
        cout<<s[i];
    }
    cout<<endl;
}   

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t = 1;
    // cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}