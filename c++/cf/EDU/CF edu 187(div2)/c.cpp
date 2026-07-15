#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define endl '\n'

void solve(){
    ll s,m;
    cin>>s>>m;
    ll low = __builtin_ctzll(m);

    if(s%(1LL<<low) != 0){
        cout<<-1<<endl;
        return;
    }

    vector<ll> pos;
    for(int i = 0;i<=63;i++){
        if((m>>i)&1){
            pos.push_back(i);
        }
    }

    auto check =[&](ll n){
        ll sh = s;
        for(int i = pos.size()-1;i>=0;i--){
            ll val = 1LL<<pos[i];
            sh -= min(n,sh/val)*val;
        }
        return sh==0;
    };

    ll R = s;
    ll L = 1;
    ll ans = -1;
    while(L<=R){
        ll mid = (L+R)>>1;
        if(check(mid)){
            R = mid-1;
            ans = mid;
        }else{
            L = mid+1;
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