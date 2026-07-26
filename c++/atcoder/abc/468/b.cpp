#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define endl '\n'

const ll N = 1e6+5;
const ll MOD = 676767677;

void solve(){
    ll m,d;
    cin>>m>>d;
    string s;
    cin>>s;
    ll n = s.length();
    s = " " + s;
    ll ans = 0; 
    for(int i = 1;i<=n;i++){
        if(s[i] == '.'){
            bool ok = true;
            for(int j = i-1;j>=max(1LL,i-d);j--){
                if(s[j] == 'G'){
                    ok = false;
                    break;
                }
            }

            for(int j = i+1;j<=min(n,i+d);j++){
                if(s[j] == 'G'){
                    ok = false;
                    break;
                }
            }
            if(ok) ans++;
        }
    }

    cout<<ans<<endl;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t = 1;
    // cin>>t;
    while(t--){
        solve();
    }
    return 0;
}