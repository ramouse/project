#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define endl '\n'

void solve(){
    ll n;
    cin>>n;
    vector<ll> p(n+1,0);
    vector<ll> a(n+1,0);
    vector<ll> pos(n+1,0);
    for(int i = 1;i<=n;i++){
        cin>>p[i];
        pos[p[i]] = i;
    }
    for(int i = 1;i<=n;i++) cin>>a[i];

    for(int i = 2;i<=n;i++){
        if(pos[a[i]]<pos[a[i-1]]){
            cout<<"No"<<endl;
            return;
        }
    }
    if(pos[a[1]]>pos[a[2]]){
        cout<<"No"<<endl;
    }else{
        cout<<"Yes"<<endl;
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