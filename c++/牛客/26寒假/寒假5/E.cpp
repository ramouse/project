#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define endl '\n'

int main(){
    int n,p;
    cin>>n>>p;
    vector<ll> a(n+1,0);
    vector<ll> pre(n+1,0);
    for(int i = 1;i<=n;i++){
        cin>>a[i];
        pre[i] = pre[i-1] + a[i];
    }

    


    return 0;
}