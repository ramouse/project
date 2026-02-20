#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define endl '\n'

void solve(){
    ll n,k;
    cin>>n>>k;
    vector<ll> a(n+1,0);
    vector<ll> nxt(n+1,0);
    ll cnt = 0;
    for(int i = 1;i<=n;i++){
        cin>>a[i];
        if(a[i]>0) cnt++;
        nxt[i] = max(nxt[i-1],a[i]+i);
    }
    if(cnt<=k){
        cout<<0<<endl;
        return;
    }


    auto check = [&](ll mid) -> bool{
        ll ans = 1;
        ll i = 1;
        ll tim = 0;
        while(i<=n && a[i] == 0){
            i++;
        }
        while(i<=n){
            tim++;
            i = nxt[i];
            if(i>=n) break;
            if(i == nxt[i]){
                while(i<=n && nxt[i] == i){
                    i++;
                }
                if(i<=n){
                    ans++;
                    tim = 0;
                }

            }else{
                if(tim == mid){
                    i++;
                    while(i<=n && a[i] == 0){
                        i++;
                    }

                    if(i<=n){
                        ans++;
                        tim = 0;
                    }
                }
            }
        }

        return ans<=k;
    };

    ll l = 1,r = n;
    while(l<=r){
        ll mid = (l+r)>>1;
        if(check(mid)){
            r=mid-1;
        }else{
            l = mid+1;
        }
    }

    if(!check(l)){
        cout<<-1<<endl;
    }else{
        cout<<l<<endl;
    }
    
    
}

int main(){
    int t;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}