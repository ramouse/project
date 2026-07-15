#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define endl '\n'

struct M3{
    ll id;
    ll x;
    ll y;
    long double angle;
};

bool same_dir(const auto &a,const auto &b){ //判断是否同向且共线
    if(a.x * b.y != a.y * b.x) return false;     // 叉积为0表示共线
    if(a.x * b.x + a.y * b.y <= 0) return false; // 点积大于0表示同向（而非反向）
    return true;
}

int main(){
    ll n,q;
    cin>>n>>q;
    vector<M3> m3(n+1);

    for(int i = 1;i<=n;i++){
        m3[i].id = i;
        cin>>m3[i].x>>m3[i].y;
        m3[i].angle = atan2l(m3[i].y,m3[i].x);
    }

    sort(m3.begin()+1,m3.end(),[](auto &a,auto &b){ //按角度值降序排序
        return a.angle<b.angle;
    });

    vector<ll> group; //将排序后的怪物统计进不同方向的组中
    vector<ll> id_to_group(n+1,0); //对应id的怪物在哪个组

    ll cur = 1;
    group.push_back(0); //因为是1-base所以添加一个0
    group.push_back(1);
    id_to_group[m3[1].id] = 1;

    for(int i = 2;i<=n;i++){//如果后一个和当前的在同一方向上，对应的group++，否则再开一组
        if(same_dir(m3[i],m3[i-1])){
            group[cur]++;
        }else{
            cur++;
            group.push_back(1);
        }
        id_to_group[m3[i].id] = cur;
    }

    vector<ll> pre(n+2,0); //前缀和统计
    for(int i = 1;i<=cur;i++){
        pre[i] = pre[i-1] + group[i];
    }

    while(q--){
        ll a,b;
        cin>>a>>b;
        if(id_to_group[a] >= id_to_group[b]){
            cout<<pre[id_to_group[a]] - pre[id_to_group[b] - 1]<<endl;
        }else{
            cout<<pre[id_to_group[a]] + pre[cur] - pre[id_to_group[b] - 1]<<endl;
        }
    }
}