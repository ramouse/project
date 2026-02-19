#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define endl '\n'

void solve(){
    ll n,x,y;
    cin>>n>>x>>y;
    vector<ll> a(n+1,0);
    vector<ll> nu(n+1,0);
    ll sum = 0;
    for(int i = 1;i<=n;i++){
        cin>>a[i];
        nu[i] = a[i]/x;
        sum+=nu[i];
    }
    ll ans = 0;
    for(int i = 1;i<=n;i++){
        ans = max(ans,a[i]+(sum-nu[i])*y);
    }
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