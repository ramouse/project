#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define endl '\n'

void solve(){
    ll n;
    cin>>n;
    while(n>0){
        if(n%10 == 5 || n%10 == 0){
            cout<<"YES"<<endl;
            return;
        }
        n/=10;
    }
    cout<<"NO"<<endl;
}  

int main(){
    int t;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}