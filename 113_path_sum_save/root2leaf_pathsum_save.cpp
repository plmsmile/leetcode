/*
 * 二叉树，根节点到叶子节点的路径，和为sum，保存所有的路径
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
 * 递归遍历节点，逐渐添加节点到当前的path，叶子节点，满足要求时，则把path追加到res中
 * Args:
 *      root -- 当前节点
 *      path -- 当前路径
 *      res -- 所有路径
 * Returns:
 *      None
 */
void find_path(TreeNode* root, int sum, vector<int>& path, vector<vector<int>> &res) {
    if (root == nullptr) {
        return;
    }
    // 到达叶子节点
    if (!root->left && !root->right) {
        if (root->val == sum) {
            path.push_back(root->val);
            res.push_back(path);
            path.pop_back();
        }
        return;
    }

    // 当前节点加到path中
    path.push_back(root->val);

    // 更新sum，到左右子树中去添加path
    int newsum = sum - root->val;
    if (root->left) {
        find_path(root->left, newsum, path, res);
    }
    if (root->right) {
        find_path(root->right, newsum, path, res);
    }
    // 当前节点从path中移除
    path.pop_back();
    
}


/*
 * 找到树种从root到leaf的所有和为sum的路径
 */
vector<vector<int>> pathSum(TreeNode* root, int sum) {
    vector<vector<int>> res;
    if (root == nullptr) {
        return res;
    }
    vector<int> path;
    find_path(root, sum, path, res);
    return res;
}





