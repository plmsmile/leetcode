/*
 * 二叉树中序遍历
 * https://leetcode.com/problems/binary-tree-inorder-traversal/description/
 * https://plmsmile.github.io/2017/12/29/leetcode-01/#中序遍历-94
 *
 * @author PLM
 * @date 2018-01-07
 */

#include <stack>
#include <vector>


using namespace std;


struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};


/*
 * 中序遍历
 */
vector<int> inorder_traversal(TreeNode* root) {
    vector<int> res;
    stack<TreeNode*> st;
    TreeNode* p = root;
    while (p || !st.empty()) {
        if (p) {
            // 根节点入栈
            st.push(p);
            // 扫描左孩子
            p = p->left;
        } else {
            // p位于栈顶，左孩子已经被遍历过或者没有左孩子，直接出栈访问
            p = st.top();
            res.push_back(p->val);
            st.pop();
            // 扫描右孩子
            p = p->right;
        }
    }
    return res;
}
