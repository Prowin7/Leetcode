/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {

    vector<int> inorder;

    void dfs(TreeNode* root){
        if(root==NULL) return;
        dfs(root->left);
        inorder.push_back(root->val);
        dfs(root->right);
    }

    TreeNode* constructTree(int left, int right){
        if(left>right) return nullptr;
        int mid = left + (right-left)/2;
        TreeNode* root = new TreeNode(inorder[mid]);
        root->left = constructTree(left,mid-1);
        root->right = constructTree(mid+1,right);
        return root;
    }

public:
    TreeNode* balanceBST(TreeNode* root) {
        dfs(root);
        return constructTree(0,inorder.size()-1);

    }
};