/*
 * 第i个丑数
 * https://plmsmile.github.io/2017/12/29/leetcode-01/#丑数-263-264-313
 *
 * @author PLM
 * @date 2018-02-28
 */

#include <algorithm>
#include <iostream>


using namespace std;


/*
 * 第n个丑数，从已有的丑数不断地向前乘得到新的丑数。
 */
int nthUglyNumber(int n) {
    if (n <= 0) {
        return -1;
    }
    if (n == 1) {
        return 1;
    }

    vector<int> u(n);
    u[0] = 1;

    int t2 = 0, t3 = 0, t5 = 0;
    // 计算丑数
    for (int i = 1; i < n; i++) {
        // 计算新的丑数，选择最小的
        int cur = min(min(u[t2] * 2, u[t3] * 3), u[t5]*5);
        u[i] = cur;
        // 更新基数索引
        if (cur == u[t2] * 2) {
            t2++;
        }
        if (cur == u[t3] * 3) {
            t3++;
        }
        if (cur == u[t5] * 5) {
            t5++;
        }
    }
    return u[n-1];
}


int main() {
    cout << min(1, 2) << endl;
    cout << min(min(1, 2), 3) << endl;
    //cout << min(1, 2, 3) << endl;

    return 0;
}
