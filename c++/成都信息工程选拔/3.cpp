#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define endl '\n'

const ll MOD = 998244353;

ll qpow(ll a,ll b){
    ll res = 1;
    while(b){
        if(b&1) res = res*a%MOD;
        a = a*a%MOD;
        b/=2;
    }
    return res;
}

void solve(){
    ll n,m;
    cin>>n>>m;
    string s1,s2;
    cin>>s1>>s2;
    ll ans = 0;
    vector<ll> vec(m,0);
    for(int i = 0;i<m;i++){
        for(int j = 0;j<n;j++){
            if(s1[j] == s2[i]){
                vec[i] = j;
                break;
            }
        }
    }

    ll cur = 1;
    ll nn = n;
    for(int i = 0;i<m;i++){
        if(vec[i])
        {
            ans = (ans + vec[i]*qpow(n,n-i)%MOD)%MOD;
        }
    }
    ans = (ans + 1)%MOD;
    cout<<ans;

}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t = 1;
    // cin>>t;
    while(t--){
        solve();
    }
    return 0;
}