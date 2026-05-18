#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define endl '\n'

const ll N = 1e9+5;

void solve(){
    ll n;
    cin>>n;

    if(n==1){
        cout<<-1<<endl;
        return;
    }
    ll ans = n / 3;
    ll sh = n % 3;
    if (sh == 1)
    {
        ans--;
    }
    if (ans == 0)
        ans = -1;
    cout << ans << endl;
    // if(n != 1){
    //     cout<<vec.size()<<endl;
    // }else{
    //     cout<<-1<<endl;
    // }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t = 1;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}