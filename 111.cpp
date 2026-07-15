#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define endl '\n'

const ll N = 1e9+5;
const ll MOD = 676767677;

void solve(){
    string s;
    cin>>s;
    for(auto &c : s){
        if(islower(c)){
            c = c - 'a' + 'A';
        }
    }
    cout<<s<<endl;
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