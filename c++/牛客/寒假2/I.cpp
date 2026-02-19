#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define endl '\n'


void solve(){
    ll n, m;
    cin >> n >> m;
    vector<vector<char>> a(n + 1, vector<char>(m + 1));
    ll one = 0,zero = 0;
    for(int i = 1;i<=n;i++){
        for(int j = 1;j<=m;j++){
            cin>>a[i][j];
            if(a[i][j] == '1') one++;
            else zero++;
        }
    }
    
    vector<vector<char>> vis(n+1,vector<char>(m+1));
    for(int i = 1;i<=n;i++){
        for(int j = 1;j<=m;j++){
            if(a[i][j] == '1' && one>1) cout<<'Y';
            else if(a[i][j] == '1' && one <=1) cout<<'N';

            if (a[i][j] == '0' && zero > 1)
                cout << 'Y';
            else if (a[i][j] == '0' && zero <= 1)
                cout << 'N';
        }
        cout<<endl;
    }

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