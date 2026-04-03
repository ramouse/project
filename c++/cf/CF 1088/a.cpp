#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define endl '\n'

void solve(){
    ll n;
    cin>>n;
    vector<ll> p(n+1,0);
    multiset<ll,greater<ll>> se;
    for(int i = 1;i<=n;i++){
        cin>>p[i];
        se.insert(p[i]);
    }

    if(n<3){
        for(int i = 1;i<=n;i++){
            cout<<n<<" ";
        }
        cout<<endl;
        return;
    }

    for(int i=  1;i<=n;i++){
        cout<<2<<" ";
    }
    cout<<endl;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t = 1;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}