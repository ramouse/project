#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define endl '\n'

const ll MOD = 998244353;

void solve(){
    ll n;
    cin>>n;
    vector<ll> a(n+1,0);
    for(int i =1;i<=n;i++) {
        cin>>a[i];
    }

    vector<ll> p(10,0);
    for(int i = 1;i<=n;i++){
        for(int j = 0;j<64 - __builtin_clzll(a[i]);j++){
            if((a[i]>>j) & 1){
               p[j]++;
            }
        }
    }
    ll ans = 0;
    cout<<endl;
    for(int i = 9;i>=0;i--){
        if(p[i]%2==1){
            ans += (1<<(i));
        }
    }
    ll ans1 = ans;
    for(int i = 0;i<=9;i++){
        if(p[i]){
            ans1 -=(1<<i);
            break;
        }
    }
    cout<<ans<<" "<<ans1;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t = 1;
    // cin>>t;
    while(t--){
        solve();
    }
    return 0;
}