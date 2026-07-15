#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define endl '\n'

int main(){
    int n;
    cin>>n;
    for(int i = 1;i<=n;i++){
        for(int j = 1;j<=n;j++){
            if(i == 1) cout<<'0';
            else if(i % 2 == 0 && ((j < i && j %2 == 0) || j>=i )) cout<<'1';
            else if(i % 2 == 0 && j<i && j %2 != 0)cout<<'0';
            else if(i%2 != 0 && j<i && j%2==0) cout<<'1';
            else cout<<'0';
        }
        cout<<endl;
    }
    return 0;
}