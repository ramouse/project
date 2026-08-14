#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define endl '\n'
#define pll pair<ll, ll>
#define T tuple<ll, ll, ll>
#define all1(x) x.begin() + 1, x.end()
#define all0(x) x.begin(), x.end()
#define pb(x) push_back(x)

const ll MOD = 10000;
const ll INF = 1e18;

void solve()
{
    ll n;
    cin>>n;
    vector<ll> a(n+1,0);
    map<ll,ll> cnt,ccnt;
    for(int i = 1;i<=n;i++){
        cin>>a[i];
        cnt[a[i]]++;
    }
    map<ll,vector<ll>> mp;
    cout<<"cnt: "<<endl;
    for(auto [f,s] : cnt){
        ccnt[s]++;
        mp[s].push_back(f);
        cout<<f<<" "<<s<<endl;
    }

    cout<<"ccnt: "<<endl;
    for(auto [f,s] : ccnt){
        cout<<f<<" "<<s<<endl;
    }



    ll ans = 0;
    for(auto [f,s] : ccnt){
        if(s == 1){
            ans += 2 * mp[s][0];
        }else{
            for(ll v : mp[s]){
                ans += v * s;
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
    cin >> t;
    while (t--)
        solve();
}