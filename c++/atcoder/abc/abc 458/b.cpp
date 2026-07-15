#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define endl '\n'
#define T tuple<ll, ll, ll>
#define pll pair<ll, ll>

const ll MOD = 998244353;
const ll INF = 1e18;
const ll LOG = 30;

void solve()
{
    int h,w;
    cin>>h>>w;
    if(h==1&&w==1){
        cout<<0<<endl;
        return;
    }
    if(h == 1){
        for(int i = 1;i<=w;i++){
            if(i!=1&&i!=w){
                cout<<2<<" ";
            }else{
                cout<<1<<" ";
            }
        }
        return;
    }
    if(w == 1){
        for(int i = 1;i<=h;i++){
            if(i!=1&&i!=h){
                cout<<2<<endl;
            }else{
                cout<<1<<endl;
            }
        }
        return;
    }
    for(int i = 1;i<=h;i++){
        for(int j = 1;j<=w;j++){
            if((i == 1 && j == 1) || (i == 1 && j == w) || (i == h && j == 1) || (i == h && j == w)){
                cout<<2<<" ";
            }else if(i == 1 || j == 1 || i == h || j == w){
                cout<<3<<" ";
            }else{
                cout<<4<<" ";
            }
        }
        cout<<endl;
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t = 1;
    // cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}