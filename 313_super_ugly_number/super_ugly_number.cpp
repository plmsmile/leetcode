/*
 * 超级丑数
 * https://plmsmile.github.io/2017/12/29/leetcode-01/#丑数-263-264-313
 *
 * @author PLM
 * @date 2018-02-28
 */
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;


/*
 * 给定素数，返回第n个丑数
 */
int nthSuperUglyNumber(int n, vector<int>& primes) {
    if (n == 1) {
        return 1;
    }
    
    if (n <= 0 || primes.empty()) {
        return -1;
    }
    
    vector<int> u(n);
    u[0] = 1;
    vector<int> t(primes.size(), 0);
    
    for (int i = 1; i < n; ++i) {
        // 计算新的丑数，选择最小的
        int cur = INT_MAX;
        for (int j = 0; j < primes.size(); ++j) {
            cur = min(cur, u[t[j]] * primes[j]);
        }
        u[i] = cur;
        // 更新索引，向前推进
        for (int j = 0; j < primes.size(); ++j) {
            if (cur == u[t[j]] * primes[j]) {
                t[j]++;
            }
        }
    }
    return u[n-1];
}


int main() {

    return 0;
}
