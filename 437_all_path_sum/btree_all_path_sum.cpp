/*
 * 给一个sum值，求二叉树中的所有路径和，任意起点和终点。
 * https://leetcode.com/problems/path-sum-iii/description/
 * https://plmsmile.github.io/2017/12/29/leetcode-01/#二叉树路径求和
 *
 * @author PLM
 * @date 2018-01-21
 */


#include <vector>

using namespace std;


struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};


/*
 * 以root为起始节点，向下走，和为sum的路径的条数
 */
int count_from_root(TreeNode* root, int sum) {
    // 空
    if (root == nullptr) return 0;
    // 直接根节点就满足，无需看孩子
    int c = 0;
    if (sum == root->val) {
        // 相等
        c = 1;
    } else if (!root->left && !root->right) {
        // 无孩子，不相等
        return 0;
    }
    // c+左右孩子的
    int newsum = sum - root->val;
    return c + count_from_root(root->left, newsum) + count_from_root(root->right, newsum);
}


/*
 * 找到树中，和为sum的所有路径数量
 */
int pathSum(TreeNode* root, int sum) {
    if (root == nullptr) {
        return 0;
    }
    queue<TreeNode*> q;
    q.push(root);
    int count = 0;
    // 前序遍历
    while (!q.empty()) {
        TreeNode* now = q.front();
        q.pop();
        count += count_from_root(now, sum);
        if (now->left) q.push(now->left);
        if (now->right) q.push(now->right);
    }
    return count;
}
