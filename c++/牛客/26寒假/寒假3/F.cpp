#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define endl '\n'

void solve(){
    ll n;
    cin>>n;
    ll ans = 0;

    // if(n == 1) ans = 0;
    // if(n == 2) ans = 1;
    // if(n == 3) ans = 2;
    // if(n == 4) ans = 4;
    // if(n>4){
    //     ans+=4;
    //     ll zu = (n - 4) / 4;
    //     ll sh = (n - 4) % 4;
    //     ans += zu * 5;
    //     if (sh == 1)
    //         ans++;
    //     else if (sh == 2)
    //         ans += 2;
    //     else if (sh == 3)
    //         ans += 3;
    // }
    
    // if(n == 1) ans = 0;
    // else{
    //     ll zu = (n-1)/3;
    //     ll sh = (n-1)%3;
    //     ans+=zu*4;
    //     if(sh == 1) ans += 1;
    //     else if(sh == 2) ans+=2;
    // }

    if(n==1) ans = 0;
    else ans = n-1 + (n-1)/3;
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