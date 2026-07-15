#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define endl '\n'

const ll INF = 1e18;
const ll N = 1e9+9;

struct Node{
    ll val;
    ll count;
    ll s;

    bool operator <(const Node& o) const{
        return val<o.val;
    }
};

void solve()
{   
    ll n;
    cin>>n;
    // vector<ll> a(n+1,0);
    map<ll,ll> fr;
    for(int i = 1;i<=n;i++){
        ll v;
        cin>>v;
        // cin>>a[i];
        fr[v]++;
    }

    // map<ll, ll> cnt;
    // map<ll, ll> num;
    // vector<ll> cnt(N,0);
    // vector<ll> num(N,0);
    vector<Node> vec;

    for(auto &[val,ccnt] : fr){
        ll cntt = 0;
        ll v = val;
        // num[v]+=ccnt;
        vec.push_back({val,ccnt,0});
        if(v == 1){
            // num[2]+=ccnt;
            // cnt[2]+=ccnt;
            vec.push_back({2,ccnt,ccnt});
        }
        while(v>1){
            if(v&1){
                ++cntt;
                ++v;
                // num[v]+=ccnt;
                // cnt[v]+=cntt*ccnt;
                vec.push_back({v,ccnt,cntt*ccnt});
            }else{
                v>>=1;
                // num[v]+=ccnt;
                ++cntt;
                // cnt[v]+=cntt*ccnt;
                vec.push_back({v,ccnt,cntt*ccnt});
            }
        }
    }
    ll ans = INF;
    ll val = -1;
    ll count = 0;
    ll sum = 0;
    sort(vec.begin(),vec.end());
    for(int i = 0;i<vec.size();i++){
        if(val != vec[i].val){
            if(count == n){
                ans = min(ans,sum);
            }
            val = vec[i].val;
            count = 0;
            sum = 0;
        }
        count+=vec[i].count;
        sum += vec[i].s;
    }
    if(count == n){
        ans = min(ans,sum);
    }

    // for(int i = 1;i<=n;i++){
    //     ll cntt = 0;
    //     num[a[i]]++;
    //     if(a[i] == 1){
    //         num[2]++;
    //         cnt[2]++;
    //     }
    //     while(a[i]>1){
    //         if(a[i]&1){
    //             cntt++;
    //             a[i]++;
    //             num[a[i]]++;
    //             cnt[a[i]]+=cntt;
    //         }else{
    //             a[i]>>=1;
    //             num[a[i]]++;
    //             cntt++;
    //             cnt[a[i]]+=cntt;
    //         }
    //     }
    // }

    // ll ans = INF;
    // for(auto &[u,v] : num){
    //     if(v == n){
    //         ans = min(ans,cnt[u]);
    //     }
    // }

    // for(auto &u : num){
    //     if(u == n){
    //         ans = min(ans,cnt[u]);
    //     }
    // }

    // for(int i = 1;i<N;i++){
    //     if(a[i] == n){
    //         ans = min(ans,cnt[i]);
    //     }
    // }

    cout<<ans<<endl;
}   

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t = 1;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}