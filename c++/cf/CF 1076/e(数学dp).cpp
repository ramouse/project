#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define endl '\n'

void solve(){
    ll n;
    cin>>n;
    vector<ll> dp(n+1,1e9);
    for(int i = 0;i<n;i++){
        ll a;
        cin>>a;
        dp[a] = 1;
    }

    for(int i = 1;i<=n;i++){
        for(int j = i;j<=n;j+=i){
            dp[j] = min(dp[j],dp[i] + dp[j/i]);
        }
    }

    for(int i = 1;i<=n;i++){
        if(dp[i] == 1e9) cout<<-1<<" ";
        else cout<<dp[i]<<" ";
    }
    cout<<endl;


}

int main(){
    int t;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}