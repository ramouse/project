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
    ll n,p;
    cin>>n>>p;
    ll num = 0;
    for(int i = 1;i<=n;i++){
        string s;
        cin>>s;
        // cout<<s.substr(0, s.size() - 1)<<endl;
        if (s.substr(0, s.size() - 1) == "WrongProblem")
        {
            if(s.back() >= 'A' && s.back() <= 'L'){
                num += 100;
            }
        }
        else if (s.substr(0, s.size() - 1) == "SameProblem")
        {
            if (s.back() >= 'A' && s.back() <= 'L')
            {
                num += 30;
            }
        }
        else if (s == "UnreasonableProblemArrangement")
        {
            num += 10;
        }
        else if (s.substr(0, s.size() - 1) == "UnreasonableLimitForProblem")
        {
            if (s.back() >= 'A' && s.back() <= 'L')
            {
                num += 5;
            }
        }
        else if (s.substr(0, s.size() - 1) == "WeakTestsForProblem")
        {
            if (s.back() >= 'A' && s.back() <= 'L')
            {
                num += 3;
            }
        }
        else if (s.substr(0, s.size() - 1) == "BadProblem")
        {
            if (s.back() >= 'A' && s.back() <= 'L')
            {
                num += 1;
            }
        }
    }

    // cout<<num<<endl;
    if(num > p){
        cout << "Joker"<<endl;
    }else{
        cout << "Judger"<<endl;
    }
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