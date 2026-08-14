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

const ll MOD = 998244353;
const ll INF = 1e18;

void solve()
{
    ll n,x;
    cin>>n>>x;
    vector<ll> a(n+1,0);
    priority_queue<ll> pq;
    ll sum = 0;
    for(int i = 1;i<=n;i++){
        cin>>a[i];
        sum = (sum + a[i]) % MOD;
        pq.push(a[i]);
    }
    if(x == 1){
        cout<<sum<<endl;
        return;
    }
    __int128_t cnt = 0;
    ll ans = 0;
    ll sh = 0;
    while(!pq.empty()){
        ll u = pq.top();
        pq.pop();
        // cout << cnt << endl;

        if(u % x == 0){
            cnt = (cnt + u/x);
            continue;
        }
        if((u + 1) % x == 0){
            cnt = (cnt + u / x);
            continue;
        }
        if(u > x){
            cnt = (cnt + u / x);
            pq.push(u%x);
            continue;
        }
        if(cnt + u >= x-1){
            cnt -= x - u;
            cnt++;
            continue;
        }
        ans = (ans + u) % MOD;
    }
    // cout<<cnt<<endl;
    // cout<<ans<<endl;
    // while(cnt >= x){
    //     cnt = cnt%x + cnt/x;
    // }
    // if(cnt == x-1) cnt = 0;
    // cout<<cnt<<endl;
    cnt %= (x-1);
    ans = (ans + (cnt)) % MOD;
    cout<<ans<<endl;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t = 1;
    cin >> t;
    while (t--)
        solve();
}