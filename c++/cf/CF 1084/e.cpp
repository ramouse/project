#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define endl '\n'

void solve(){
    int n;
    cin>>n;
    vector<ll> a(n+1,0);
    for(int i = 1;i<=n;i++){
        cin>>a[i];
    }

    if(is_sorted(a.begin()+1,a.end())){
        cout<<"Bob"<<endl;
        return;
    }

    vector<ll> b(n+1,0);
    for(int i = 1;i<=n;i++){
        set<ll> se;
        for(int j = 2;j*j<=a[i];j++){
            while(a[i]%j == 0){
                se.insert(j);
                a[i]/=j;
            }
        }
        if(a[i]>1) se.insert(a[i]);
        if(se.size()>=2){
            cout<<"Alice"<<endl;
            return;
        }
        if(se.size() == 0) b[i] = 1;
        if(se.size() == 1) b[i] = *se.begin();
    }
    if(is_sorted(b.begin()+1,b.end())) cout<<"Bob"<<endl;
    else cout<<"Alice"<<endl;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}