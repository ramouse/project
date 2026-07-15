#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define endl '\n'

int main(){
    int n;
    cin>>n;
    vector<int> a(n,0);
    vector<int> b(n,0);
    vector<vector<int>> dp(n+1,vector<int>(2048,0));
    for(int i = 0;i<n;i++) cin>>a[i];
    for(int i = 0;i<n;i++) cin>>b[i];

    dp[0][0] = 1;
    for(int i = 0;i<n;i++){
        for(int j = 0;j<2048;j++){
            if(dp[i][j]){
                dp[i+1][max(0,j-a[i])] = 1;
                dp[i+1][j^b[i]] = 1;
            }
        }
    }

    for(int i = 2047;i>=0;i--){
        if(dp[n][i]){
            cout<<i;
            return 0;
        }
    }
    return 0;
}