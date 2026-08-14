#include <bits/stdc++.h>
using ll = long long;
using namespace std;
#define endl '\n'

const ll MOD = 998244353;
const ll INF = 1e18;
const ll N = 1e4;

void solve()
{
    ll n,k;
    cin>>n>>k;
    string s;
    cin>>s;
    double ans = INF;
    ll cnt = 0;
    s = " " + s;

    for(int i = 1;i<=n;i++){
        ll r = i;
        while(r <= n){
            if(s[r] == 'o') cnt++;
        }
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int t = 1;
    // cin>>t;
    while (t--)
        solve();

    return 0;
}