#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define endl '\n'


void solve(){
    ll n;
    cin>>n;
    vector<ll> a(n+1,0);
    ll ma = 0;
    for(int i = 1;i<=n;i++){
        cin>>a[i];
        ma = max(ma,a[i]);
    }
    ll ans = 0;
    for(int i = 2;i<=n-1;i++){
        a[i] = ma;
    }
    for(int i = 1;i<=n;i++) ans += a[i];
    cout<<ans<<endl;

}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}