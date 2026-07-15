#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define endl '\n'

int main(){
    ll n,k;
    cin>>n>>k;
    ll ans = 0;
    k -= n;
    n++;
    if(k>0){
        while (1)
        {
            
            k -= n;
            ans++;
            if (k <= 0)
                break;
            n++;
        }
    }
    
    cout<<ans;

    return 0;
}