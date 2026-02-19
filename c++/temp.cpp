#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define endl '\n'

int main()
{
    int n = 5;
    int d[7] = {0}; // 差分数组，多开一些空间
    // 第一次操作：第2到第4个数加3
    d[2] += 3;
    d[5] -= 3;
    // 第二次操作：第1到第3个数加2
    d[1] += 2;
    d[4] -= 2;
    // 第三次操作：第3到第5个数加1
    d[3] += 1;
    d[6] -= 1;
    // 通过差分数组还原原数组
    int a[6] = {0};
    cout << "最终数组: ";
    for (int i = 1; i <= n; i++)
    {
        a[i] = a[i - 1] + d[i];
        cout << a[i] << " ";
    }
    cout << endl;
    return 0;
}
