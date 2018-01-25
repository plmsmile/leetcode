/*
 * n皇后的排列方法
 * https://plmsmile.github.io/2017/12/29/leetcode-01/#n皇后问题-051
 *
 * @author PLM
 * @date 2018-01-25
 */


#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
#include <iterator>
#include <stdio.h>

using namespace std;

template <typename T>
void show(const vector<T> v) {
    for_each(v.begin(), v.end(), [](string i){
        cout << i << endl;
    });
    cout << endl;
}


/*
 * 检查第t行的皇后放在第i个位置，是否可行
 * Args:
 *      t -- 第t行，从0开始
 *      k -- 放在第k个列，从0开始
 *      path -- 当前的路径，[0,t-1]行已经放好
 * Returns:
 *      true or false
 */
bool legal(int t, int k, const vector<int>& path) {
    for (int i = 0; i <= t - 1; i++) {
        // 1. 不能和之前的在同一列
        if (path[i] == k) {
            return false;
        }
        // 2. 不能在主对角线上
        if (t - i == k - path[i]) {
            return false;
        }
        
        // 3. 不能在副对角线上
        if (t + k == i + path[i]) {
            return false;
        }
    }
    return true;
}


/*
 * dfs，设置t行的皇后位置
 * Args:
 *      t -- 第t行，从0开始
 *      n -- n皇后
 *      path -- 当前的路径方案
 *      res -- 总的方案
 * Returns:
 *      None
 */
void dfs(int t, int n, vector<int>& path, vector<vector<int>>& res) {
    if (t == n) {
        res.push_back(path);
        return;
    }
    // 前面t-1行已经ok，再后面的t-n个选择中选择遍历t
    for (int i = t; i < n; i++) {
        if (legal(t, path[i], path) == true) {
            swap(path[i], path[t]);
            dfs(t + 1, n, path, res);
            swap(path[i], path[t]);
        }
    }
}


/*
 * 返回n皇后的解法
 */
vector<vector<string>> solveNQueens(int n) {
    // 1. 获得所有可能的位置
    vector<vector<int>> locations;
    vector<int> path(n);
    std::iota(path.begin(), path.end(), 0);
    dfs(0, n, path, locations);
    
    // 2. 构造返回结果
    vector<vector<string>> res;
    for (auto loc : locations) {
        vector<string> solu;
        for (int i : loc) {
            string line(n, '.');
            line[i] = 'Q';
            solu.push_back(line);
        }
        res.push_back(solu);
    }
    show(res[0]);
    
    return res;
}


int main() {
    solveNQueens(4);
    return 0;
}
