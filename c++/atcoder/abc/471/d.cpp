#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using i128 = __int128_t;
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
    ll q,v;
    cin>>q>>v;

    multiset<ll> se;
    while(q--){
        ll op = 0;
        cin>>op;
        if(op == 1){
            ll t,w;
            cin>>t>>w;
            se.insert(w-t);
        }else{
            ll t;
            cin>>t;
            if(se.empty()){
                cout<<-1<<endl;
            }else{
                cout<<min(v,*se.rbegin() + t)<<endl;
                se.extract(*se.rbegin());
            }
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