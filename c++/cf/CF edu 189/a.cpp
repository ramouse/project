#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define endl '\n'

const ll MOD = 998244353;
const ll MAXN = 2e5 + 5;

void solve()
{
    ll x,y;
    cin>>x>>y;
    if(y-x==1){
        cout<<"NO"<<endl;
        return;
    }

    for(ll i = x+x;i<=y;i+=x){
        if(i%x==0 && y%i != 0){
            cout<<"YES"<<endl;
            return;
        }
    }
    cout<<"NO"<<endl;
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