/*
 * 有序链表转化为平衡的二叉树
 * https://leetcode.com/problems/convert-sorted-list-to-binary-search-tree/description/
 * https://plmsmile.github.io/2017/12/29/leetcode-01/#有序链表转平衡bst-109
 *
 * @author PLM
 * @date 2018-01-22
 */

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};


struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};


/*
 * 递归中序创建树
 * Args:
 *      head -- 链表的起始节点
 *      start -- 起始节点编号，从1开始
 *      end -- 结束节点编号
 * Returns:
 *      root -- 树的根节点
 */
TreeNode* create_tree(ListNode* head, int start, int end) {
    // 0. 递归终止条件
    if (head == nullptr || start > end) {
        return nullptr;
    }
    
    // 1. 找到中间节点，构建根节点
    int mid = (end + start) / 2;
    ListNode* node = head;
    for (int i = start + 1; i <= mid; i++) {
        node = node->next;
    }
    TreeNode* root = new TreeNode(node->val);

    // 2. 递归构造左右子树
    root->left = create_tree(head, start, mid - 1);
    root->right = create_tree(node->next, mid + 1, end);

    return root;
}


/*
 * 把有序链表转化为平衡的BST
 * Args:
 *      head -- 链表
 * Returns:
 *      root -- 头结点
 */ 
TreeNode* sortedListToBST(ListNode* head) {
    if (head == nullptr) {
        return nullptr;
    }

    int size = 0;
    ListNode* p = head;
    while (p) {
        ++size;
        p = p->next;
    }
    
    return create_tree(head, 1, size);
}


int main() {

    return 0;
}
