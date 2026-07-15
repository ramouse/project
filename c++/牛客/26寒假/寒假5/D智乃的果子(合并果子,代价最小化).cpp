#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define endl '\n'

const int MOD = 1e9+7;

int main(){
    ll n;
    cin>>n;
    ll total = 0;
    priority_queue<pair<ll,ll>,vector<pair<ll,ll>>,greater<pair<ll,ll>>> pq;

    for(int i = 1;i<=n;i++){
        ll c,w;
        cin>>c>>w;
        pq.push({w,c});
        total += c;
    }

    if(total<=1){ //如果总个数等于1，则不用合并，代价为0
        cout<<0<<endl;
        return 0;
    }

    ll ans = 0;

    while(total>=2){ //总而言之，我们发现，优先合并当前重量最小的两个总是更优的
        auto [w,c] = pq.top();
        pq.pop();
        if(c>1){ //如果当前重量下的个数大于1个
            ll p = c/2; //两两合并能合的组数
            pq.push({w*2,p}); 
            ll cost = 2*w*p%MOD;
            ans = (ans + cost) % MOD;

            if(c&1){ //如果c为奇数，则肯定会有一个剩下的没有合并，直接放回去
                pq.push({w,1});
            }
            total -= p;
        }else{ //如果当前重量下只有一个，那么我们就再拿出一组来进行合并
            auto [tw,tc] = pq.top();
            pq.pop();
            tc--;
            pq.push({w+tw,1});
            ll cost = w+tw;
            ans = (ans + cost)%MOD;

            if(tc){
                pq.push({tw,tc});
            }
            total--;
        }
    }
    cout<<ans<<endl;

    return 0;
}