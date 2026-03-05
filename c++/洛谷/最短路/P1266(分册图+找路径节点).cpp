#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define endl '\n'

const ll INF = 1e18;

struct Node{
    int to;
    int l;
    int v;
};

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n,m,d;
    cin>>n>>m>>d;
    vector<Node> adj[n];
    for(int i = 1;i<=m;i++){
        int u,v,s,l;
        cin>>u>>v>>s>>l;
        adj[u].push_back({v,l,s});
    }

    //本题的边权，也就是时间并非固定不变，所有需要再开一维来进行表示，dist[u][se]表示到达u节点且速度为se时的最短路径
    vector<vector<double>> dist(n,vector<double>(505,INF));
    priority_queue<tuple<double,ll,ll>,vector<tuple<double,ll,ll>>,greater<tuple<double,ll,ll>>> pq;
    vector<vector<int>> pre_pos(n,vector<int>(505,-1));//表示到达对应状态的上一个路口
    vector<vector<int>> pre_sp(n,vector<int>(505,-1));//表示到达对应状态的上一个速度
    pq.push({0.0,70,0});
    dist[0][70] = 0;

    while(!pq.empty()){
        auto [t,se,u] = pq.top();
        pq.pop();

        if(t>dist[u][se]) continue;

        for(auto &edge : adj[u]){
            int v = edge.to;
            int l = edge.l;
            int se1 = edge.v;
            double t1 = 0.0;
           
            if(se1 == 0){
                t1 = (double)l / se;
                se1 = se;
            }else{
                t1 = (double)l / se1;
            }
            
            if(dist[v][se1]>dist[u][se]+t1){
                dist[v][se1] = dist[u][se] + t1;
                pq.push({dist[v][se1],se1,v});
                pre_pos[v][se1] = u;
                pre_sp[v][se1] = se;
            }
        }
    }

    double minn = INF;
    vector<int> ans;
    int sp = -1;
    for(int i = 0;i<=500;i++){
        if(minn>dist[d][i]){
            minn = dist[d][i];
            sp = i;
        }
    }

    int cur_u = d;
    int cur_sp = sp;

    while(cur_u != -1){
        ans.push_back(cur_u);

        int next_u = pre_pos[cur_u][cur_sp];
        int next_sp = pre_sp[cur_u][cur_sp];

        cur_u = next_u;
        cur_sp = next_sp;
    }
    reverse(ans.begin(),ans.end());

    for(int i = 0;i<ans.size();i++){
        cout<<ans[i]<<" ";
    }

    return 0;
}