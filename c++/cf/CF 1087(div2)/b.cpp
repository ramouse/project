#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define endl '\n'

const ll N = 1e9;
const ll N1 = -1e9;

void solve(){
    ll n;
    cin>>n;
    vector<ll> a(n+1,0);
    vector<ll> aa(n + 1, 0);
    vector<ll> dif(n+1,0);
    vector<ll> diff(n+1,0);
    for(int i = 1;i<=n;i++){
        cin>>a[i];
        aa[i] = a[i];
        a[i] -= N;
        a[i] = abs(a[i]);
        aa[i] -= N1; 
        aa[i] = abs(aa[i]);
    }

    for(int i = 1;i<=n;i++){
        for(int j = i+1;j<=n;j++){
            if(a[i]>a[j]){
                dif[i]++;
            }
            if(aa[i]>aa[j]){
                diff[i]++;
            }
        }
    }


    for(int i = 1;i<=n;i++){
        cout<<max(dif[i],diff[i])<<" ";
    }
    cout<<endl;
    
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