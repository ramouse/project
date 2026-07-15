#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define endl '\n'

const ll N = 1e9 + 5;
const ll MOD = 676767677;

void solve()
{
    ll n;
    cin>>n;

    if(n == 2){
        cout<<"2 1 1 2 2 1 2 1"<<endl;
        return;
    }

    for(int i = 1;i<=n;i++){
        cout<<i<<" "<<i<<" ";
    }
    for(int i = 1;i<=2;i++){
        for(int j = 1;j<=n-2;j++){
            cout<<j<<" ";
        }
        cout<<n<<" "<<n-1<<" ";
    }
    cout<<endl;

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