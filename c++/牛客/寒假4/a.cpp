#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define endl '\n'

int main(){
    int n;
    cin>>n;
    vector<int> a(n+1,0);
    for(int i = 1;i<=n;i++){
        cin>>a[i];
    }
    sort(a.begin()+1,a.end());
    ll ans = 0;
    int p = ceil((n-1) * 0.8);
    for(int i = 1;i<=n;i++){
        if(a[i] >= a[p+1]){
            ans+=a[i];
        }
    }
    cout<<ans;
}