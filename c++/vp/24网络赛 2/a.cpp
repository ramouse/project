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
    ll n,k;
    cin>>n>>k;

    vector<ll> c(k+1,0);
    for(int i = 1;i<=k;i++){
        cin>>c[i];
    }
    ll minn = *min_element(all1(c));

    vector<pair<ll,string>> vec(n+1);
    map<string,vector<ll>> mp;
    for(int i = 1;i<=n;i++){
        ll val;
        cin>>val;
        string t;
        cin>>t;
        vec[i] = {val,t};
        mp[t].pb(val);
    }

    ll kindteam = mp.size();

    set<ll> se;
    for(auto &[s,ve] : mp){
        sort(all0(ve), greater<ll>());
        for(int i = 0;i<min((ll)ve.size(),minn);i++){
            se.insert(ve[i]);
        }
    }

    // for(ll u : se){
    //     cout<<u<<" ";
    // }
    // cout<<endl;

    vector<ll> ans(n+1,0);
    ll m = minn * kindteam;

    for(int i = 1;i<=n;i++){
        string team = vec[i].second;
        ll val = vec[i].first;

        vector<ll> ve = mp[team];
        ll k = 0;
        if(se.count(val)){
            se.erase(val);
            k = val;
        }
        else{
            se.erase(ve[0]);
            k = ve[0];
        }

        // for(ll u : se){
        //     cout<<u<<" ";
        // }
        // cout<<endl;

        vector<ll> v;
        v.pb(0);
        for(ll u : se){
            v.pb(u);
        }

        auto idx = upper_bound(all1(v),val);
        // cout<<"idx: "<<idx - v.begin()<<endl;
        if(idx == v.end()) cout<<1<<endl;
        else cout<<se.size() - (idx - v.begin()) + 2<<endl;
        // for (int j = 0; j < min((ll)ve.size(), minn); j++)
        // {
        //     se.insert(ve[j]);
        // }
        se.insert(k);
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