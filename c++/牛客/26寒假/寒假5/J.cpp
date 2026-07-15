#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define endl '\n'

int main(){
    multiset<int> set;
    vector<vector<int>> a(3,vector<int>(3,0));
    for(int i = 0;i<3;i++){
        for(int j = 0;j<3;j++){
            cin>>a[i][j];
            set.insert(a[i][j]);
        }
    }
    int hang = a[0][0]+a[0][1]+a[0][2];
    int lie = a[0][0]+a[1][0]+a[2][0];
    int dui = a[0][0] + a[1][1] + a[2][2];
    if(dui != (a[0][2] + a[1][1] + a[2][0])){
        cout<<"No";
        return 0;
    }
    int t = 0;
    for(int i = 1;i<3;i++){
        t = 0;
        for(int j = 0;j<3;j++){
            t+=a[i][j];
        }
        if(t != hang){
            cout<<"No";
            return 0;
        }
    }
    for(int i = 1;i<3;i++){
        t = 0;
        for(int j = 0;j<3;j++){
            t+=a[j][i];
        }
        if(t != lie){
            cout<<"No";
            return 0;
        }
    }

    for(int i = 1;i<=9;i++){
        if(set.count(i) > 1){
            cout<<"No";
            return 0;
        }
    }
    cout<<"Yes";
    return 0;
}