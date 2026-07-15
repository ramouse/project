#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define endl '\n'

ll get_sum(ll x){
    ll res = 0;
    while(x>0){
        res+=x%10;
        x/=10;
    }
    return res;
}

void solve(){
    ll x;
    cin>>x;
    ll ans = 0;
    for(int i = 0;i<=90;i++){
        ll y = x+i;
        if(y-get_sum(y) == x){
            ans++;
        }
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