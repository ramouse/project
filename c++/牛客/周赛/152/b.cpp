#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define endl '\n'

const ll INF = 1e18;
const ll MAXN = 2e5 * 32;
const ll MOD = 1e9+7;

void solve()
{   
    ll k;
    cin>>k;

    if(k > 21){
        cout<<-1<<endl;
        return;
    }

    ll co = 0;
    for(int i = 1;i<=7;i++){
        for(int j = 1;j<=6;j++){
            if(i & 1 && co != k){
                if(j & 1){
                    cout<<'1';
                    co++;
                }else{
                    cout<<'0';
                }
            }else if(!(i & 1) && co != k){
                if(j&1){
                    cout<<'0';
                }else{
                    cout<<'1';
                    co++;
                }
            }else{
                cout<<'0';
            }
            
        }
        cout<<endl;
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