#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define endl '\n'

const ll N = 1e9;
const ll MOD = 676767677;

void solve(){
    ll n;
    cin>>n;
    vector<ll> a(n+1,0),b(n+1,0),vec(n+1,0);
    for(int i = 1;i<=n;i++) cin>>a[i];
    for(int i = 1;i<=n;i++){
        cin>>b[i];
        vec[i] = a[i] - b[i];
    }
    // for(int i = 1;i<=n;i++){
    //     cout<<vec[i]<<" ";
    // }

    ll cur = 0;
    for(int i = n-1;i;i--){
        if(vec[i+1] > 0){
            vec[i] += vec[i+1];
        }
    }
    cur=vec[1];
    // cout<<cur<<" ";
    if(cur <= 0){
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