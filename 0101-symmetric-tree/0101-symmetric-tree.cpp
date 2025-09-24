class Solution {
    bool func(TreeNode* p, TreeNode* q) {
        if (p == NULL && q == NULL) return true;
        if (p == NULL || q == NULL) return false;

        if (p->val != q->val) return false;

        return func(p->left, q->right) && func(p->right, q->left);
    }
public:
    bool isSymmetric(TreeNode* root) {
        if (root == NULL) return true;
        return func(root->left, root->right);
    }
};
