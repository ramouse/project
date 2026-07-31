#include<bits/stdc++.h> 
using ll = long long;
using namespace std;
#define endl '\n'

const ll MOD = 998244353;
const ll INF = 1e18;
const ll N = 1e5;


void solve(){
    ll n;
    cin>>n;
    vector<ll> a(2*n+1,0);
    map<ll,ll> mp;
    for(int i = 1;i<=2*n;i++){
        cin>>a[i];
        mp[a[i]]++;
    }

    sort(a.begin() + 1,a.end());
    a.erase(unique(a.begin() + 1,a.end()),a.end());
    ll m = a.size();
    ll last = 0;
    vector<ll> vec;
    for(int i = 1;i<m;i++){
        ll cnt = mp[a[i]];
        if(cnt&1) vec.push_back(a[i]);
        if(((cnt/2)&1)) last ^= a[i];
    }

    if(vec.size() == 0){
        if(last == 0) cout<<"Menji"<<endl;
        else cout<<"Bot"<<endl;
    }else{
        if(vec.size() == 2){
            if(vec[0] == last || vec[1] == last) cout<<"Menji"<<endl;
            else cout<<"Bot"<<endl;
        }else{
            cout<<"Bot"<<endl;
        }
    }

}

int main( )
{
    int t = 1;
    cin>>t;
    while(t--) solve();
    
    return 0;
}