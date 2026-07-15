#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve()
{
    ll k;
    cin>>k;
    vector<ll> vec(k+1,0);
    map<ll,ll> cnt;
    bool ok = false;
    ll t = 0;
    for(int i = 1;i<=k;i++){
        cin>>vec[i];
        if(vec[i] >= 3){
            ok = true;
        }
        if(vec[i] == 2) t++;
        
    }

    if(t>=2) ok = true;

    if(ok) cout<<"Yes"<<endl;
    else cout<<"No"<<endl;
}

int main()
{
    int t = 1;
    cin>>t;
    while (t--)
        solve();
    return 0;
}