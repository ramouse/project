#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define endl '\n'

const ll INF = 1e18;

void solve()
{
    ll n;
    cin>>n;
    ll maxx = 0;
    ll one = 0;
    ll tot = 0;
    ll minn = INF;
    ll cnt = 0;
    vector<ll> a(n+1,0);
    for(int i = 1;i<=n;i++){
        ll t;
        cin>>t;
        a[i] = t;
        maxx = max(maxx,t);
        if(t == 1) one++;
        else{
            tot+=a[i];
            cnt += (a[i]-2)/2;
            minn = min(minn,a[i]);
        }
    }

    if(n == 1){
        if(a[1]>=3){
            cout<<a[1]<<endl;
            return;
        }else{
            cout<<0<<endl;
            return;
        }
    }

    if(maxx == 1){
        cout<<0<<endl;
        return;
    }

    ll ans = min(one,(maxx)/2) + maxx;
    cout<<max(ans,min(one,cnt)+tot)<<endl;
   
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t = 1;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}