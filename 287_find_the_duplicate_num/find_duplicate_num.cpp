/*
 * 查找数组中重复的元素，数组有n+1个数，范围都在[1,n]中
 * https://leetcode.com/problems/find-the-duplicate-number/description/
 * https://plmsmile.github.io/2017/12/29/leetcode-01/#发现重复的数字-287
 *
 * @author PLM
 * @date 2018-01-08
 */


#include <iostream>
#include <vector>

using namespace std;


/*
 * 找到数组a中，[min, max]这些数的出现次数
 */
int count_range(const vector<int>& a, int min, int max) {
    int count = 0;
    for (int i = 0; i < a.size(); i++) {
        if (a[i] >= min && a[i] <= max) {
            count++;
        }
    }
    return count;
}


/*
 * 找到一个重复的数字
 * Args:
 *      a -- 数组，n+1个元素，范围[1,n]，至少有一个重复的数字
 * Returns:
 *      dup -- 重复的数字
 */
int find_duplicate(const vector<int>& a) {
    int n = a.size() - 1;
    if (n <= 0) {
        return 0;
    }

    int l = 1;
    int r = n;
    int dup = -1;
    // 不断缩小范围
    while (l <= r) {
        int m = (l + r) >> 1;
        // 统计[l,m]在a中的出现次数
        int count = count_range(a, l, m);
        if (l == r) {
            if (count >= 2) {
                dup = l;
                break;
            }
        }
        
        // [l, m]有重复的
        if (count > (m - l + 1)) {
            r = m;
        } 
        // [m+1, r]有重复的
        else {
            l = m + 1;
        }
    }
    return dup;
}
