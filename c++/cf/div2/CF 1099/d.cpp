#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define endl '\n'

const ll INF = 1e18;
const ll N = 1e9+9;

void solve()
{   
    ll n;
    cin>>n;
    string s;
    cin>>s;
    s = " "+s;
    vector<ll> a(n+1,0),b(n+1,0),c(n+1,0);
    for(int i = 1;i<=n;i++){
        cin>>a[i];
    }
    for(int i = 1;i<=n;i++){
        cin>>c[i];
    }

    for(int i = 1;i<n;i++){
        if(c[i] > c[i+1]){
            cout<<"No"<<endl;
            return;
        }
    }
    bool ok = true;
    vector<ll> lim(n+1,0),req(n+1,0),vis(n+1,0);
    for(int i = 1;i<=n;i++){
        lim[i] = c[i];
        if(i == 1 || c[i]>c[i-1]){
            req[i] = c[i];
            vis[i] = 1;
        }
    }

    if(s[1] == '1' && a[1] != c[1]){
        ok = false;
    }


    for(int i = n;i>=2;--i){
        if(s[i] == '1'){
            lim[i-1] = min(lim[i-1],lim[i]-a[i]);
            if (vis[i])
            {
                ll val = req[i] - a[i];
                if (vis[i - 1] && req[i - 1] != val)
                {
                    ok = false;
                    break;
                }
                else
                {
                    vis[i - 1] = 1;
                    req[i - 1] = val;
                }
            }
        }
        
    }
    for(int i = 1;i<=n;i++){
        if(vis[i] && req[i] > lim[i]){
            ok = false;
            break;
        }
    }

    if(!ok){
        cout<<"No"<<endl;
        return;
    }

    for(int i = 1;i<=n;i++){
        if(vis[i]){
            b[i] = req[i];
        }else if(s[i] == '1'){
            b[i] = b[i-1] + a[i];
        }else{
            b[i] = lim[i];
        }
    }

    for(int i = 1;i<=n;i++){
        if(b[i] > c[i]){
            cout<<"No"<<endl;
            return;
        }
    }

    cout<<"Yes"<<endl;

    for(int i = 1;i<=n;i++){
        cout<<b[i] - b[i-1]<<" ";
    }
    cout<<endl;
    
}   

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t = 1;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}