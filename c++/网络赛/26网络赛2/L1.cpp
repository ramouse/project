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
    ll n;
    cin>>n;
    vector<ll> lie(n+1,0);
    for(int i = 0;i<n;i++){
        cin>>lie[i];
    }

    if(n == 1){
        cout<<lie[0]<<endl;
        return;
    }

    vector<ll> hang(n+1,0);
    hang[0] = lie[0];
    for(int i = 1;i<n;i++){
        hang[i] = lie[n-i];
    }
    ll ans = INF;
    ll cur = 0;
    ll minn = INF;
    ll idx = -1;
    for(int j = 0;j<n-1;j++){
        ll i = j + 1;
        ll cnt = (n -  i)/2;
        cnt = max(1LL,cnt);

        if(i == n-1){
            ans = min(ans,(cur + hang[i-1]) * 2 + hang[i]);
            break;
        }

        if((n - 1 - i) % 2 == 0){
            cur += (hang[i] + hang[i-1]) * cnt;
            cur += hang[i - 1];
            ans = min(ans,cur * 2 + hang[i]);
            // cout<<ans<<endl;
            cur -= (hang[i] + hang[i - 1]) * cnt;
            cur -= hang[i - 1];
        }else{
            cur += (hang[i] + hang[i - 1]) * cnt;
            
            ans = min(ans,cur * 2 + hang[i-1]);
            // cout<<ans<<endl;
            cur -= (hang[i] + hang[i - 1]) * cnt;
            
        }
        cur += hang[i-1];
    }

    cur = 0;
    for(int j = 0;j<n-1;j++){
        ll i = j + 1;
        ll cnt = (n  - i) / 2;
        cnt = max(1LL, cnt);

        if (i == n - 1)
        {
            ans = min(ans, (cur + lie[i - 1]) * 2 + lie[i]);
            break;
        }

        if((n - 1 - i) % 2 == 0){
            // cout<<cur;
            cur += (lie[i] + lie[i-1]) * cnt;
            cur += lie[i-1];
            ans = min(ans,cur * 2 + lie[i]);
            // cout<<" "<<cur<<" "<<ans<<endl;
            cur -= (lie[i] + lie[i - 1]) * cnt;
            cur -= lie[i - 1];
        }else{
            // cout<<cnt<<" "<<cur;
            cur += (lie[i] + lie[i-1]) * cnt;
            ans = min(ans,cur *2 + lie[i-1]);
            // cout << " " << cur << " " << ans << endl;
            cur -= (lie[i] + lie[i-1]) * cnt;
        }
        cur += lie[i-1];
    }

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