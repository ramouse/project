#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define endl '\n'

const ll N = 1e9+5;
const ll MOD = 10007;

// ll f(ll a,ll b){
//     while(b>=2){
//         if(a%b == 0){
//             return a/b;
//         }
//         b--;
//     }
//     return a;
// }

void solve(){
    ll n;
    cin>>n;
    ll t = n;
    ll b = 0;
    ll ans = 0;
    vector<ll> vec;

    for(int i = 1;i * i <= n;i++){
        if(n % i == 0){
            vec.push_back(i);
            if(i * i  != n){
                vec.push_back(n / i);
            }
        }
    }
    
    sort(vec.begin(),vec.end());

    for(int i = 0;i<vec.size()- 1;i++){
        ans += (t / vec[i]) * (vec[i + 1] - vec[i]);
    }


    // for(int i = 1;i<=n;i++){
    //     if(n%i == 0){
    //         b = n/i;
    //     }
    //     // cout<<b<<" ";
    //     ans += b;
    // }
    // cout<<ans<<" "<<(ll)sqrt(n)<<endl;
    // ans += (n-(ll)sqrt(n)-2) * b + 1;
    
    cout<<ans+1<<endl;
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