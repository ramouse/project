#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define endl '\n'

const int N = 5e5+5;

ll x[N];
ll y[N];

double gain(ll i){
    if(y[i]<=0) return 0;

    double cur = sqrt(x[i]*x[i] + y[i]*y[i]);
    double next = sqrt(x[i]*x[i] + (y[i] -1) * (y[i] - 1));
    return cur-next;
}

int main(){
    ll n,w;
    cin>>n>>w;

    priority_queue<pair<double,ll>> pq;

    double ans = 0.0;

    for(ll i = 1;i<=n;i++){
        cin>>x[i]>>y[i];
        pq.push({gain(i),i});
        ans+=sqrt(x[i]*x[i] + y[i]*y[i]);
    }

    while(w > 0 && !pq.empty()){
        auto [f,s] = pq.top();
        pq.pop();

        y[s]--;
        ans-=f;
        w--;

        if(y[s] > 0){
            pq.push({gain(s),s});
        }
    }

    printf("%.10lf",ans);
    return 0;
}