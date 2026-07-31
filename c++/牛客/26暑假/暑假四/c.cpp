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
    vector<vector<ll>> vec(n+1,vector<ll>(m+1,0));
    vector<string> s(n+1);
    vector<vector<ll>> has(m+1);//hang  R
    vector<ll> lie(m + 1, 0);
    vector<ll> val(n+1,0);//hang val
    vector<vector<ll>> suf(n+1,vector<ll>(m+2,0));
    for(int i = 1;i<=n;i++){
        for(int j = 1;j<=m;j++){
            cin>>vec[i][j];
            val[i] += vec[i][j];
        }
        for(int j = m;j>=1;j--){
            suf[i][j] = suf[i][j+1] + vec[i][j];
        }
        cin>>s[i];
        for(int j = 0;j<s[i].length();j++){
            if(s[i][j] == 'R') has[i].push_back(j+1),lie[i]++;
        }
    }




    vector<bool> vis(m+1,0);//lie
    vector<bool> vvis(n+1,0);//hang
    ll ans = 0;
    for(int i = 1;i<=m;i++){

        ll cur = 0;
        vector<pair<ll,ll>> v;
        for(int j = 1;j<=n;j++){
            if(!vvis[j]) v.push_back({suf[j][i+1],j});
        }
        sort(v.begin(),v.end(),greater<pair<ll,ll>>());

        ll idxx = -1;
        for(auto [vv,idx] : v){
            for(ll u : has[idx]){
                if(lie[u] > cur){
                    
                }
            }
        }
        
    }


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