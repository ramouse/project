#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define endl '\n'

int main(){
    int n;
    cin>>n;
    vector<ll> p;
    for(int i = 0;i<1<<n;i++){
        p.push_back(i ^ i >> 1);
    }
    for(int i = 0;i<p.size();i++) cout<<p[i]<<" ";
    return 0;
}