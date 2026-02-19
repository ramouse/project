#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define endl '\n'

void solve(){
    ll n,k;
    cin>>n>>k;
    deque<ll> dq;
    for(int i = 1;i<=n;i++){
        ll a;
        cin>>a;
        dq.push_back(a);
    }
    ll ans = k + dq.front();
    for(int i = 1;i<=n;i++){
        dq.push_front(k);
        k = dq.back();
        dq.pop_back();
        ans = max(ans,k+dq.front());

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