#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define endl '\n'

const ll MOD = 998244353;
const ll MAXN = 2e5 + 5;

void solve()
{
    string s;
    cin>>s;
    s = " "+s;
    bool ok = true;
    ll la = 0;
    for(int i = 1;i<s.length();i++){
        if(s[i] == s[i+1]){
            la++;
        }
    }
    if(la<=2){
        cout<<"YES"<<endl;
    }else{
        cout<<"NO"<<endl;
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t = 1;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}