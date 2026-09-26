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

const ll MOD = 1e9 + 7;
const ll INF = 1e18;
const ll N = 1e5;


void solve()
{
    string s;
    cin>>s;
    ll D;
    cin>>D;

    ll len = s.length();
    s = " " + s;

    static ll memo[N+1][100] = {0};
    static ll vis[N+1][100] = {0};

    auto dfs = [&](auto &&self,bool tight,bool started,ll pos,ll rem) -> ll{
        if(pos == len + 1){
            if(!started) return 0;
            return rem == 0;
        }

        if(!tight && started && vis[pos][rem]) return memo[pos][rem];

        ll res = 0;
        ll limt = tight ? s[pos] - '0' : 9;
        for(int d = 0;d <= limt;d++){
            bool ntight = tight && (d == s[pos] - '0');
            if(!started && d == 0){
                res = (res + self(self,ntight,0,pos+1,rem)) % MOD;
            }else{
                ll nrem = (rem + d) % D;
                res = (res + self(self,ntight,1,pos + 1,nrem)) % MOD;
            }
        }

        if(started){
            vis[pos][rem] = 1;
            memo[pos][rem] = res;
        }

        return res;
    };

    cout<<dfs(dfs,1,0,1,0)<<endl;

}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t = 1;
    // cin >> t; 
    while (t--){
        solve();
    }
        
}