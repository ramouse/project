#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define endl '\n'

const ll INF = 1e18;
const ll MOD = 998244353;

struct SparseTable {
    int n;
    vector<vector<ll>> st;
    vector<int> lg;

    void init(const vector<ll>& a) {
        n = a.size();
        int max_log = __lg(n) + 1;
        st.assign(max_log, vector<ll>(n));
        lg.assign(n + 1, 0);

        for (int i = 2; i <= n; i++) lg[i] = lg[i / 2] + 1;
        for (int i = 0; i < n; i++) st[0][i] = a[i];

        for (int j = 1; j < max_log; j++) {
            for (int i = 0; i + (1 << j) <= n; i++) {
                st[j][i] = min(st[j - 1][i], st[j - 1][i + (1 << (j - 1))]);
            }
        }
    }

    ll query(int l, int r) {
        if (l > r) return INF;
        int k = lg[r - l + 1];
        return min(st[k][l], st[k][r - (1 << k) + 1]);
    }
} st_min;

void solve()
{
    ll n,m;
    cin>>n>>m;
    string s;
    cin>>s;

    vector<ll> a(n+1,0);
    vector<ll> pre(n+1,0),prema(n+2,-INF),ppre(n+1,0);
    for(int i = 1;i<=n;i++){
        cin>>a[i];
        pre[i] = (pre[i-1] + a[i]);
        ppre[i] = (ppre[i-1] + pre[i] + MOD) % MOD;
    }
    for(int i = n;i;i--){
        prema[i] = max(prema[i+1],pre[i]);
    }

    auto getpi = [&](const string& p){
        ll N = p.size() + 1;
        vector<ll> pi(N+1,0);
        for (int i = 1; i < p.size(); i++)
        {
            int j = pi[i - 1];
            while (j > 0 && p[i] != p[j])
                j = pi[j - 1];
            if (p[i] == p[j])
                j++;
            pi[i] = j;
        }

        return pi;
    };

    st_min.init(pre);
    

    auto kmp = [&](const string& p){
        vector<ll> pi = getpi(p);
        vector<ll> match;
        int j = 0;
        for(int i = 0;i<s.size();i++){
            while (j > 0 && s[i] != p[j])
                j = pi[j - 1];
            if (s[i] == p[j])
                j++;
            if (j == p.size())
            {
                match.push_back(i - j + 2);
                j = pi[j - 1]; // 继续找下一个匹配
            }
        }

        return match;
    };

    while(m--){
        string t;
        cin>>t;
        ll len = t.size();

        ll maxx = -INF;
        ll sum = 0;
        vector<ll> match = kmp(t);

        ll prel = 0;

        for(int i = 0;i<match.size();i++){
            ll curl = match[i];
            ll curr = curl+len-1;
            ll prer = prel+len-1;

            ll cntl = curl - prel;
            ll cntr = n - curr + 1;

            maxx = max(maxx,prema[curr] - st_min.query(prel,curl-1));
            sum = (sum + ((cntl * (ppre[n] - ppre[max(0LL,curr-1)] + MOD) % MOD) % MOD - cntr * (ppre[max(curl-1,0LL)] - ppre[max(prel-1,0LL)] + MOD) % MOD + MOD) % MOD) % MOD;

            prel = curl;
        }
        cout<<maxx<<" "<<sum<<endl;
    }
}

int main()
{
    int t = 1;
    // cin>>t;
    while (t--)
        solve();
    return 0;
}