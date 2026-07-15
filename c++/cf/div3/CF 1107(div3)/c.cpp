#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define endl '\n'

const ll N = 1e9;
const ll MOD = 676767677;


void solve(){
    ll n;
    cin>>n;
    string s;
    cin>>s;

    ll o = 0,z = 0;
    // ll last = s[1],llast = s[0];
    for(char c : s){
        if(c == '1') o++;
        if(c == '0') z++;
    }
    if(o == s.length() || z == s.length()){
        cout<<1<<endl;
        return;
    }

    bool ok1 = false;
    bool ok2 = false;
    for(int i = 0;i<n-1;i++){
        if(s[i] == '0' && s[i+1] == '1') ok1 = true;
        if(s[i] == '1' && s[i+1] == '0') ok2 = true;

    }

    if(ok1 && ok2){
        cout<<1<<endl;
    }else{
        cout<<2<<endl;
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t = 1;
    cin>>t;
    // init();
    while(t--){
        solve();
    }
    return 0;
}