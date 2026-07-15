#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define endl '\n'

void solve(){
    ll n,m;
    cin>>n>>m;
    vector<ll> a(n+1,0);
    vector<ll> b(n+1,0);

    for(int i = 1;i<=n;i++) cin>>a[i];
    for(int i = 1;i<=m;i++) cin>>b[i];

    if(n<m){
        cout<<"NO"<<endl;
        return;
    }

    ll l = 1,r = 1;
    bool ok = false;
    while(1){
        if(a[l]>=b[r]){
            l++,r++;
        }else{
            l++;
        }
        if(l>n || r>m){
            break;
        }
    }
    if(r == m+1){
        cout<<"YES"<<endl;
    }else cout<<"NO"<<endl;
}

int main(){
    int t;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}