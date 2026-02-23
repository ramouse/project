#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define endl '\n'

void solve(){
    ll n;
    cin>>n;
    vector<ll> f(n+1,0);
    for(int i = 1;i<=n;i++){
        cin>>f[i];
    }
    vector<ll> a(n+1,0);
    for(int i = 2;i<=n-1;i++){
        a[i] = (f[i+1] + f[i-1] - 2*f[i]) / 2;
    }

    ll num = 0;
    for(int i = 2;i<=n-1;i++){
        num+=a[i]*(i-1);
    }
    a[n] = (f[1] - num)/(n-1);
    
    num = 0;
    for(int i = 2;i<=n;i++){
        num += (n-i)*a[i];
    }
    a[1] = (f[n] - num)/(n-1);

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