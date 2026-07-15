#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define endl '\n'

const ll INF = 1e18;

void solve()
{   
    ll n,x,y;
    cin>>n>>x>>y;

    vector<ll> p(n+1,0);
    vector<ll> pos(n+1,0);
    for(int i = 1;i<=n;i++){
        cin>>p[i];
        pos[p[i]] = i;
    }

    ll a = abs(x-y);
    if(a == 0) a = x;
    ll b = gcd(x,y);

    for(int i = 1;i<=n;i++){
        ll t = abs(pos[i] - i);
        if(t % b == 0){
            continue;
        }else{
            // cout<<i<<" "; 
            cout<<"NO"<<endl;
            return;
        }
    }

    cout<<"YES"<<endl;
}

int main()
{
    int t = 1;
    cin >> t;
    while (t--)
        solve();
    return 0;
}