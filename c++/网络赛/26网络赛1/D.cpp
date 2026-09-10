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
const ll N = 5e5+1;


void solve()
{
    ll n;
    cin>>n;

    vector<ll> cnt(n+1,0);
    for(int i = 1;i<=n;i++){
        ll p = 0;
        cin>>p;
        cnt[p]++;
    }

    ll x = 0,y = 0;//已经有x个0，y个1
    ll ans = 1;
    for(int i = 1;i<=n;i++){
        if(x == y){
            ans = ans * 2 % MOD;
            cnt[y]--;
            x++;
        }else if(x > y){
            if(cnt[y] > 0){
                cnt[y]--;
                x++;
            }else{
                cnt[x]--;
                y++;
            }
        }else{
            if(cnt[x] > 0){
                cnt[x]--;
                y++;
            }else{
                cnt[y]--;
                x++;
            }
        }
    }

    cout<<ans<<endl;
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