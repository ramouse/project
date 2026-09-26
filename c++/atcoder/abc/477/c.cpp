#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using i128 = __int128_t;
#define endl '\n'
#define pll pair<ll,ll>
#define T tuple<ll,ll,ll>
#define all1(x) x.begin() + 1,x.end()
#define all0(x) x.begin(),x.end()
#define pb push_back
#define fir first
#define sec second

const ll MOD = 998244353;
const ll INF = 1e18;

void solve()
{   
    ll q;
    cin>>q;
    string s,t;
    cin>>s>>t;

    ll n = t.size();


    vector<ll> matc;
    // int j = 0;
    // for (int i = 0; i < s.size(); i++)
    // {
    //     while (j > 0 && s[i] != pi[j])
    //         j = pi[j - 1];
    //     if (s[i] == pi[j])
    //         j++;
    //     if (j == s.size())
    //     {
    //         matc.push_back(i - j + 1);
    //         j = pi[j - 1];
    //     }
    // }



    for(int i = 0;i<s.size();i++){
        if(i + t.size() > s.size()) break;
        if(s.substr(i,t.length()) == t){
            matc.push_back(i);
        }
    }

    // for(ll u : matc){
    //     cout<<u<<" ";
    // }
    // cout<<endl;

    while(q--){
        ll l,r;
        cin>>l>>r;
        l--;
        r--;
        ll idx = lower_bound(all0(matc),l) - matc.begin();
        // cout<<idx<<endl;
        if(idx == matc.size()){
            cout<<"No"<<endl;
        }else{
            if(matc[idx] + n - 1 > r){
                cout<<"No"<<endl;
            }else{
                cout<<"Yes"<<endl;
            }
        }
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