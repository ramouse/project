#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define endl '\n'

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    ll n,m,h;
    cin>>n>>m>>h;
    vector<ll> a(n+1,0);

    ll cnt = 0;
    while(m--){
        ll p,f;
        cin>>p>>f;

        ll j = min(f+p,n);
        
        bool ok = false;
        cnt++;
        for(int i = p;i<=j;i++){
            a[i] += max(f - abs(i-p),1LL*0);
            if(a[i]>h){
                ok = true;
            }
        }
        j = max(1LL*1,p-f);
        for(int i = p;i>=j;i--){
            if(i != p){
                a[i] += max(f - abs(i - p), 1LL * 0);
            }
            if(a[i]>h){
                ok = true;
            }
        }
        if(ok){
            cout<<"Yes"<<endl;
            cout<<cnt<<endl;
            return 0;
        }
    }
    cout<<"No";
    return 0;
}