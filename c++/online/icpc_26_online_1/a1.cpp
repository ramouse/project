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
    cin >> n;

    string ans = "";
    map<ll, ll> cnt, cnt1;
    vector<ll> st;
    vector<pair<char, ll>> vec(n + 1);
    map<ll, vector<ll>> mp;
    for (int i = 1; i <= n; i++)
    {
        cin >> vec[i].first >> vec[i].second;
        if (vec[i].first == 'T')
        {
            cnt1[vec[i].second]++;
        }
        mp[vec[i].second].push_back(i);
    }

    vector<ll> next(n + 1, 0);
    for (auto [val, v] : mp)
    {
        // cout<<"val :"<<val<<endl;
        for (int i = 0; i < v.size() - 1; i++)
        {
            // cout<<v[i]<<" ";
            next[v[i]] = v[i + 1];
        }
        // cout<<v.back()<<endl;
    }

    // for(int i = 1;i<=n;i++){
    //     cout<<i<<" "<<next[i]<<endl;
    // }

    map<ll,ll> cur;

    for (int i = 1; i <= n; i++)
    {
        char c = vec[i].first;
        ll val = vec[i].second;

        while(!st.empty()){
            ll v = st.back();
            ll p = next[cur[v]];

            if(vec[p].first == 'F' || vec[p].first == '+' || p == 0){
                ans += '-';
                st.pop_back();
            }else{
                break;
            }
        }
        if(c == '+') ans += '+';
        else ans += '?';
        if(c == '+'){
            st.pb(val);
            cur[val] = i;
        }else{
            cur[val] = i;
        }
    }

    cout << ans << endl;
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