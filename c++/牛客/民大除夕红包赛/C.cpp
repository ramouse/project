#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define endl '\n'

const int MOD = 998244353;
const int N = 2e5+5;

vector<ll> dp(N,0);

void solve(){
    ll n;
    cin>>n;

    cout<<dp[n]<<endl;
    

}

int main(){
    int t;
    cin>>t;
    dp[1] = 2;
    dp[2] = 3;
    dp[3] = 5;
    for(int i = 4;i<N;i++){
        dp[i] = (dp[i-1] + dp[i-2]) % MOD;
    }
    while(t--){
        solve();
    }
    return 0;
}