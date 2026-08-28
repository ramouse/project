#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using i128 = __int128_t;
#define endl '\n'
#define pll pair<ll, ll>
#define T tuple<ll, ll, ll>
#define all1(x) x.begin() + 1, x.end()
#define all0(x) x.begin(), x.end()
#define pb push_back
#define fir first
#define sec second

const ll MOD = 998244353;
const ll INF = 1e18;

void solve()
{
    ll n,m,k;
    cin>>n>>m>>k;
    ll sum = 0;
    vector<ll> a(n+1,0);
    for(int i = 1;i<=n;i++){
        cin>>a[i];
    }

    // sum += a[1];
    queue<ll> q;
    // q.push(1);

    for(int i = 1;i<=n;i++){
        ll t = max(i - m + 1, 1LL);
        // cout<<t<<" "<<q.empty() ? 0 : q.back()<<endl;
        while (!q.empty())
        {
            // cout<<i<<" "<<q.front()<<endl;
            if(q.front() < t){
                sum -= a[q.front()];
                q.pop();
            }else{
                break;
            }
            
        }
        if(sum + a[i] <= k){
            cout<<"Yes"<<endl;
            q.push(i);
            // cout<<i<<endl;
            sum += a[i];
        }else{
            cout<<"No"<<endl;
        }
        
    }

    // while(!q.empty()){
    //     cout<<q.front()<<endl;
    //     q.pop();
    // }
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