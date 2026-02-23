#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define endl '\n'

void solve(){
    ll n;
    cin>>n;
    vector<ll> a(n+1,0),b(n+1,0);
    for(int i = 1;i<=n;i++){
        cin>>a[i];
    }
    for(int i = 1;i<=n;i++){
        cin>>b[i];
    }
    bool ok = true;
    if(a[n] != b[n]){
        cout<<"No"<<endl;
        return;
    }
    for(int i = n-1;i;i--){
        if(a[i] != b[i]){
            ll t1 = a[i] ^ a[i+1];
            ll t2 = a[i] ^ b[i+1];
            if(t1 != b[i] && t2 != b[i]){
                ok = false;
                break;
            }
        }
    }

    if(ok) cout<<"Yes"<<endl;
    else cout<<"No"<<endl;
}

int main(){
    int t;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}