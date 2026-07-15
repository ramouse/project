#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define endl '\n'

void solve(){
    int n;
    cin>>n;
    string s;
    cin>>s;
    int ans = 1;
    int p = 0;
    
    int l = 1,r = 0;
    char cur = s[0];
    while(l<n){
        if(s[l] == cur){
            l++;
            p = 1;
        }else{
            ans++;
            cur = s[l];
            l++;
        }
    }

    if(p==1){
        if(s[0] != s[n-1]) ans++;
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