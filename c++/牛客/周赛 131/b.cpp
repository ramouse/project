#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define endl '\n'

void solve(){
    ll n;
    cin>>n;
    string t;
    cin>>t;

    bool ok = true;

    if(n == 1){
        if(t[0] == '1') cout<<"NO"<<endl;
        else cout<<"YES"<<endl;
        return;
    }

    for(int i = 0;i<n-1;i++){
        if(i == n-2){
            if(t[i+1] == '1'){
                if(t[i] == '0'){
                    ok = false;
                    break;
                }
            }
        }
        if(i == 0){
            if(t[i] == '1' && t[i+1] == '0'){
                ok = false;
                break;
            }
        }else{
            if(t[i] == '1'){
                if(t[i-1] == '0' && t[i+1] == '0'){
                    ok = false;
                    break;
                }
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