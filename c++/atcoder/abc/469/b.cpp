#include <bits/stdc++.h>
using ll = long long;
using namespace std;
#define endl '\n'

const ll MOD = 998244353;
const ll INF = 1e18;
const ll N = 1e4;

void solve()
{
    ll n;
    cin>>n;
    string s;
    cin>>s;
    ll ans = 0;
    for(int i = 0;i<s.length();i++){
        bool ok = true;
        if(s[i] == 'x'){
            if(i>0){
                if(s[i-1] == 'o') ok = false;
            } 
            if(i < s.length() - 1){
                if(s[i+1] == 'o') ok = false;
            }
        }else{
            ok = false;
        }
        if(ok) ans++;
    }
    cout<<ans<<endl;
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