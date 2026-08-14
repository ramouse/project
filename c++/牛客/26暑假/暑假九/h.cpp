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
    ll n;
    cin>>n;
    vector<ll> a(n+1,0);
    bool ok = false;
    ll odd = -1, even = -1;
    ll cntj = 0,cnto = 0;
    for(int i = 1;i<=n;i++){
        cin>>a[i];
        if(a[i] & 1){
            odd = max(odd,a[i]);
            cntj++;
        }else{
            cnto++;
            even = max(even,a[i]);
        }
    }

    if(cntj == 0){
        cout<<even/2<<endl;
        return;
    }
    if(cntj & 1){
        cout<<max(even,odd+1)/2<<endl;
    }else{
        cout<<max(odd-1,even)/2<<endl;
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