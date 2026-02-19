### 定义与特性

栈 (stack)，一种后进先出的数据结构，能高效匹配括号，也能处理递归问题等

`<stack>` 容器适配器提供了一个栈的接口，它基于其他容器（如 `deque` 或 `vector`）来实现。



######特性

- 先进后出
- 只允许在栈顶则进行添加和移除操作
- 栈的元素是线性排列的
- `<stack>` 不提供直接访问栈中元素的方法，只能通过 `top()` 访问栈顶元素。



### 基本使用

1. 语法

   ```c++
   std::stack<T> st;
   st.push(x) //将元素x压入栈中
   st.top(); //返回栈顶元素，但不对其进行操作
   st.pop(); //移除栈顶元素
   st.size();
   ```
   
   





###经典匹配问题

1. [P1241 括号序列 - 洛谷](https://www.luogu.com.cn/problem/P1241?contestId=283740) //md做了好久，感觉自己跟sb一样

思路为：创建一个栈来存储字符串的位置，创建一个数组或容器来存储对应的情况，然后按对应情况输出

```c++
#include<bits/stdc++.h>
using namespace std;

int main(){
    stack<int> st;
    string s;
    cin >> s;
    int len = s.length();
    bool ok[10005];
    for (int i = 0; i < len; i++)
    {
        if (s[i] == ']')
        {
            if(st.empty()) continue;
            int k = st.top();
            if (s[k] == '[')
            {
                ok[k] = ok[i] = 1;
                st.pop();
            }
        }
        else if (s[i] == ')')
        {
            if(st.empty()) continue;
            int k = st.top();
            if (s[k] == '(')
            {
                ok[k] = ok[i] = 1;
                st.pop();
            }
        }
        else
        {
            st.push(i);
        }
    }

    for (int i = 0; i < len; i++)
    {
        if (ok[i])
            cout << s[i];
        else
        {
            if (s[i] == '(' || s[i] == ')')
                printf("()");
            else
                printf("[]");
        }
    }

    return 0;
}
```



2. [B-括号序列_牛客2025秋季算法编程训练联赛6-基础组](https://ac.nowcoder.com/acm/contest/120455/B)

思路与第一题相差不大

```c++
#include<bits/stdc++.h>
using namespace std;
using ll = long long;

void solve(){
    int n = 0;
    int ans = 0;
    stack<ll> st;
    string s;
    cin>>n;
    cin>>s;
    vector<int> v(n,0);
    for(int i = 0;i<n;i++){
        if(s[i] == ')'){
            if(st.empty()) continue;
            int k = st.top();
            if(s[k] == '('){
                v[k] = v[i] = 1;
                st.pop();
            }
        }else{
            st.push(i);
        }
    }
    
    for(auto it : v){
        if(it == 0) ans++;
    }
    
    while(1){
        if(st.empty()) break;
        else st.pop();
    }
    
    cout<<ans<<endl;
    
}



int main(){
    ll t;
    cin>>t;
    for(;t>0;t--){
        solve();
    }
    
    return 0;
}
```

