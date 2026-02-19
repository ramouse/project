#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define endl '\n'

void solve(){
    ll n;
    cin>>n;
    vector<ll> p(n+1,0);
    vector<ll> pre(n+1,2e8);
    vector<ll> suf(n+2,0);
    vector<ll> s;
    for(int i = 1;i<=n;i++){
        cin>>p[i];
        pre[i] = min(pre[i-1],p[i]);
    }
    for(int i = n;i;i--){
        suf[i] = max(suf[i+1],p[i]);
    }

    bool ok = true;
    for(int i = 2;i<=n;i++){
        if(pre[i-1]>suf[i]){
            ok = false;
            break;
        }
    }
    
    if(ok){
        cout<<"Yes"<<endl;
        for(int i = 1;i<=n-1;i++){
            if(p[i]<suf[i+1]){
                cout<<p[i]<<" "<<suf[i+1]<<endl;
            }else{
                cout<<pre[i]<<" "<<suf[i+1]<<endl;
            }
        }
        
    }else{
        cout<<"No"<<endl;
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