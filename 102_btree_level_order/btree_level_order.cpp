/*
 * 二叉树层次遍历
 * https://leetcode.com/problems/binary-tree-level-order-traversal/description/
 * https://plmsmile.github.io/2017/12/29/leetcode-01/#层次遍历-102
 * 
 * @author PLM
 * @date 2018-01-11
 */

#include <vector>
#include <iostream>
#include <queue>

using namespace std;


struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};


/*
 * 层次遍历二叉树，每一层放在一个vector里面
 */
vector<vector<int>> levelOrder(TreeNode* root) {
    vector<vector<int>> res;
    if (root == nullptr) {
        return res;
    }
    queue<TreeNode*> q;
    q.push(root);
    res.push_back(vector<int>());
    // 当前层，在队列里面的元素数量
    int cur_remain = 1;
    // 下一层的元素数量
    int next_level = 0;
    while (!q.empty()) {
        TreeNode* now = q.front();
        q.pop();
        // 存入队列
        res[res.size() - 1].push_back(now->val);
        
        // 左右孩子入队
        if (now->left) {
            q.push(now->left);
            next_level++;
        }
        if (now->right) {
            q.push(now->right);
            next_level++;
        }
        // 当前层数量--
        cur_remain--;
        // 切换到下一层
        if (cur_remain == 0 && !q.empty()) {
            res.push_back(vector<int>());
            cur_remain = next_level;
            next_level = 0;
        }
    }
    return res;
}


/*
 * 保证当前队列的循环只有当前层的
 */
vector<vector<int>> level_order(TreeNode* root) {
    vector<vector<int>> res;
    if (root == nullptr) {
        return res;
    }
    queue<TreeNode*> q;
    q.push(root);
    // 一次while循环，出掉当前层的所有元素，下一层的元素全部入队
    while (!q.empty()) {
        // 当前层的数量和遍历结果序列
        int level_num = q.size();
        vector<int> curv;
        for (int i = 0; i < level_num; i++) {
            TreeNode* p = q.front();
            // p的左右孩子入队列
            if (p->left) q.push(p->left);
            if (p->right) q.push(p->right);
            // p出队，放到当前层的vector中
            q.pop();
            curv.push_back(p->val);
        }
        // res.insert(res.begin(), curv); // 放到末尾，就是从下到上
        res.push_back(curv);
    }
    return res;
}



int main() {

    vector<int> v(1, 1);
    v.insert(v.begin(), 2);
    cout << v[0] << endl;
    cout << (vector<int>()).size() << endl;

    return 0;
}
