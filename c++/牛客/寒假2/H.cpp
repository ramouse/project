#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define endl '\n'



void solve(){
    ll n;
    cin>>n;
    ll ans = 0;
    vector<ll> a(n+1,0);
    vector<ll> pre(n+2,0);
    for(int i = 1;i<=n;i++){
        cin>>a[i];
        pre[i] = pre[i-1] + a[i];
    }
    for(int i = 1;i<=n;i++){
        for(int j = 1;j<i;j++){
            ans+=pre[i]-pre[j];
        }
        ans+=pre[i];
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