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

    if(a[1] == -1){
        a[1] = a[n];
    }else if(a[n] == -1){
        a[n] = a[1];
    }
    for(int i = 1;i<=n;i++){
        if(a[i] == -1) a[i] = 0;
    }
    cout<<abs(a[n]-a[1])<<endl;
    for(int i = 1;i<=n;i++){
        cout<<a[i]<<" ";
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