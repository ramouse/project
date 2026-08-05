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
    string s;
    cin>>s;
    s = " " + s;
    string t = "";
    ll cnt = 0;


    ll ans = 1;
    for(int i = 1;i<n;i++){
        if(s[i] != s[i+1]) ans++;
    }

    ll d = 0;
    for(int i = 2;i<n;i++){
        ll cur = (s[i - 1] != s[i + 1]) - (s[i - 1] != s[i]) - (s[i] != s[i + 1]);
        d =min(d,cur);
    }
    cout<<ans+d<<endl;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t = 1;
    cin >> t;
    while (t--)
        solve();
}