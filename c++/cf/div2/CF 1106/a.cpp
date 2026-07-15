#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define endl '\n'

const ll N = 1e9;
const ll MOD = 676767677;

void solve()
{
    ll n,c;
    cin>>n>>c;
    vector<ll> a(n+1,0),b(n+1,0);
    for(int i = 1;i<=n;i++){
        cin>>a[i];
    }
    bool ok = false;
    for(int i = 1;i<=n;i++){
        cin>>b[i];
        if(b[i] > a[i]){
            ok = true;
        }
    }
    ll ans = 0;
    sort(a.begin()+1,a.end());
    sort(b.begin()+1,b.end());
    for(int i = 1;i<=n;i++){
        if(a[i] < b[i]){
            cout<<-1<<endl;
            return;
        }else{
            ans+=a[i]-b[i];
        }
    }
    if(ok) ans+=c;

    cout<<ans<<endl;
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