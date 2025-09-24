class Solution {
    bool same(TreeNode* p, TreeNode* q) {
        if (p == NULL && q == NULL) return true;    // both empty
        if (p == NULL || q == NULL) return false;   // one empty, one not

        // both non-null → compare values & recurse
        if (p->val != q->val) return false;

        return same(p->left, q->left) && same(p->right, q->right);
    }
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        return same(p, q);
    }
};
