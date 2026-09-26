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
        sum1 += b[i];
    }
    sort(all1(a));
    for(int i = 1;i<=6;i++){
        vec.push_back(a[i]);
        vec.push_back(a[i] + 1);
    }

    // for(ll u : vec){
    //     cout<<u<<" "; 
    // }
    // cout<<endl;

    cin >> k;
    if(k/6 > 0) vec.push_back(k/6);
    if(k/6  + 1> 0) vec.push_back(k/6 + 1); 

    // sort(all0(vec));
    // vec.erase(unique(all0(vec)),vec.end());

    ll n = vec.size();

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
        if(index == 6){
            ll cnt = 0;
            ll sum = 0;
            for(int i = 1;i <= 6;i++){
                sum += temp[i];
                for(int j = 1;j<=6;j++){
                    if(temp[i] > a[j]) cnt++;
                    else break;
                }
            }

            if(cnt >= 19 && sum == k){
                // cout<<val<<endl;
                // for(int i = 1;i<=6;i++){
                //     cout<<temp[i]<<" ";
                // }
                // cout<<endl;
                cout<<"YES"<<endl;
                ok = true;
                for(int i = 1;i<=6;i++){
                    cout<<temp[i]<<" ";
                }
                cout<<endl;
            }
            return;
        }

        if(index == 5){
            ll sum = 0;
            for(int i = 1;i<=5;i++){
                sum += temp[i];
            }
            if(sum < k){
                // for(int i = 1;i<=5;i++){
                //     cout<<temp[i]<<" ";
                // }
                // cout<<endl;
                temp[6] = k - sum;
                ll cnt = 0;
                for (int i = 1; i <= 6; i++)
                {
                    for (int j = 1; j <= 6; j++)
                    {
                        if (temp[i] > a[j])
                            cnt++;
                        else
                            break;
                    }
                }
                if (cnt >= 19)
                {
                    cout << "YES" << endl;
                    ok = true;
                    for (int i = 1; i <= 6; i++)
                    {
                        cout << temp[i] << " ";
                    }
                    cout << endl;
                    return;
                }
            }

            
        }

        for(int i = 0;i<n;i++){
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