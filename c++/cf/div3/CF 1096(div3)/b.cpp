#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define endl '\n'

const ll MOD = 1e9 + 7;
const ll MAXN = 2e5 + 5;

void solve()
{
    ll n;
    cin>>n;
    string s;
    cin>>s;

    ll a = 0,b = 0;
    for(auto c : s){
        if(c == ')') a++;
        if(c == '(') b++;
    }

    if(a == b){
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