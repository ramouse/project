#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define endl '\n'
#define T tuple<ll, ll, ll>
#define pll pair<ll, ll>

const ll MOD = 998244353;
const ll INF = 1e18;
const ll LOG = 30;

void solve()
{
    ll x,q;
    cin>>x>>q;
    priority_queue<ll> maxx;
    priority_queue<ll,vector<ll>,greater<ll>> minn;
    maxx.push(x);

    while(q--){
        ll a,b;
        cin>>a>>b;
        if(a>maxx.top()){
            minn.push(a);
        }else{
            maxx.push(a);
        }
        if(b>maxx.top()){
            minn.push(b);
        }else{
            maxx.push(b);
        }
        while(maxx.size()>minn.size()+1){
            ll u = maxx.top();
            maxx.pop();
            minn.push(u);
        }
        while(maxx.size()<minn.size()+1){
            ll u = minn.top();
            minn.pop();
            maxx.push(u);
        }
        cout<<maxx.top()<<endl;
    }

}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t = 1;
    // cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}