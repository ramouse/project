#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define endl '\n'

const ll INF = 1e18;
const ll MAXN = 3e5+5;
const ll MOD = 998244353;

void solve()
{   
    ll n,m;
    cin>>n>>m;
    vector<string> vec(n+1);
    vector<ll> cnt(n+1,0);
    for(int i = 1;i<=n;i++){
        cin>>vec[i];
    }

    for(int i = 1;i<=m;i++){
        string s;
        cin>>s;
        for(int j = 1;j<=n;j++){
            // cout<<vec[i].substr(0,s.length())<<endl;
            if(s == vec[j].substr(0,s.length())){
                cnt[j]++;
            }
        }
    }

    for(int i = 1;i<=n;i++){
        cout<<cnt[i]<<" ";
    }

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