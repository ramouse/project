#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n;
    cin >> n;
    vector<int> a(n);
    // 初始化全局最小值和最大值
    int min_all = 2e9, max_all = -2e9;

    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        min_all = min(min_all, a[i]);
        max_all = max(max_all, a[i]);
    }

    // 制作一个排序后的副本，用来比对哪些位置是错的
    vector<int> b = a;
    sort(b.begin(), b.end());

    int ans = 2e9; // 初始化为无穷大
    bool sorted = true;

    for (int i = 0; i < n; i++)
    {
        // 如果当前位置的数不对（需要移动）
        if (a[i] != b[i])
        {
            sorted = false;
            // 计算这个数要能动，k 最大能是多少
            // 它要么找 min_all 换，要么找 max_all 换，取两者中最远的距离
            int max_possible_k_for_this_element = max(abs(a[i] - min_all), abs(a[i] - max_all));

            // 最终的 k 必须满足所有错位数的限制，所以取最小值
            ans = min(ans, max_possible_k_for_this_element);
        }
    }

    if (sorted)
    {
        cout << -1 << "\n";
    }
    else
    {
        cout << ans << "\n";
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}