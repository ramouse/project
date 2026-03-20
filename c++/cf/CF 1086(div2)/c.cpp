#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define endl '\n'



void solve(){
    ll n;
    cin>>n;
    vector<pair<int,int>> vec(n+1);
    for(int i = 1;i<=n;i++){
        int c,p;
        cin>>c>>p;
        vec[i].first = c;
        vec[i].second = p;
    }

    double ans = 0.0;
    for(int i = n;i;--i){
      
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