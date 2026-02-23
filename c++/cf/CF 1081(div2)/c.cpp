#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define endl '\n'

void solve(){
    ll n,h,k;
    cin>>n>>h>>k;
    vector<ll> a(n+1,0);
    vector<ll> pre(n+1,0);
    vector<ll> p_min(n+1,2e9);
    vector<ll> suf_ma(n+2,0);
    ll maxx = 0;
    ll id = 0;
    ll total = 0;
    for(int i = 1;i<=n;i++){
        cin>>a[i];
        pre[i] = pre[i-1] + a[i];
        p_min[i] = min(p_min[i-1],a[i]);
        total += a[i];
        maxx = max(maxx,a[i]);
    }
    for(int i = n;i;--i){
        suf_ma[i] = max(suf_ma[i+1],a[i]);
    }


    if(total == h){
        cout<<n<<endl;
        return;
    }

    ll zu = h/total;
    ll sh = h%total;
    
    ll t = 1;
    for(;t<=n;t++){
        ll cur = pre[t];
        if(t<n){
            if(suf_ma[t+1] > p_min[t]){
                cur += suf_ma[t+1] - p_min[t];
            }
        }
        if(cur>=sh){
            break;
        }
    }

    if(h%total == 0){
        cout << zu * n + (zu-1) * k  << endl;
    }else{
        cout << zu * n + zu * k + t << endl;
    }
    
    

}

int main(){
    int t;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}