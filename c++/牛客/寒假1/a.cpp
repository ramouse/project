#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define endl '\n'

const ll MOD = 998244353;

vector<ll> num(10, 0);

ll qpow(ll a, ll b) //快速幂
{
    ll res = 1;
    while (b != 0)
    {
        if (b % 2 == 1)
            res = res * a % MOD;
        a = a * a % MOD;
        b /= 2;
    }
    return res;
}

ll cal(ll x){ //求出四个显示器显示四位数x的概率
    if(x == 0){
        return num[0] * num[0] % MOD * num[0] % MOD * num[0] % MOD;
    }else{
        ll res = 1;
        ll len = 0;
        while(x>0){
            res = res * num[x%10] % MOD;
            x/=10;
            len++;
        }
        for(int i = 0;i<4-len;i++){ //乘上前导0的概率
            res = res * num[0] % MOD;
        }
        return res;
    }
}

void solve(){
    ll c;
    cin>>c;
    ll inv100 = qpow(100,MOD-2); //100的逆元
    vector<ll> p(8,0);
    for(int i = 1;i<=7;i++){ //在输入时直接将概率p转化为模后的概率，后续就不用多余处理
        cin>>p[i];
        p[i] = p[i] * inv100 % MOD;
    }
    vector<ll> q(8,0);
    for(int i = 1;i<=7;i++){
        q[i] = (1 - p[i] + MOD) % MOD;
    }

    //打表出每个数字显示出来的概率
    num[0] = q[4] * p[1] % MOD * p[2] % MOD * p[3] % MOD * p[7] % MOD * p[5] % MOD * p[6] % MOD;
    num[1] = p[3] * p[6] % MOD * q[1] % MOD * q[2] % MOD * q[4] % MOD * q[5] % MOD * q[7] % MOD;
    num[2] = q[2] * q[6] % MOD * p[1] % MOD * p[3] % MOD * p[4] % MOD * p[5] % MOD * p[7] % MOD;
    num[3] = q[2] * q[5] % MOD * p[1] % MOD * p[3] % MOD * p[4] % MOD * p[6] % MOD * p[7] % MOD;
    num[4] = q[1] * q[5] % MOD * q[7] % MOD * p[2] % MOD * p[3] % MOD * p[4] % MOD * p[6] % MOD;
    num[5] = q[3] * q[5] % MOD * p[1] % MOD * p[2] % MOD * p[4] % MOD * p[6] % MOD * p[7] % MOD;
    num[6] = q[3] * p[1] % MOD * p[2] % MOD * p[4] % MOD * p[5] % MOD * p[6] % MOD * p[7] % MOD;
    num[7] = p[1] * p[3] % MOD * p[6] % MOD * q[2] % MOD * q[4] % MOD * q[5] % MOD * q[7] % MOD;
    num[8] = p[1] * p[2] % MOD * p[3] % MOD * p[4] % MOD * p[5] % MOD * p[6] % MOD * p[7] % MOD;
    num[9] = p[1] * p[2] % MOD * p[3] % MOD * p[4] % MOD * q[5] % MOD * p[6] % MOD * p[7] % MOD;


    ll ans = 0;
    for(int i = 0;i<=c;i++){ //枚举每一组 a+b=c的概率
        ll a = i;
        ll b = c - a;
        ans += cal(a) * cal(b) % MOD;
        ans %= MOD;
    }
    cout<< ans  <<endl;
}

int main(){
    int t;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}