#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define endl '\n'

void solve(){
    ll n;
    cin>>n;
    ll m = (n+1)/2;
    m++;
    for(int i = 1;i<=n;i++){
        if(i&1){
            cout<<-1<<" ";
        }else{
            if(i != n){
                cout<<3<<" ";
            }else{
                cout<<2<<" ";
            }
        }
    }
    cout<<endl;
}

int main(){
    int t;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}