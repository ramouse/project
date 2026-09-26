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
    ll k;
    vector<ll> a(7,0);
    vector<ll> b(7,0);
    vector<ll> vec;
    vec.push_back(1);
    ll sum1 = 0;
    for(int i = 1;i<=6;i++){
        cin>>a[i];
        b[i] = a[i] + 1;
        vec.pb(b[i]);
        sum1 += b[i];
    }
    sort(all1(a));
    sort(all0(vec));


    cin >> k;
    vec.erase(unique(all0(vec)),vec.end());

    // for (ll u : vec)
    // {
    //     cout << u << " ";
    // }
    // cout << endl;

    if(sum1 == k){
        cout<<"YES"<<endl;
        for(int i = 1;i<=6;i++){
            cout<<b[i]<<" ";
        }
        return;
    }

    vector<ll> temp(7,0);

    bool ok = false;
    auto dfs = [&](auto &&self,ll index,ll val) -> void{
        if(ok) return;
        if(index == 7){
            ll sum = 0;
            for(int i = 1;i<=6;i++){
                sum += temp[i];
            }

            if(sum <= k){
                // for(int i = 1;i<=6;i++){
                //     cout<<temp[i]<<" ";
                // }
                // cout<<endl;
                ll cnt = 0;
                bool ok1 = true;
                for(int i = 1;i<=6;i++){
                    for(int j = 1;j<=6;j++){
                        if(temp[i] > a[j]) cnt++;
                    }
                }

                if(cnt >= 19 && ok1){
                    ok = true;
                    ll sh = k - sum;
                    temp[6] += sh;
                    cout<<"YES"<<endl;
                    for(int i = 1;i<=6;i++){
                        cout<<temp[i]<<" ";
                    }
                    cout<<endl;
                }
            }
            return;
        }


        for(int i = 0;i<vec.size();i++){
            temp[index] = vec[i];
            val += vec[i];
            self(self,index+1,val);
        }
    };

    dfs(dfs,1,0);

    if(!ok){
        cout<<"NO"<<endl;
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