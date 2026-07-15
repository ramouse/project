#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define endl '\n'

const ll INF = 1e18;

void solve()
{   
    ll n;
    cin>>n;
    vector<ll> a(n+1,0);
    for(int i = 1;i<=n;i++){
        cin>>a[i];
    }
    ll cur = 0;
    for(int i = 1;i<=n;i++){
        if(a[i] + cur >= i){
            cur += a[i] - i;
        }else{
            cout<<"No"<<endl;
            return;
        }
    }

    cout<<"Yes"<<endl;
}

int main()
{
    int t = 1;
    cin >> t;
    while (t--)
        solve();
    return 0;
}