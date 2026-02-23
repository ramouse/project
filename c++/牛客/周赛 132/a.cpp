#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define endl '\n'

int main(){
    int n;
    cin>>n;
    if(n+5>=24){
        n = n+5-24;
    }else{
        n = n+5;
    }
    cout<<n<<endl;
    return 0;
}