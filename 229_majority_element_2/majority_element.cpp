/*
 * 查找所有的主元素，出现次数超过n/3
 * https://plmsmile.github.io/2017/12/29/leetcode-01/#主元素2-229
 *
 * @author PLM
 * @date 2018-01-31
 */

#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;


void show(vector<int>& nums) {
    for_each(nums.begin(), nums.end(), [](int n){
        cout << n << " ";
    });
    cout << endl;
}


/*
 * 查找出现次数超过n/3的元素
 * Args:
 *      nums -- 数组
 * Returns:
 *      res -- 超过n/3的元素
 */
vector<int> majority_element(const vector<int>& nums) {
    vector<int> res;
    if (nums.empty()) {
        return res;
    }
    
    // 1. 找到出现次数最多的两个数
    int n1 = 0, c1 = 0;
    int n2 = 0, c2 = 0;

    for (int n : nums) {
        if (n == n1) {
            c1++;
        } else if (n == n2) {
            c2++;
        } else if (c1 == 0) {
            n1 = n;
            c1 = 1;
        } else if (c2 == 0) {
            n2 = n;
            c2 = 1;
        } else {
            c1--;
            c2--;
        }
    }

    c1 = 0, c2 = 0;
    // 2. 重新计算出现次数
    for (auto n : nums) {
        if (n1 == n) {
            c1++;
        } else if (n2 == n) {
            c2++;
        }
    }

    // 3. 把出现次数超过n/3的数字放到res里面
    if (c1 > nums.size() / 3) {
        res.push_back(n1);
    }
    if (n2 != n1 && c2 > nums.size() / 3) {
        res.push_back(n2);
    }

    return res;
}


void test_majority_element() {
    vector<int> nums{2, 2, 1, 3};
    vector<int> res = majority_element(nums);
    show(res);
}


int main() {
    test_majority_element();
    return 0;
}
