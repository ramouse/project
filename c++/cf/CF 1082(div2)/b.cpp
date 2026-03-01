#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define endl '\n'

void solve(){
    ll n;
    cin>>n;
    string s;
    cin>>s;
    
    bool ok = true;
    if(n&1){
        if(s[0] == 'b'){
            ok = false;
        }

        for(int i = 1;i<=n-1;i+=2){
            if(s[i] != '?' && s[i+1] != '?' && s[i] == s[i+1]){
                ok = false;
                break;
            }
        }
    }else{
        for(int i = 0;i<=n-1;i+=2){
            if(s[i] != '?' && s[i+1] != '?' && s[i] == s[i+1]){
                ok = false;
                break;
            }
        }
    }

    if(ok) cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
    
}

int main(){
    int t;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}