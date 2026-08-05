#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define endl '\n'

const ll MOD = 10000;
const ll INF = 1e18;

struct Node
{
    ll lx, ly, rx, ry;
};

void solve()
{
    ll n;
    cin>>n;
    vector<ll> vec(n+1,0);
    for(int i = 1;i<=n;i++){
        cin>>vec[i];
    }   

    vector<ll> v = vec;
    vec = v;
    
    sort(v.begin() + 1,v.end());
    v.erase(unique(v.begin() + 1,v.end()),v.end());
    map<ll,ll> mp;
    for(int i = 1;i<v.size();i++){
        mp[v[i]] = i;
    }

    vector<ll> cnt(n+1,0);
    vector<vector<ll>> p(n+1);
    for(int i = 1;i<=n;i++){
        cnt[mp[vec[i]]]++;
        p[mp[vec[i]]].push_back(i);
    }


    ll len = v.size()-1;

    vector<ll> ans(n+1,0);
    ll cur = 0;
    ll maxx = 0;
    // cout<<len<<endl;
    if(len >= 1){
        if(v[1] != 0){
            cout<<-1<<endl;
            return;
        }
    }
    ll last = 0;
    for(int i = 2;i<=len;i++){
        if((v[i] - v[i-1])% cnt[i-1] != 0 ){
            cout<<-1<<endl;
            return;
        }else{
            // cout<<v[i]<<" "<<cur<<" "<<cnt[i]<<endl; 
            ll val = (v[i] - v[i-1])/cnt[i-1];
            if(val < last){
                cout<<-1<<endl;
                return;
            }
            last = val;
            for (ll idx : p[i-1])
            {
                ans[idx] = val;
                maxx = max(maxx,val);
            }
            cur+=v[i];
        }
        
    }


    for(ll idx : p[len]){
        ans[idx] = maxx+1;
    }

    for(int i = 1;i<=n;i++){
        cout<<ans[i]<<" ";
    }
    cout<<endl;

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