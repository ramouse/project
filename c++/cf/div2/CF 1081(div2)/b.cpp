#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define endl '\n'

void solve(){
    ll n;
    cin>>n;
    string s;
    cin>>s;

    ll one = 0,zero = 0;
    for(int i = 0;i<n;i++){
        if(s[i] == '0') zero++;
        else one++;
    }
    if(zero == n){
        cout<<0<<endl;
        return;
    }

    if(n&1){
        if(one&1){
            cout<<-1<<endl;
        }else{
            cout<<one<<endl;
            for(int i = 0;i<n;i++){
                if(s[i] == '1') cout<<i+1<<" ";
            }
            cout<<endl;
        }
    }else{
        if(one&1){
            cout<<zero<<endl;
            for(int i = 0;i<n;i++){
                if(s[i] == '0') cout<<i+1<<" ";
            }
            cout<<endl;
        }else{
            cout<<one<<endl;
            for(int i = 0;i<n;i++){
                if(s[i] == '1') cout<<i+1<<" ";
            }
            cout<<endl;
        }
    }
    
}

int main(){
    int t;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}