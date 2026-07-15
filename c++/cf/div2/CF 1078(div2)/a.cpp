#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define endl '\n'

void solve(){
    ll n,w;
    cin>>n>>w;
    ll zu = n/w;
    ll sh = n%w;
    cout<<zu*(w-1) + sh<<endl;
}

int main(){
    int t;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}