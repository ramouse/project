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
    ll n;cin>>n;
    ll ans[32] ={0};
    if(n==0){cout<<"NO"<<endl;return;}
    else{
        if((n&3)==0)
        {
            cout << "NO" << endl;
            return;
        }
     

        ll t = __builtin_ctzll(n);
        ans[31] = 1;
        // ans[t] = -1;
        // cout<<t<<endl;
        for(int i = t;i<31;i++){
            if(n & (1 << (i + 1))){
                ans[i] = 1;
            }else{
                ans[i] = -1;
            }
        }

        cout << "YES" << endl;
        cout << ans[0] << " ";
        ll cnt = 1;
        for (ll i = 1; i <= 31; i++)
        {
            cnt++;
            cout << ans[i] << " ";
            if (cnt == 8)
            {
                cout << endl;
                cnt = 0;
            }
        }
    }
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