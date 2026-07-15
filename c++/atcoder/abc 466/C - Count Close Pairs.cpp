#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define endl '\n'

const ll N = 1e9;
const ll MOD = 676767677;



void solve()
{
    ll n;
    cin>>n;

    auto ask = [&](ll f,ll s) -> bool{
        cout<<"? "<<" "<<f<<" "<<s<<endl;
        cout.flush();

        string t;
        cin>>t;
        if(t == "Yes") return true;
        else return false;
    };

    ll ans = 0;

    ll r = 2;
    for(int l = 1;l<=n;l++){
        if(r<=l) r = l+1;
        while(r<=n){
            if(ask(l,r)) r++;
            else break;
        }

        ans += r-l-1;
    }



    cout<<"! "<<ans<<endl;
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