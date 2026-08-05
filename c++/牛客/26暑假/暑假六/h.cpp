#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define endl '\n'

const ll MOD = 10000;
const ll INF = 1e18;

void solve()
{
    ll n;
    cin>>n;
    if(n == 2){
        cout<<"1 2"<<endl;
        return;
    }
    bool ok = true;
    for(int i = 2;i<n-1;i++){
        if((n-1) % i == 0){
            ok = false;
            break;
        }
    }
    if(n == 3 || n == 4 || n == 6){
        cout<<"-1"<<endl;
        return;
    }
    if(n & 1 ){
        for(int i = 1;i<=n;i++){
            cout<<i<<" ";
        }
        cout<<endl;
    }else{
        if(!ok){
            for (int i = 1; i <= n; i++)
            {
                cout << i << " ";
            }
            cout << endl;
        }else{
            for (int i = 1; i <= n - 4; i++)
            {
                cout << i << " ";
            }
            cout << n << " " << n - 1 << " " << n - 2 << " " << n - 3 << endl;
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
        solve();
}