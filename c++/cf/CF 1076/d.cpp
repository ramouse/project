#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define endl '\n'

void solve(){
    ll n;
    cin>>n;
    vector<ll> a(n+1,0);
    vector<ll> b(n+1,0);
    for(int i = 1;i<=n;i++){
        cin>>a[i];
    }
    for(int i = 1;i<=n;i++){
        cin>>b[i];
    }
    sort(a.begin()+1,a.end(),greater<ll>());

    ll ans = 0;
    ll h = 0;
    ll sum = 0;
    for(int i = 1;i<=n;i++){
        while(h<n && sum + b[h+1] <= i) h++,sum+=b[h];
        ans = max(ans,h*a[i]);
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