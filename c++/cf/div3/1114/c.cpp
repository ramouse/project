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
    ll n;
    cin>>n;
    string a,b;
    cin>>a>>b;

    // ll f = 0,s = 0;
    vector<ll> f,s;
    a = " " + a;
    b = " " + b;
    ll j = 0, o = 0;
    for(int i = 1;i<=n;i++){
        if(a[i] == '1' && b[i] != 1){
            if(i & 1){
                j++;
            }else{
                o++;
            }
            f.push_back(i);
        }
        if(b[i] == '1' && a[i] != 1){
            if(i&1){
                j--;
            }else{
                o--;
            }
            s.push_back(i);
        }
    }

    if(s.size() != f.size()){
        cout<<"NO"<<endl;
        return;
    }

    if(j == 0 && o == 0){
        cout<<"YES"<<endl;
    }else{
        cout<<"NO"<<endl;
    }

    // vector<bool> vis(n+1,0);
    // for(ll u : s){
    //     bool ok = false;
    //     for(ll v : f){
    //         if(abs(u - v) % 2 == 0 && !vis[v]){
    //             vis[v] = 1;
    //             // cout<<u<<" "<<v<<" ";
    //             ok = true;
    //             break;
    //         }
    //     }
    //     if(!ok){
    //         // for(ll v : f){
    //         //     cout<<vis[v]<<" ";
    //         // }
    //         cout<<"NO"<<endl;
    //         return;
    //     }
    // }

    // cout<<"YES"<<endl;

    
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