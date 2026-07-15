#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define endl '\n'

const ll INF = 1e18;
const ll MAXN = 2e5 * 32;
const ll MOD = 1e9+7;

ll trie[MAXN][2];
ll cnt[MAXN];

void solve()
{   
    ll n,k1,k2;
    cin>>n>>k1>>k2;
    ll k = k1 ^ k2;
    vector<ll> a(n+1,0),b(n+1,0),c(n+1,0);
    // ll trie[MAXN][2] = {0};
    // vector<vector<ll>> trie(MAXN,vector<ll>(2,0));
    // vector<ll> cnt(MAXN,0);
    ll node = 0;
    for(int i = 1;i<=n;i++){
        cin>>a[i];
    }

    ll ans = 0;
    for(int i = 1;i<=n;i++){
        cin>>b[i];
        c[i] = a[i] ^ b[i];

        ll sum = 0;
        ll cur = 0;
        ll num = c[i];
        for(int j = 30;j>=0;j--){
            ll bit = ((num >> j) & 1);
            ll bitk = ((k>>j) & 1);

            int same = bit ^ bitk;
            int diff = same ^ 1;

            if(same){
                if(trie[cur][diff]){
                    ans += cnt[trie[cur][diff]];
                }
                cur = trie[cur][0];
            }else{
                cur = trie[cur][0];
            }

            if(!cur) break;
        }

        cur = 0;
        for(int j = 30;j>=0;j--){
            ll bit = ((num >> j) & 1);
            if(!trie[cur][bit]){
                trie[cur][bit] = ++node;
            }
            cur = trie[cur][bit];
            cnt[cur]++;
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
    {
        solve();
    }
    return 0;
}