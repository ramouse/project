#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define endl '\n'

ll n, q;
string s;
map<pair<ll,ll>,vector<ll>> ve; //存储每个坐标下对应的步数
vector<ll> px,py; //预处理每一步所到达的坐标


void solve(){
    ll l,r,x,y;
    cin>>l>>r>>x>>y;

    if(ve.count({x,y})){ //如果目标点位在l前出现，直接输出yes
        if(ve[{x,y}][0] < l){
            cout<<"Yes"<<endl;
            return;
        }
    }

    ll t_x = x + px[r] - px[l-1]; //加上目标点位在 l-r 的横向位移
    ll t_y = y + py[r] - py[l-1]; //加上目标点位在 l-r 的纵向位移

    //如果加上之后的点位，在r之后出现了，意味着回退 l-r 上的位移后，一定能到达原来的目标点位
    if(ve.count({t_x,t_y})){  
        if(ve[{t_x,t_y}].back() >r){
            cout<<"Yes"<<endl;
            return;
        }
    }
    cout<<"No"<<endl;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>n>>q;
    cin>>s;

    px.resize(n+1,0);
    py.resize(n+1,0);
    
    ve[{0,0}].push_back(0);
    ll xx = 0,yy = 0;

    for(int i = 0;i<n;i++){
        if(s[i] == 'L'){
            xx--;
        }else if(s[i] == 'R') xx++;
        else if(s[i] == 'U') yy++;
        else if(s[i] == 'D') yy--;

        ve[{xx,yy}].push_back(i+1);
        px[i+1] = xx;
        py[i+1] = yy;
    }
    while(q--){
        solve();
    }
    return 0;
}