#include<bits/stdc++.h>
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
    sort(a.begin()+1,a.end());
    ll ans = 0;
    for(int i = 2;i<=n;i++){
        if(a[i]<=a[i-1]){
            ans+=a[i-1]-a[i]+1;
            a[i] = a[i-1]+1;
        }
    }
    cout<<ans<<endl;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t = 1;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}