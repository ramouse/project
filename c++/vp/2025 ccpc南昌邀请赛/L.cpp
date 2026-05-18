#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define endl '\n'

const ll N = 1e9+5;

void solve(){
    ll a,b;
    cin>>a>>b;
    if(a == 30){
        cout<<"Alice"<<endl;
        return;
    }
    if(b == 30){
        cout<<"Bob"<<endl;
        return;
    }
    if(a-b>=2 && a>=21){
        cout << "Alice" << endl;
        return;
    }else if(b-a>=2 && b>=21){
        cout << "Bob" << endl;
        return;
    }else{
        cout << "Underway"<<endl;
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t = 1;
    // cin>>t;
    while(t--){
        solve();
    }
    return 0;
}