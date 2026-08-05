#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define endl '\n'

const ll MOD = 10000;
const ll INF = 1e18;

struct Node
{
    ll lx, ly, rx, ry;
};

void solve()
{
    vector<ll> vec(3,0);
    cin>>vec[0]>>vec[1]>>vec[2];
    sort(vec.begin(),vec.end());
    cout<<min(vec[1] - vec[0],vec[2]-vec[1])<<endl;
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