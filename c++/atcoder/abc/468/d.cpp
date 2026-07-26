#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define endl '\n'

const ll N = 1e6+5;
const ll MOD = 998244353;

void solve(){
    string s;
    cin>>s;
    ll ans = s.length();
    ll len = s.size();
    for(int i = 1;i<s.length() - 1;i++){
        ll cnt = 0;
        for(int j = 1;j<=min((ll)i,len - i - 1);j++){
            if(s[i-j] != s[i+j]){
                cnt++;
            }
            if(cnt <= 1){
                // cout<<i<<" "<<j<<endl;
                ans++;
            }else break;
        }
    }

    for(int i = 0;i<s.length()-1;i++){
        ll cnt = 0;
        if(s[i] != s[i+1]) cnt++;
        if(cnt<=1) ans++;
        for(int j = 1;j<=min((ll)i,len - i - 2);j++){
            if(s[i-j] != s[i+j+1]){
                // cout << i << " " << j << endl;
                cnt++;
            }
            if(cnt<=1){
                
                ans++;
            }else break;
        }
    }

    cout<<ans<<endl;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t = 1;
    // cout<<'j'-'0'-'0'<<endl;
    // cin>>t;
    while(t--){
        solve();
    }
    return 0;
}