#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define endl '\n'

void solve(){
    int n;
    cin>>n;
    vector<int> a(n+1,0),b(n+1,0);
    for(int i = 1;i<=n;i++) cin>>a[i];
    for(int i = 1;i<=n;i++) cin>>b[i];

    ll ans = 0;
    for(int i = 1;i<=n;i++){
        ll cur = a[i] - b[i];
        if(cur>0) ans+=cur;
    }
    cout<<ans+1<<endl;
}

int main(){
    int t;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}