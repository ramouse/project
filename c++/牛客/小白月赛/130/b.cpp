#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define endl '\n'



void solve(){
    ll n;
    cin>>n;
    vector<ll> a(n+1,0),b(n+1,0),diff(n+1,0);
    for(int i = 1;i<=n;i++){
        cin>>a[i];
    }
    for(int i = 1;i<=n;i++){
        cin>>b[i];
    }
    for(int i = 1;i<=n;i++){
        diff[i] = a[i]-b[i];
    }

    ll t = 0;
    for(int i = 1;i<=n;i++){
        if(i&1){
            t+=diff[i];
        }else{
            t-=diff[i];
        }
    }

    if(t == 0){
        cout<<"Yes"<<endl;
    }else{
        cout<<"No"<<endl;
    }

}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t = 1;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}