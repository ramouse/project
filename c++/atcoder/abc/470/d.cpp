#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define endl '\n'
#define pll pair<ll, ll>
#define T tuple<ll, ll, ll>
#define all1(x) x.begin() + 1, x.end()
#define all0(x) x.begin(), x.end()
#define pb(x) push_back(x)
#define fi first
#define se second

const ll MOD = 10000;
const ll INF = 1e18;

void solve()
{
    ll n,q;
    cin>>n>>q;
    vector<ll> p(n+1,0),pos(n+1,0);
    for(int i = 1;i<=n;i++){
        cin>>p[i];
        pos[p[i]] = i;
    }

    ll cnt = 0;
    while(q--){
        ll op = 0;
        cin>>op;
        if(op == 1){
            ll x,y;
            cin>>x>>y;
            if(cnt&1){
                ll a = pos[x],b = pos[y];
                swap(p[a],p[b]);
                swap(pos[x],pos[y]);
            }else{
                ll a = p[x], b = p[y];
                swap(p[x], p[y]);
                swap(pos[a], pos[b]);
            }

        }else{
            cnt++;
        }
    }
    
    for(int i = 1;i<=n;i++){
        cout<<(cnt & 1 ? pos[i] : p[i])<<" ";
    }
    cout<<endl;
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