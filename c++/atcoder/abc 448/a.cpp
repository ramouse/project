#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define endl '\n'

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n,x;
    cin>>n>>x;
    // vector<int> a(n+1,0);
    int a;
    for(int i = 1;i<=n;i++){
        cin>>a;
        if(a<x){
            cout<<1<<endl;
            x = a;
        }else{
            cout<<0<<endl;
        }
    }
    return 0;
}