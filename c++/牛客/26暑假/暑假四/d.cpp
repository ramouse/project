#include <bits/stdc++.h>
using ll = long long;
using namespace std;
#define endl '\n'

const ll MOD = 998244353;
const ll INF = 1e18;
const ll N = 1e5;

void solve()
{
    ll n;
    cin>>n;
    if(n == 1){
        cout<<1<<endl;
        return;
    }
    if(n == 2){
        cout<<"1 2"<<endl;
        return;
    }
    if(n == 3){
        cout<<"1 3 2"<<endl;
    }


    vector<ll> ans(n+1,0);
    if(n&1){
        
    }else{
        ll t = n;
        ans[1] = 1;
        for(int i = n;i>=n/2;i--){
            ans[t] = i;
            t-=2;
        }
        t = 2;
        ll tt = n-1;
        for(int i = 1;i>=n/2-1;i++){
            ans[tt] = t;
            t++;
            // cout<<t<<endl;
            tt-=2;
        }
    }

    for(int i = 1;i<=n;i++){
        cout<<ans[i]<<" ";
    }
    cout<<endl;
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