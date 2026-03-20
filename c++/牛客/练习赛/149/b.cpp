#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define endl '\n'



void solve(){
    ll n,x;
    cin>>n>>x;
    vector<ll> a(n+1,0),b(n+1,0);
    for(int i = 1;i<=n;i++){
        cin>>a[i];
    }
    for(int i = 1;i<=n;i++){
        cin>>b[i];
    }
    vector<ll> di(n+1,0);
    for(int i = 1;i<=n;i++){
        di[i] = b[i] - a[i];
    }
    ll mm = 0;
    ll p = 0;
    for(int i = 1;i<=n;i++){
        ll c = a[i]- p;
        mm = max(c,mm);
        p+=di[i];
    }

    ll ans = 0;
    ll xx = x;
    if(x<mm){
        for(int i = 1;i<=n;i++){
            if(xx<a[i]){
                break;
            }
            xx+=di[i];
            ans++;
        }
        cout<<ans<<endl;
    }else{
        if(p>=0){
            cout << "Infinity"<<endl;
        }else{
            ll zu = (x-mm)/(-p) + 1;
            ans = zu*n;
            xx = x - zu * (-p);
            for (int i = 1; i <= n; i++)
            {
                if (xx < a[i])
                {
                    break;
                }
                xx += di[i];
                ans++;
            }
            cout << ans << endl;
        }
    }
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