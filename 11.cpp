#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define endl '\n'

void solve()
{
    ll s,k,m;
    cin>>s>>k>>m;
    ll ans = 0;
    if(s<=k){
        cout<<max((ll)0,s-(m%k))<<endl;
    }else{
        if((m/k) % 2 == 0) cout<<s-(m%k)<<endl;
        else cout<<k - (m%k)<<endl;
    }
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}