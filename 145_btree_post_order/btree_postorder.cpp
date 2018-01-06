/*
 * 二叉树的后序遍历
 *
 * @author PLM
 * @date 2018-01-06
 */


#include <iostream>
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
 * 后序遍历
 */
vector<int> post_order(TreeNode* root) {
    vector<int> res;
    stack<TreeNode*> st;
    // 前一次访问的节点
    TreeNode* pre = nullptr;
    if (root != nullptr) {
        st.push(root);
    }

    while (!st.empty()) {
        TreeNode* p = st.top();
        // 0. 检查是否可以直接访问p
        bool no_child = (p->left == nullptr && p->right == nullptr);
        bool pre_is_child = (pre == p->left || pre == p->right);
        if (nullptr == pre) {
            pre_is_child = false;
        }
        
        // 1. p无左右子树 or 左右子树刚刚遍历完，直接访问p
        if (no_child || pre_is_child) {
            res.push_back(p->val);
            pre = p;
            st.pop();
        } 
        // 2. 需要将p的左右孩子入栈
        else {
            if (p->right) {
                st.push(p->right);
            }
            if (p->left) {
                st.push(p->left);
            }
        }
    }
    return res;
}


int main() {
    
    return 0;
}

