#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define endl '\n'

const ll N = 1e6+5;
const ll MOD = 998244353;


void solve(){
    ll n;
    cin>>n;
    vector<ll> a(n+1,0);
    for(int i = 1;i<=n;i++){
        cin>>a[i];
    }
    vector<bool> vis(n+1,0);
    vector<ll> low(n+1,0);
    ll len = 0;

    for(int i = 1;i<=n;i++){
        if(a[i] > low[len]){
            len++;
            low[len] = a[i];
        }else{
            // ll idx = lower_bound(low.begin() + 1,low.begin() + 1 + len,a[i]) - low.begin();
            // low[idx] = a[i]; 
        }
    }

    for(ll u : low){
        vis[u] = 1;
        // cout<<u<<" ";
    }
    // cout<<endl;
    vector<ll> vec;
    vec.push_back(0);
    for(int i = 1;i<=n;i++){
        if(!vis[a[i]]){
            vec.push_back(a[i]);
            // cout<<vec.back()<<" ";
        }
    }
    // cout<<endl;

    ll len1 = 0;
    low.resize(vec.size()+1,0);
    for(int i = 1;i<vec.size();i++){
        if(vec[i] > low[len1]){
            len1++;
            low[len1] = vec[i];
        }else{
            ll idx = lower_bound(low.begin() + 1,low.begin() + 1 + len1,vec[i]) - low.begin();
            low[idx] = vec[i];
        }
    }

    cout<<len+len1<<endl;

}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t = 1;
    // cout<<'j'-'0'-'0'<<endl;
    // cin>>t;
    while(t--){
        solve();
    }
    return 0;
}