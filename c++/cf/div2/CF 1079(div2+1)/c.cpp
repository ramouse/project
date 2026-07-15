#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define endl '\n'

void solve(){
    ll p,q;
    cin>>p>>q;
    if(p>=q){
        cout<<"Alice"<<endl;
        return;
    }

    if(p*3 >= q*2){
        cout<<"Bob"<<endl;
    }else{
        cout<<"Alice"<<endl;
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