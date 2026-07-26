#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define endl '\n'

const ll N = 1e9;
const ll MOD = 676767677;
const ll INF = 1e18;


void solve()
{
    ll h,w;
    cin>>h>>w;
    // double hh = h/100;
    if(w *100 * 100 >= 25 * h * h){
        cout<<"Yes"<<endl;
    }else{
        cout<<"No"<<endl;
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t = 1;
    // cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}