#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define endl '\n'

void solve(){
    ll n;
    cin>>n;
    vector<ll> a(n+1,0);
    vector<ll> pre(n+1,0);
    ll total = 0;
    for(int i = 1;i<=n;i++){
        cin>>a[i];
    }

    ll ans = 0;
    ll cnt = 0;
    for(int i = 1;i<=n;i++){
        ans += (n-1) * (a[i]/2);
        if(a[i]&1) cnt++;
    }
    ans += cnt*(cnt - 1) / 2;
    cout<<ans<<endl;

}

int main(){
    int t;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}