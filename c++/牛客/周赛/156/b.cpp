#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define endl '\n'
#define pll pair<ll, ll>
#define T tuple<ll, ll, ll>
#define all1(x) x.begin() + 1, x.end()
#define all0(x) x.begin(), x.end()
#define pb(x) push_back(x)
#define fir first
#define sec second

const ll MOD = 10000;
const ll INF = 1e18;

void solve()
{
    ll n;
    cin>>n;
    string s;
    cin >> s;
    ll ans = 0;
    for(char i = 'a';i <= 'z';i++){
        string t;
        bool ok1 = false;
        for(char c : s){
            if(c == i){
                ok1 = true;
                break;
            }
        }
        if(!ok1) continue;
        for(char c : s){
            if(c != i){
                t+=c;
            }
        }

        ll l = t.length() / 2, r = (t.length() + 1) / 2;
        if(t.length() & 1){
            l = (t.length() + 1)/2;
            r = l;
        }else{
            l = t.length()/2;
            r = l + 1;
        }
        l--,r--;
        bool ok = true;
        while(l>=0 && r<t.length()){
            if(t[l] != t[r]){
                ok = false;
                break;
            }
            l--,r++;
        }
        if(ok){
            ans++;
        }
    }

    cout<<ans<<endl;
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