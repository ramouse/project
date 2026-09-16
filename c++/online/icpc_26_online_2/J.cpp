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
    bool ok1 = false,ok2 = false,ok3 = false,ok4 = false,ok5 = false;
    char c1,c2,c3,c4,c5;
    for(int i = 1;i<=n;i++){
        string s;
        cin>>s;
        if (s.substr(0, s.size() - 1) == "WrongProblem")
        {
            if(!ok1 && s.back() >= 'A' && s.back() <= 'L'){
                ok1 = true;
                num+=100;
                c1 = s.back();
            }else if(ok1){
                if(s.back() == c1){
                    num+=100;
                }
            }
        }
        else if (s.substr(0, s.size() - 1) == "SameProblem")
        {
            if (!ok2 && s.back() >= 'A' && s.back() <= 'L')
            {
                ok2 = true;
                num += 30;
                c2 = s.back();
            }
            else if(ok2)
            {
                if(s.back() == c2){
                    num += 30;
                }
            }
        }
        else if (s == "UnreasonableProblemArrangement")
        {
            num += 10;
        }
        else if (s.substr(0, s.size() - 1) == "UnreasonableLimitForProblem")
        {
            if (!ok3 && s.back() >= 'A' && s.back() <= 'L')
            {
                ok3 = true;
                num += 5;
                c3 = s.back();
            }
            else if(ok3)
            {
                if(s.back() == c3){
                    num += 5;
                }
            }
        }
        else if (s.substr(0, s.size() - 1) == "WeakTestsForProblem")
        {
            if (!ok4 && s.back() >= 'A' && s.back() <= 'L')
            {
                num += 3;
                ok4 = true;
                c4 = s.back();
            }
            else if(ok4)
            {
                if(s.back() == c4){
                    num += 3;
                }
            }
        }
        else if (s.substr(0, s.size() - 1) == "BadProblem")
        {
            if (!ok5 && s.back() >= 'A' && s.back() <= 'L')
            {
                ok5 = true;
                num += 1;
                c5  = s.back();
            }
            else if(ok5)
            {
                if(s.back() == c5){
                    num += 1;
                }
            }
        }
    }

    cout<<num<<endl;
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