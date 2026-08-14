#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define endl '\n'
#define pll pair<ll, ll>
#define T tuple<ll, ll, ll>
#define all1(x) x.begin() + 1, x.end()
#define all0(x) x.begin(), x.end()
#define pb(x) push_back(x)
#define fir first
#define sec second

const ll MOD = 10000;
const ll INF = 1e18;

void solve()
{
    ll n,q,x;
    cin>>n>>q>>x;
    vector<ll> a(n+1,0);
    vector<ll> vec(n+1,0);
    ll sum = 0;
    vector<ll> pre(n+1,0);
    for(int i = 1;i<=n;i++){
        cin>>a[i];
        vec[i] = abs(a[i] - x);
        sum+=vec[i];
    }
    sort(all1(vec));

    for(int i = 1;i<=n;i++){
        pre[i] = pre[i - 1] + vec[i];
    }
    

    while(q--){
        ll k;
        cin>>k;
        if(sum <= k){
            cout<<0<<endl;
        }else{
            auto idx = upper_bound(all1(pre),k);
            cout<<n - distance(pre.begin()+1,idx)<<endl;
        }
    }


}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t = 1;
    // cin >> t;
    while (t--)
        solve();
}