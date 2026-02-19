#include<bits/stdc++.h>
using namespace std;

int Count(string s,string t){
    int dp[t.length()+1] = {0};
    dp[0] = 1;
    for(int i = 0;i<s.length();i++){
        for(int j = t.length();j;j--){
            if(s[i] == t[j-1]){
                dp[j] += dp[j - 1]; 
                // dp[j] 的含义是：目标字符串 T 的“前 j 个字符”在当前扫描过的 S 中作为子序列出现了多少次。
            }
        }
    }
    return dp[t.length()];
}

int main(){
    string s;
    cin>>s;
    vector<pair<string,int>> a(5);
    a[0].first = "HUST";
    a[0].second = Count(s,"HUST");
    a[1].first = "WHU";
    a[1].second = Count(s,"WHU");
    a[2].first = "WHUT";
    a[2].second = Count(s,"WHUT");
    a[3].first = "HZAU";
    a[3].second = Count(s,"HZAU");
    a[4].first = "CCNU";
    a[4].second = Count(s,"CCNU");
    sort(a.begin(),a.end(),[](auto &x,auto &y){
        if(x.second == y.second) return x.first < y.first;
        else return x.second > y.second;
    });
    cout<<a[0].first<<" "<<a[0].second;
    return 0;
}