#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define endl '\n'

void solve(){
    ll n;
    cin>>n;

    vector<ll> a(n+1,0);
    // map<ll,ll,greater<ll>> cnt;
    ll maxx = 0;
    for(int i = 1;i<=n;i++){
        cin>>a[i];
        maxx = max(a[i],maxx);
        // cnt[a[i]]++;
    }
    // vector<ll> b = a;
    // sort(b.begin()+1,b.end(),greater<ll>());

    // ll val = -1;
    // int i = 1;
    // while(i<=n){
    //     int j = i;
    //     while(j<=n && b[j] == b[i]) j++;

    //     ll cnt = j-i;
    //     if(cnt % 2 != 0){
    //         val = b[i];
    //         break;
    //     }
    //     i = j;
    // }
    // string ans = "";
    // for(int i = 1;i<=n;i++){
    //     if(a[i] == val && val != -1) ans += '1';
    //     else ans+='0';
    // }
    // cout<<ans<<endl;

    ll cnt = 0;
    for(int i = 1;i<=n;i++){
        if(a[i] == maxx) cnt++;
    }
    string ans = "";
    for(int i = 1;i<=n;i++){
        if(cnt%2 != 0){
            if(a[i] == maxx) ans+='1';
            else ans+='0';
        }else{
            if(a[i]<maxx) ans+='1';
            else ans+='0';
        }
    }
    cout<<ans<<endl;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}