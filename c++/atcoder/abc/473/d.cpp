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

    vector<vector<int>> ans;

    // queue<tuple<int,int,vector<int>>> q;
    // for(int i = 0;i<=k;i++){
    //     vector<int> vec;
    //     vec.push_back(i);
    //     q.push({1,i,vec});
    // }

    // while(!q.empty()){
    //     auto [idx,sum,vec] = q.front();
    //     q.pop();

    //     // for (ll u : vec)
    //     // {
    //     //     cout << u << " ";
    //     // }
    //     // cout<<endl;


    //     if(sum == k){
    //         ans.pb(vec);
    //         continue;
    //     }

    //     if (idx == n)
    //         continue;

    //     for(int i = 0;i<=k;i++){
    //         if(sum + (idx + 1) * i <= k){
    //             vec.push_back(i);
    //             q.push({idx+1,sum + (idx + 1) * i,vec});
    //             vec.pop_back();
    //         }else{  
    //             break;
    //         }
    //     }
    // }

    vector<int> v;
    auto dfs = [&](auto &&self,ll sum,ll idx) -> void{
        if(idx == n+1){
            if(sum == k) ans.pb(v);
            return;
        }

        if(idx == n){
            ll rem = sum - k;
            if(rem % n != 0) return;
            v.pb(rem/n);
            self(self,k,idx+1);
            v.pop_back();
        }else{
            for (int i = 0; i <= k; i++)
            {
                if (sum + idx * i <= k)
                {
                    v.pb(i);
                    self(self, sum + idx * i, idx + 1);
                    v.pop_back();
                }
                else
                {
                    return;
                }
            }
        }

       
    };

    for(int i = 0;i<=k;i++){
        v.pb(i);
        dfs(dfs,i,2);
        v.pop_back();
    }

    sort(all0(ans),[&](const auto&x,const auto&y){
        return x<y;
    });

    for(auto vec : ans){
        ll cnt = 0;
        for(ll u : vec){
            cout<<abs(u)<<" ";
            cnt++;
        }
        if(cnt < n){
            for(int i = 1;i<=n-cnt;i++){
                cout<<0<<" ";
            }
        }
        cout<<endl;
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