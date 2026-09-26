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
    string s;
    cin>>s;

    ll len = s.length() + 1;
    ll len1 = len;
    ll n = 1;
    while(len1--){
        n *= 10;
    }
    vector<ll> prime;
    vector<int> vis(n+1,0);

    vis[1] = 1;
    for(int i = 2;i<=n;i++){
        if(!vis[i]){
            prime.push_back(i);
        }
        for(int j = 0;j<prime.size();j++){
            ll p = prime[j];
            if(i * p > n) break;

            vis[i * p] = true;
            if(i % p == 0) break;
        }
    }

    bool ok = false;
    for(ll u : prime){
        string t = to_string(u);
        if(t.length() != len - 1){
            continue;
        }

        bool ok1 = true;
        map<char,char> mp;
        vector<int> vis(10,0);
        for(int i = 0;i<len-1;i++){
            if(mp.find(s[i]) == mp.end() && vis[t[i] - '0'] == 0){
                mp[s[i]] = t[i];
                vis[t[i] - '0'] = 1;
            }else if(mp[s[i]] != t[i]){
                ok1 = false;
                break;
            }
        }

        if(ok1){
            cout<<t<<endl;
            ok = true;
            break;
        }
    }

    if(!ok){
        cout<<-1<<endl;
    }

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