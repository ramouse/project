#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define endl '\n'

const ll N = 1e5+10;
//我是猪🐖
void solve()
{
    ll n,m;
    cin>>n>>m;
    vector<vector<ll>> s(n+1,vector<ll>(257,0));
    vector<vector<ll>> ce(n+1);
    vector<vector<ll>> vis(n+1,vector<ll>(257,false));
    vector<ll> tot(257,0);

    for(int i =1;i<=n;i++){
        string t;
        cin>>t;
        for(char c:t){
            s[i][c]++;
            if(!vis[i][c]){
                vis[i][c] = true;
                ce[i].push_back(c);
            }
            tot[c]++;
        }
    }

    // for(int i =1;i<=256;i++){
    //     tot[i]*=m;
    // }
    // auto check = [&](ll id,ll mid){
    //     vector<ll> h(257,0);
    //     for(int i =1;i<=n;i++){
    //         if(i != id){
    //             for (char c : ce[i])
    //             {
    //                 h[c] += mid* s[i][c];
    //                 if(h[c]>tot[c]){
    //                     return false;
    //                 }
    //             }
    //         }else{
    //             for(char c : ce[i]){
    //                 h[c]+=s[i][c];
    //                 if(h[c]>tot[c]){
    //                     return false;
    //                 }
    //             }
    //         }
            
    //     }
    //     return true;
    // };

    for(int i = 1;i<=n;i++){
        // for(auto a:ce[i]){
        //     tot[a] = tot[a] - (s[i][a]*m);
        // }

        // ll l = 0,r = m;
        ll ans = m;
        for(char c = 'A';c<='Z';c++){
            if(tot[c] == 0) continue;
            ll have = tot[c]*m-s[i][c]*m;
            ll rem = have - s[i][c];
            if(rem<0){
                ans = -1;
                break;
            }else{
                ans = min(ans, rem / (tot[c]-s[i][c]));
            }
            
            

        }
        cout<<ans<<" ";
        // while(l<=r){
        //     ll mid = (l+r)>>1;
        //     if(check(i,mid)){
        //         l=mid+1;
        //         ans = mid;
        //     }else{
        //         r = mid-1;
        //     }
        // }
        // cout<<ans<<" ";
        // for(auto a:ce[i]){
        //     tot[a] = tot[a] + (s[i][a] * m);
        // }
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