#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define endl '\n'
#define pll pair<ll, ll>
#define T tuple<ll, ll, ll>
#define all1(x) x.begin() + 1, x.end()
#define all0(x) x.begin(), x.end()
#define pb(x) push_back(x)
#define fi first
#define se second

const ll MOD = 10000;
const ll INF = 1e18;

void solve()
{
    ll n;
    cin>>n;
    vector<ll> a(n+1,0);
    for(int i = 1;i<=n;i++){
        cin>>a[i];
    }

    ll mask = (1<<31) - 1;
    auto check = [&](ll m) -> bool{
        ll prev = 0;
        ll fm = ((1<<31)-1) ^ m;
        for(int i = 1;i<=n;i++){
            ll num = a[i];
            if((fm & prev) == (fm & num)){
                continue;
            }
            ll cur = 0;
            for(int j = 30;j>=0;j--){
                if(!(fm & (1<<j))){
                    ll fixed = num & ((1<<j) - 1) & fm; //j位之后不可修改的大小
                    ll low = m & ((1<<j) - 1);  //j位之后可修改位全填1的大小
                    if(cur + fixed + low < prev){ //看当前位填0有没有可能单调不减，不能这一位就只能是1
                        cur |= (1<<j);
                    }
                }else{
                    cur |= (num & (1<<j));
                }
            }
            if(cur < prev) return false;
            prev = cur;
        }
        return true;
    };

    ll ans = 0;
    for(int i = 30;i>=0;i--){
        if(check(mask^(1<<i))){
            mask ^= (1<<i);
        }else{
            ans += (1<<i);
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