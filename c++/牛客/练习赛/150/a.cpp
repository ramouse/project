#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define endl '\n'
#define pll pair<ll, ll>
#define T tuple<ll, ll, ll>

// ll dx[] = {-2,-1,1,2,2,1,-1,-2};
// ll dy[] = {1,2,2,1,-1,-2,-2,-1};

const ll MOD = 998244353;
const ll INF = 1e18;

struct Node
{
    ll to;
    ll w;
};

void solve()
{
    ll n;
    cin>>n;
    priority_queue<ll> a,b;
    ll maxx_a = 0,maxx_b = 0;
    for(int i = 1;i<=n;i++){
        ll t;
        cin>>t;
        if(t&1){
            maxx_a = max(maxx_a,t);
            a.push(t);
        }else{
            maxx_b = max(maxx_b,t);
            b.push(t);
        }
    }
    cout<<max(maxx_a,maxx_b)<<" ";
    ll i = 1;
    ll t = 0;
    while(i<=n-1){
        if (b.empty())
        {
            maxx_a = 0;
        }
        else
        {
            t = b.top();
            b.pop();
            maxx_a += t;
        }

        if (a.empty())
        {
            maxx_b = 0;
        }
        else
        {
            t = a.top();
            a.pop();
            maxx_b += t;
        }
        cout << max(maxx_a, maxx_b) << " ";
        
        i++;
        
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t = 1;
    // cin >> t;

    while (t--)
    {
        solve();
    }
    return 0;
}