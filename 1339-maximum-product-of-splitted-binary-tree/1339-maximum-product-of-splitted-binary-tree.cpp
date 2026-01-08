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
    long long totalSum = 0;
    int mod = 1e9+7;
    long long ans = INT_MIN;
    long long sum(TreeNode* root){
        if(root==NULL) return 0;
        return root->val+sum(root->left)+sum(root->right);
    }

    long long dfs(TreeNode* root){
        if(root==NULL) return 0;
        long long left = dfs(root->left);
        long long right = dfs(root->right);
        long long subSum=  root->val+left+right;
        ans = max(ans,(totalSum-subSum)*subSum);
        return subSum;
    }

public:
    int maxProduct(TreeNode* root) {
    totalSum=sum(root);  
    dfs(root);
    return ans%mod;
       
    }
};