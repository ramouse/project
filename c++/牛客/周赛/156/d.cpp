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

const ll MOD = 10000;
const ll INF = 1e18;

void solve()
{
    ll n;
    cin>>n;
    

    string s[3];
    cin>>s[0]>>s[1]>>s[2];

    if (n > 8)
    {
        cout << 0 << endl;
        return;
    }

    vector<bool> vis(8,0);
    auto check = [&](ll x, ll t) -> bool{
        for(int i = 0;i<3;i++){
            char c = ((t >> i) & 1) + '0';
            if(s[i][x] != '?' && s[i][x] != c) return false;
        }
        return true;
    };

    ll ans = 0;
    auto dfs = [&](auto &&self,ll x) -> void{
        if(x == n){
            ans++;
            return;
        }

        for(int i = 0;i<8;i++){
            if(!vis[i] && check(x,i)){
                vis[i] = 1;
                self(self,x+1);
                vis[i] = 0;
            }
        }
    };
    dfs(dfs,0);
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