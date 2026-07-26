#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define endl '\n'

const ll N = 1e6+5;
const ll MOD = 676767677;

void solve(){
    ll n;
    cin>>n;
    vector<ll> a(n+1,0);
    for(int i = 1;i<=n;i++){
        cin>>a[i];
    }
    ll ans =0;
    for(int i = 2;i<n;i++){
        if(a[i] > a[i-1] && a[i] > a[i+1]){
            ans++;
        }
    }
    cout<<ans<<endl;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t = 1;
    // cin>>t;
    while(t--){
        solve();
    }
    return 0;
}