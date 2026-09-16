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
    while(cnt.find(mex) != cnt.end()){
        mex++;
    }

    map<ll,ll> ans;
    for(auto [v,c] : cnt){
        if(v < mex && c < 2){
            continue;
        }

        ll k = v + mex;//k - v = mex

        ll now = mex;

        for(ll x = mex;x<=n;x++){
            ll y = k - x;

            if(y < x && y >= 0){
                ll have = 0;
                if(cnt.find(x) != cnt.end()) have+=cnt[x];
                if(cnt.find(y) != cnt.end()) have+=cnt[y];
                if(have >= 2)
                {
                    continue;
                }else{
                    now = x;
                    break;
                }
            }else{
                ll have = 0;
                if(cnt.find(x) != cnt.end()) have+=cnt[x];
                if(cnt.find(y) != cnt.end()) have+=cnt[y];
                if(have >= 1){
                    continue;
                }else{
                    now = x;
                    break;
                }
            }
        }
        ans[k] = now;
    }


    ll q;
    cin>>q;
    ll an = 0;

    while(q--){
        ll k;
        cin>>k;
        if(ans.find(k) != ans.end()) an ^= ans[k];
        else an ^= mex;
    }


    

    cout<<an<<endl;
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