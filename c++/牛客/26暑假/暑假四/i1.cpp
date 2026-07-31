#include <bits/stdc++.h>
using ll = long long;
using namespace std;
#define endl '\n'

const ll MOD = 998244353;
const ll INF = 1e18;
const ll N = 1e5;

void solve()
{
    string s;
    cin >> s;
    ll k = 0;
    cin >> k;

    ll len = s.length();
    s += s;
    string t = "Rounddo";
    for (int i = 1; i <= k; i++)
    {
        t += 'g';
    }
    ll ans = 0;
    ll cnt = 0;
    // cout<<len<<" "<<t.length()<<endl;
    ll tlen = t.length();
     for (int i = 0; i < len; i++)
    {
        if (s.substr(i, tlen) == t)
        {  
            cnt++;
        }
    }
    if(cnt==0){cout<<0<<endl;return;}
    if(cnt==1){cout<<len-tlen+1<<endl;}
    if(cnt>=2){cout<<len<<endl;}
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t = 1;
    cin >> t;
    while (t--)
        solve();

    return 0;
}