#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define endl '\n'

void solve(){
    ll n;
    cin>>n;

    vector<ll> p;
    for(int i = 2;i * i<=n;i++){
        while(n%i == 0){
            p.push_back(i);
            n/=i;
        }
    }

    if(n > 1) p.push_back(n);

    ll a = p.size();
    p.erase(unique(p.begin(),p.end()),p.end());
    ll m = p.size();

    cout<<a + m -1<<endl;
}


int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t = 1;
    cin>>t;
    while(t--) solve();
    return 0;
}