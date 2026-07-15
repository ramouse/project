#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define endl '\n'

void solve(){
    ll n;
    cin>>n;
    string s;
    cin>>s;
    
    ll ans = 0;
    for(int i = 0;i<n;i++){
        if (s[i] == '0' && (i == 0 || s[i - 1] == '0') && (i == n-1 || s[i + 1] == '0'))
        {
            if(i + 1 < n && (i + 2 >= n || s[i+2] == '0')){
                s[i+1] = '1';
            }else{
                s[i] = '1';
            }
        }
    }
    for(int i = 0;i<n;i++){
        if(s[i] == '1') ans++;
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