#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define endl '\n'

void solve(){
    int n;
    cin>>n;
    vector<int> a(n+1,0);
    a[n] = n;
    if(n>2){
        if(n%2!=0){
            for (int i = n - 1; i; i--)
            {
                if (i % 2 == 0)
                    a[i] = a[i + 1] - i;
                else
                    a[i] = a[i + 1] + i;
            }
        }else{
            for (int i = n - 1; i; i--)
            {
                if (i % 2 == 0)
                    a[i] = a[i + 1] + i;
                else
                    a[i] = a[i + 1] - i;
            }
        }
        
    }else a[1] = 1;
    

    for(int i = 1;i<=n;i++){
        cout<<a[i]<<" ";
    }
    cout<<endl;
}

int main(){
    int t;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}