#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define endl '\n'

int main(){
    int x;
    cin>>x;
    int i = 1;
    while(1){
        if(i>100){
            cout<<"NO";
            break;
        }
        if(x == i*(i+1)){
            cout<<"YES";
            break;
        }else i++;
    }
    return 0;
}