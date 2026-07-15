#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define endl '\n'

void solve(){
    ll n,l,r;
    cin>>n>>l>>r;
    string s;
    cin>>s;
    s=" "+s;

    vector<ll> cnt(256,0);
    ll ans = 0;
    for(int i = l+1;i<=min(n,1+r);i++) cnt[s[i]]++;
    for(int i = 1;i<=n;i++){
        ans += cnt[s[i]];
        int L = l+i;
        int R = r+i+1;
        if(L<=n){
            cnt[s[L]]--;
        }
        if(R<=n){
            cnt[s[R]]++;
        }
        
    }
    // for(int i = l+1;i<=n;i++){
    //     int R = i-l;
    //     if(R>=1){
    //         cnt[s[R]]++;
    //     }
    //     int L = i-r-1;
    //     if(L>=1){
    //         cnt[s[L]]--;
    //     }

    //     ans+=cnt[s[i]];
    // }
    
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