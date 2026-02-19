#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define endl '\n'

int Q(int n){
    while(n%2 == 0){
        n/=2;
    }
    return n;
}

void solve(){
    ll n;
    cin>>n;
    vector<ll> a(n+1,0);
    bool ok = true;
    for(int i = 1;i<=n;i++){
        cin>>a[i];
        if(Q(i) != Q(a[i])) ok = false;
    }

    
    
    if(ok) cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
}

int main(){
    int t;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}