#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define endl '\n'

struct Node{
    ll l,r;
};

void solve(){
    ll n;
    cin>>n;
    vector<ll> a(n+1,0);
    for(int i = 1;i<=n;i++){
        cin>>a[i];
    }
    
    vector<Node> ve;

    for(int i = 1;i<=n;i++){
        if(!ve.empty() && a[i]-1>=ve.back().l && a[i]-1<=ve.back().r){
            ve.back().r = a[i];
        }else{
            ve.push_back({a[i],a[i]});
        }
    }
    cout<<ve.size()<<endl;
    
}

int main(){
    int t;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}