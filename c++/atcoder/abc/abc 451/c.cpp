#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define endl '\n'

void solve()
{
    ll q;
    cin>>q;
    multiset<ll> se;
    while(q--){
        ll n,h;
        cin>>n>>h;
        if(n==1){
            se.insert(h);
            cout<<se.size()<<endl;
        }else{
            auto idx = se.upper_bound(h);
            
            se.erase(se.begin(),idx);
            if(se.empty()){
                cout<<0<<endl;
            }else cout<<se.size()<<endl;
        }
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(0);
    ll t = 1;
    // cin>>t;
    while(t--){
        solve();
    }
    
    return 0;
}