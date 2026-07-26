#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define endl '\n'

const ll N = 1e9;
const ll MOD = 676767677;
const ll INF = 1e18;


void solve()
{
    ll px,py,qx,qy,rx,ry,sx,sy;
    cin>>px>>py>>qx>>qy>>rx>>ry>>sx>>sy;

    ll dx1 = qx-px;
    ll dy1 = qy - py;
    ll dx2 = sx-rx;
    ll dy2 = sy - ry;

    ll cr = dx1 * dy2 - dx2 * dy1;

    if(cr != 0){
        cout<<"Yes"<<endl;
    }else{
        ll m1 = px + qx - sx - rx;
        ll m2 = qy + py - sy - ry;

        ll dot = dx1 * m1 + dy1 * m2;
        if(dot == 0){
            cout<<"Yes"<<endl;
        }else{
            cout<<"No"<<endl;
        }
    }


}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t = 1;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}