#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define endl '\n'

void solve(){
    ll l,r,d,u;
    cin>>l>>r>>d>>u;
    ll diff = u-d+1;
    
    ll ans = 0;
    for(;l<=r;l++){
        if(abs(l)&1){
            if(abs(u-abs(l))>=0){
                ans += (u - abs(l) + 1)/2 ;
            }
        }else{
            ans+=diff;
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