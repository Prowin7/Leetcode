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
public:
    int maxLevelSum(TreeNode* root) {
        queue<TreeNode*> q;
        int level=1;
        long long maxSum=LLONG_MIN;
        int ans = 1;

        q.push(root);
        while(!q.empty()){
            int s=q.size();
            
            long long curSum=0;
            
            for(int i=0;i<s;i++){
                TreeNode* node = q.front();
                curSum+=node->val;
                q.pop();
                if(node->left!=NULL) q.push(node->left);
                if(node->right!=NULL) q.push(node->right);
            }
            if(curSum>maxSum){
                maxSum=curSum;
                ans=level;
            }
            level++;
        }
        return ans;
    }
};