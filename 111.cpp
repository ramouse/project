#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define endl '\n'

const ll N = 1e6+5;
const ll MOD = 676767677;

void solve(){
    ll n,m;
    cin>>n>>m;

    vector<pair<ll,ll>> vec(n+1);
    vector<ll> diff(N+1,0);
    for(int i = 1;i<=n;i++){
        cin>>vec[i].first>>vec[i].second;
        diff[vec[i].first+1]--;
        diff[vec[i].second+1]++;
    }

    for(int i = 1;i<=N;i++){
        diff[i] += diff[i-1];
    }

    ll cnt = 0;
    ll ans = 0;
    for(int i = N;i>=0;i--){
        if(diff[i] > 0){
            ll x = 2 * i - 1;
            if(diff[i] + cnt>=m){
                ans += (m - cnt) * x;
                break;
            }else{
                ans += diff[i] * x;
                cnt+=diff[i];
            }
        }
    }
    
    cout<<ans<<endl;

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