#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define endl '\n'

void solve(){
    ll n,m,k;
    cin>>n>>m>>k;
    ll num = n*m;

    vector<vector<ll>> pos(n,vector<ll>(m,0));

    ll index = 0;
    if(k!=0){
        for (int i = 1; i <= n - 2; i += 2)
        {
            for (int j = 1; j <= m - 2; j += 2)
            {
                pos[i][j] = num;
                num--;
                index++;
                if (index == k)
                    break;
            }
            if (index == k)
                break;
        }
    }
    

    if(index < k && k != 0){
        cout<<"No"<<endl;
        return;
    }else cout<<"Yes"<<endl;

    ll nu = 1;
    for(int i = 0;i<n;i++){
        for(int j = 0;j<m;j++){
            if(pos[i][j] != 0) cout<<pos[i][j]<<" ";
            else cout<<nu++<<" ";
        }
        cout<<endl;
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
