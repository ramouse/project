#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define endl '\n'

void solve(){  //我们固定最后一位是 1 ，问题就可被转换为pi ^ i = 1 的问题
               //那么显而易见，若i为偶数，则i+1与其异或为1，若为奇数则是i-1
    ll n;
    cin>>n;
    if(n%2 == 0)
    { // 由于首位不算在内且末尾已确定为1，则若n为偶数，中间位确定后，只剩下n未排，直接放到首位
        cout<<n<<" ";
        for(int i = 2;i<=n-2;i+=2){
            cout<<i+1<<" "<<i<<" ";
        }
        cout<<1;
    }
    else
    { // 由于首位不算在内且末尾已确定为1，则若n为奇数，中间确定完后剩下n-1(偶数)和n，n^n-1=1,则n-1只能放在首位
        cout<<n-1<<" ";
        for(int i = 2;i<=n-3;i+=2){
            cout<<i+1<<" "<<i<<" ";

        }
        cout<<n<<" "<<1;
    }
    cout<<endl;
}

int main(){
    int t;
    cin>>t;
    while(t--){
        solve();
    }

    return 0;

}