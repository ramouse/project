#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define endl '\n'

ll gcd(ll a, ll b)
{
    a = abs(a);
    b = abs(b);
    if (a > b)
        swap(a, b);
    if (a == 0)
        return b;
    else
        return gcd(b % a, a);
}

void solve(){
    int n;
    cin>>n;
    vector<ll> a(n,0);
    for(int i = 0;i<n;i++){
        cin>>a[i];
    }
    bool ok = false;
    for(int i = 0;i<n;i++){
        for(int j = i+1;j<n;j++){
            if(gcd(a[i],a[j])>1){
                cout<<a[i]<<" "<<a[j]<<endl;
                return;
            }
        }
    }
    cout<<-1<<endl;
}

int main()
{
    int t;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}