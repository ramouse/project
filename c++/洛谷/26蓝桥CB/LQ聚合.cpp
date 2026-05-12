#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define endl '\n'

void solve()
{
    ll n;
    cin >> n;
    string s;
    cin >> s;
    s = " " +s;
    
    ll cl = 0;
    ll cur = 0;
    ll tot = 0;
    for(int i = 1;i<=n;i++){
        if(s[i] == 'L'){
            cl++;
        }
        if(s[i] == 'Q' || s[i] == '?'){
            tot++;
            cur += cl;
        }
    }

    ll ans = cur;
    cl = 0;
    for(int i = 1;i<=n;i++){
        if(s[i] == 'L'){
            cl++;
        }

        if(s[i] == 'Q'){
            tot--;
        }
        if(s[i] == '?'){
            tot--;

            cur-=cl;
            cur+=tot;
            cl++;
            ans=max(ans,cur);
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
    {
        solve();
    }
    return 0;
}