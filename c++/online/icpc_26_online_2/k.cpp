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
    vector<ll> a(n+1,0);
    unordered_map<ll,ll> cnt;
    for(int i = 1;i<=n;i++){
        cin>>a[i];
        cnt[a[i]]++;
    }

    ll mex = 0;
    while(cnt[mex]){
        mex++;
    }

    unordered_set<ll> p;
    ll q;
    cin>>q;

    for (int i = 0; i < mex; i++)
    {
        cnt[i]--;
    }

    while(q--){
        ll k;
        cin>>k;
        if(!p.count(k)) p.insert(k);
        else p.erase(k);
    }

    ll ans = 0;

    for(ll k : p){
        ll t = k - mex;
        if(t < 0 || cnt[t] == 0){
            ans ^= mex;
            continue;
        }
        ll now = mex;
        vector<ll> temp;
        while(1){
            ll need = k - now;
            if(cnt[now]){
                cnt[now]--;
                temp.emplace_back(now);
                now++;
            }else if(cnt[need]){
                cnt[need]--;
                temp.emplace_back(need);
                now++;;
            }else{
                break;
            }
        }

        ans ^= now;
        for(ll u : temp) cnt[u]++;
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