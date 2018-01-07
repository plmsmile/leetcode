/*
 * 二叉树先序遍历
 * https://leetcode.com/problems/binary-tree-preorder-traversal/description/
 * https://plmsmile.github.io/2017/12/29/leetcode-01/#先序遍历-144
 *
 * @author PLM
 * @date 2018-01-06
 */


#include <vector>
#include <stack>


using namespace std;


struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x): val(x), left(nullptr), right(nullptr) {}
};


/*
 * 先序遍历
 */
vector<int> pre_order(TreeNode* root) {
    vector<int> vpre;
    stack<TreeNode*> st;

    if (root != nullptr) {
        st.push(root);
    }
    while (!st.empty()) {
        TreeNode* p = st.top();
        vpre.push_back(p->val);
        st.pop();
        // 右进、左进；出时：左先出
        if (p->right) {
            st.push(p->right);
        }
        if (p->left) {
            st.push(p->left);
        }
    }

    return vpre;
}


int main() {

    return 0;
}
