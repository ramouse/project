#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define endl '\n'

const ll INF = 1e18;

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

struct MedianFinder {
    priority_queue<ll> maxp;                          // 大根堆，存较小的一半（含中位数）
    priority_queue<ll, vector<ll>, greater<ll>> minp;  // 小根堆，存较大的一半

    unordered_map<ll,int> delMax, delMin; // 分别记录两个堆各自"待懒删除"的值及次数
    ll szMax = 0, szMin = 0;              // 两个堆各自的真实（未被删除）元素个数

    // 清理 maxp 堆顶已经被标记删除的元素
    void cleanMax(){
        while(!maxp.empty()){
            auto it = delMax.find(maxp.top());
            if(it == delMax.end() || it->second == 0) break;
            it->second--;
            maxp.pop();
        }
    }
    // 清理 minp 堆顶已经被标记删除的元素
    void cleanMin(){
        while(!minp.empty()){
            auto it = delMin.find(minp.top());
            if(it == delMin.end() || it->second == 0) break;
            it->second--;
            minp.pop();
        }
    }

    // 根据真实计数 szMax / szMin 重新调整平衡
    void rebalance(){
        while(szMax > szMin + 1){
            cleanMax();
            minp.push(maxp.top()); maxp.pop();
            szMax--; szMin++;
        }
        while(szMin > szMax){
            cleanMin();
            maxp.push(minp.top()); minp.pop();
            szMin--; szMax++;
        }
        cleanMax(); cleanMin();
    }

    // 插入一个数
    void add(ll x){
        cleanMax();
        if(maxp.empty() || x <= maxp.top()){ maxp.push(x); szMax++; }
        else { minp.push(x); szMin++; }
        rebalance();
    }

    // 删除一个数（要求这个数确实存在于结构中，否则计数会出错）
    void erase(ll x){
        cleanMax(); cleanMin();
        if(!maxp.empty() && x <= maxp.top()){
            delMax[x]++; szMax--;   // 逻辑上认为 x 属于"较小的一半"
        } else {
            delMin[x]++; szMin--;   // 属于"较大的一半"
        }
        cleanMax(); cleanMin();      // 如果刚好在堆顶，立刻顺手清掉
        rebalance();
    }

    ll size() const {
        return szMax + szMin;
    }

    bool empty() const {
        return size() == 0;
    }

    // 中位数为浮点数版本（总数为偶数时取两堆堆顶均值）
    double getMedian(){
        cleanMax(); cleanMin();
        if(szMax > szMin) return (double)maxp.top();
        return (maxp.top() + minp.top()) / 2.0;
    }

    // 中位数保证是整数时使用
    ll getMedianInt(){
        if(empty()) return 0;
        cleanMax(); cleanMin();
        if(szMax > szMin) return maxp.top();
        return (maxp.top() + minp.top())/2; // 需要 /2 的话自行调整
    }

    // 若元素个数为偶数，分别取两个中位数（下中位数、上中位数）
    pair<ll,ll> getTwoMedians(){
        cleanMax(); cleanMin();
        // 调用前需保证 size() 为偶数且 size() > 0
        return {maxp.top(), minp.top()};
    }
};

void solve()
{
    ll n,m;
    cin>>n>>m;
    priority_queue<ll> maxp;
    priority_queue<ll, vector<ll>, greater<ll>> minp;
    auto add = [&](ll x){
        if(maxp.empty() || x <= maxp.top()) maxp.push(x);
        else minp.push(x);

        while(maxp.size() > minp.size() + 1){
            minp.push(maxp.top());
            maxp.pop();
        }
        while(maxp.size() < minp.size()){
            maxp.push(minp.top());
            minp.pop();
        }
    };

    ll k = 1, b = 0;
    auto pri = [&](){
        if(minp.size() == maxp.size()){
            cout<<fixed<<setprecision(10)<<(double)(minp.top() * k + b + maxp.top() * k + b)/2<<endl;
        }else{
            cout<<fixed<<setprecision(10)<<(double)(maxp.top() * k + b)<<endl;
        }
    };
   
    vector<ll> x(n+1,0);
    for(int i = 1;i<=n;i++){
        cin>>x[i];
        add(x[i]);
    }
    pri();
    




    while(m--){
        ll op;
        cin>>op;
        if(op == 1){
            ll v;
            cin>>v;
            add((v - b) * k);
        }else if(op == 2){
            ll v;
            cin>>v;
            b+=v;
        }else if(op == 3){
            ll v;
            cin>>v;
            b = 2 * v - b;
            k *= (-1);
        }
        pri();
    }
}

int main()
{
    int t = 1;
    // cin>>t;
    while (t--)
        solve();
    return 0;
}