#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define endl '\n'

void solve(){
    ll n;
    cin>>n;
    vector<ll> a(n+1,0);
    for(int i = 1;i<=n;i++) cin>>a[i];
    
    vector<ll> dp(n+5,0);
    
    ll ans = 0;
    for(int i = 1;i<=n;i++){
        dp[a[i]] = max(dp[a[i]-1],dp[a[i]+1]) + 1;
        ans = max(ans,dp[a[i]]);
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