#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define endl '\n'
#define pll pair<ll,ll>
#define T tuple<ll,ll,ll>

// ll dx[] = {-2,-1,1,2,2,1,-1,-2};
// ll dy[] = {1,2,2,1,-1,-2,-2,-1};


const ll MOD = 998244353;
const ll INF = 1e18;

struct Node{
    ll to;
    ll w;
};

void solve()
{
    ll n,m;
    cin>>n>>m;
    priority_queue<ll> pq_a,pq_b;
    for(int i =1;i<=n;i++){
        ll t;
        cin>>t;
        pq_a.push(t);
    }
    for(int i = 1;i<=m;i++){
        ll t;
        cin >> t;
        pq_b.push(t);
    }

    ll t = 1;
    while(1){
        if(pq_a.empty()){
            break;
        }
        if(pq_b.empty()){
            break;
        }
        ll a = pq_a.top();
        ll b = pq_b.top();
        pq_b.pop();
        pq_a.pop();
        if(t&1){
            if(a<b){
                b -= a;
                pq_b.push(b);
            }
            pq_a.push(a);
            t++;
        }else{
            if(b<a){
                a -= b;
                pq_a.push(a);
            }
            pq_b.push(b);
            t++;
        }
    }
    if(pq_a.empty()){
        cout<<"Bob"<<endl;
    }else{
        cout<<"Alice"<<endl;
    }

}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t = 1;
    cin >> t;

    while (t--)
    {
        solve();
    }
    return 0;
}