/*
 * 判断一个数是否是丑数
 * https://plmsmile.github.io/2017/12/29/leetcode-01/#丑数-263-264-313
 *
 * @author PLM
 * @date 2018-02-28
 */


/*
 * 判断一个数是否是丑数
 */
bool isUgly(int num) {
    // 特殊情况
    if (num <= 0) {
        return false;
    }
    if (num == 1) {
        return true;
    }
    // 不断分解2,3,5
    vector<int> a = {2, 3, 5};
    for (auto i : a) {
        while (num % i == 0) {
            num /= i;
        }
    }
    return num == 1;
}
