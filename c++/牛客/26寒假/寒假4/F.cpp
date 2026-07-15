#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define endl '\n'

int main(){
    int t;
    cin>>t;
    while(t--){//将少的均匀的插入到多的里
        int a,b;
        cin>>a>>b;
        int n = a+b;
        string ans = "";
        if(a >= b){
            int k = a / (b + 1);
            int x = a % (b + 1);
            for(int i = 1;i<=b+1;i++){
                ans += string(k+(x>0),'0'); //将多的插到里面
                x--;
                if(i<=b) ans += '1';
            }

        }else{
            int k = b/(a+1);
            int x = b % (a+1);
            for(int i = 1;i<=a+1;i++){
                ans+=string(k+(x>0),'1');
                x--;
                if(i<=a) ans+='0';
            }
        }
        cout<<ans<<endl;
    }
    
    return 0;
}