#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define endl '\n'

void solve(){
    ll n;
    cin>>n;
    vector<ll> a(n+1,0);
    for(int i = 1;i<=n;i++){
        cin>>a[i];
    }

    ll ans = 0;
    for(int i = 1;i<=n;i++){
        for(int j = i+1;j<=n;j++){
            if(a[i] * a[j] == j-i){
                ans++;
            }
        }
    }
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