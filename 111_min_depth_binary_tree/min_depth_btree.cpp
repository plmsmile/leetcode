/*
 * 二叉树的最小深度
 * https://plmsmile.github.io/2017/12/29/leetcode-01/#二叉树的最小深度-111
 *
 * @author PLM
 * @date 2018-01-06
 */


#include <iostream>
#include <algorithm>


struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};


/*
 * 最小深度，无左边在右边；无右边在左边。左右都有，选最小的
 */
int minDepth(TreeNode* root) {
    if (root == nullptr) {
        return 0;
    }
    if (root->left == nullptr) {
        return 1 + minDepth(root->right);
    }
    if (root->right == nullptr) {
        return 1 + minDepth(root->left);
    }
    return std::min(minDepth(root->right), minDepth(root->left)) + 1;
}
