#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define endl '\n'

int main(){
    ll t,n;
    cin>>t>>n;

    ll zu = t/n;
    ll sh = t%n;
    for(int i = 1;i<=n;i++){
        if(sh != 0) cout<<zu+1<<" ";
        else cout<<zu<<" ";
        if(sh  != 0) sh--;
    }
    return 0;
}