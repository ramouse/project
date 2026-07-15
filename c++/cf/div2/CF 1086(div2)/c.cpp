#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define endl '\n'



void solve(){
    ll n;
    cin>>n;
    vector<double> p(n+1,0.0);
    vector<double> c(n+1,0.0);
    for(int i = 1;i<=n;i++){
        cin>>c[i]>>p[i];
    }

    vector<double> dp(n+2,0.0);
    for(int i = n;i;--i){
        dp[i] = max(dp[i+1],c[i]+(double)(1-p[i]/100)*dp[i+1]);
    }
    printf("%.10lf\n",dp[1]);

}

int main(){
    int t;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}