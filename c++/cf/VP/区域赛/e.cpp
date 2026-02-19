#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define endl '\n'



int main(){
    int n,m;
    cin>>n>>m;
    int c = 1;
    cout<<"Yes"<<endl;
    for(int i = 1;i<=n;i++){
        for(int j = 1;j<=m;j++){
            cout<<c++<<" ";
        }
        
        cout<<endl;
    }
    
    return 0;
}