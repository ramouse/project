#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define endl '\n'

int main(){
    ll n,t;
    cin>>n>>t;
    vector<ll> a(n+1,0);
    for(int i = 1;i<=n;i++) cin>>a[i];
    ll ans = 0;
    ll change = 0;

    for(int i = 1;i<=n;i++){
        if(change < a[i]){
            ans += a[i] - change;
            change = a[i] + 100;
        }
    }
    if(change < t) ans += t-change;
    cout<<ans;
    return 0;
}