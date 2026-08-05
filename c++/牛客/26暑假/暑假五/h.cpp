#include<bits/stdc++.h> 
using ll = long long;
using namespace std;
#define endl '\n'

const ll MOD = 998244353;
const ll INF = 1e18;
const ll N = 1e5;


void solve(){
    ll n,m;
    cin>>n>>m;
    vector<ll> a(n+1,0);
    set<ll> se2,se1;
    ll ans = 0;
    for(int i = 1;i<=n-1;i++){
        cin>>a[i];
        se2.insert(a[i]);
    }
    ll sufmex = 0;
    while(se2.count(sufmex)){
        sufmex++;
    }

    ll permex = 0;
    for(int i = 1;i<=n;i++){
        se1.insert(a[i]);
        se2.erase(a[i]);
        if(a[i] == sufmex-1){
            sufmex--;
            while(se2.count(sufmex)){
                sufmex++;
            }
        }

        while(se1.count(permex)){
            permex++;
        }

        if(min(permex,sufmex) == a[i]){
            ans = (ans + 1) % MOD;
        }

    }

    cout<<ans<<endl;
}

int main( )
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t = 1;
    // cin>>t;
    while(t--) solve();
    
    return 0;
}