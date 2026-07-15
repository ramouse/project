#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define endl '\n'

int main(){
    int t;
    cin>>t;
    while(t--){
        ll n;
        cin>>n;
        vector<ll> a(n+1,0);
        vector<ll> diff(n+1,0);
        for(int i = 1;i<=n;i++){
            cin>>a[i];
            diff[i] = a[i] - a[i-1];
        }

        
    }
    return 0;
}