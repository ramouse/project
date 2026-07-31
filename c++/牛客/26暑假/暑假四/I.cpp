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
    cin>>s;
    ll k = 0;
    cin>>k;

    ll len = s.length();
    s += s;
    string t = "Rounddo";
    for(int i = 1;i<=k;i++){
        t+='g';
    }
    ll ans = 0;
    ll cnt = 0;
    // cout<<len<<" "<<t.length()<<endl;
    for(int i = 0;i<len - t.length() + 1;i++){
        // string tt = s.substr(i,len);
        // size_t pos = 0;
        // if(tt.find(t) != string::npos) ans++;
        // if(s.substr(i,t.length()) == t) ans++;
        // cout<<s.substr(i,len)<<endl;

        if(s.substr(i,t.length()) == t){
            // cout<<i<<" ";
            ans += len - t.length() - i + 1 + i - cnt;
            cnt++;
        }

    }
    // if(ans != 0) ans++;
    cout<<ans<<endl;
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