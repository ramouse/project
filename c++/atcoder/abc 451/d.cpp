#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define endl '\n'

void solve()
{
    ll n;
    cin>>n;
    vector<ll> vec;
    set<ll> a;
    for(int i = 0;i<=31;i++){
        if((1<<i)>1e9){
            break;
        }else{
            vec.push_back((1<<i));
        }
    }
    sort(vec.begin(),vec.end());
    ll t = 0;
    
    
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t = 1;
    // cin>>t;
    while(t--){
        solve();
    }
    
    return 0;
}