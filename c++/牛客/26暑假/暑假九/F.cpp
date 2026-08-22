#include <bits\stdc++.h>
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define debug(x) cout << #x ": " << x << endl
using namespace std;
typedef long long ll;
typedef pair<ll, ll> PII;
const ll mod = 1e9 + 7;
//const ll mod = 998244353;
const ll awa = 1e6 + 5;
const ll INF = 1e18;
struct node
{
    ll l,r,s,t,T,f;
};
//l,r:当前块的左右边界
//s:当前块的边长
//t:当前块填满一条对角线所需要的时间（更快填满那条）
//T:当前块完全填满所需时间 计算公式T=t+s-1
//f:当前块上一次合并时合并的方向
void solve()
{
    ll n; cin>>n;
    ll m=0;// 当前有m个独立的块
    vector<node> a(n+1);
    ll flag=0;// <--1  0-->  flag==1时代表这次合并是向左合并，==0则是向右下
    auto work=[&](ll f)
    {
        node x,y,z;//当前块，上一个块，合并出来的新块
        x=a[m],y=a[m-1];
        z.l=min(x.l,y.l);
        z.r=max(x.r,y.r);
        ll u,v;
        //如果合并方向就是顺沿更快填满那条对角线，那么新块就的t就是填满对角线即可
        //否则就是需要填满另一个对角线，也就是整个都填满
        //然后取max就是新块填对角线所需时间
        if(f==x.f) u=x.t; else u=x.T;
        if(f==y.f) v=y.t; else v=y.T;
        z.t=max(u,v);
        z.s=x.s+y.s;
        z.T=z.t+z.s-1;
        z.f=f;
        m--;
        a[m]=z;
    };
    for(ll i=1;i<=n;i++)
    {
        ll x; cin>>x;
        m++;//每次新来一列都记为一个新的块
        a[m].l=x,a[m].r=x,a[m].s=1,a[m].t=0,a[m].T=0,a[m].f=0;
        while(m>1)//while循环一直往前处理
        {
            if(a[m].l-1==a[m-1].r) flag=0;
            else if(a[m].r+1==a[m-1].l) flag=1; //判断能否合并，得出合并方向
            else break;
            work(flag); //处理合并
        }
    }
    if(m!=1) cout<<-1<<endl;//不能合并到第一个块就是-1
    else cout<<a[m].T<<endl;//可以合并则m==1
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    ll T = 1;
    //cin >> T;
    while (T--)
    {
        solve();
    }
    return 0;
}