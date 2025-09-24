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
    vector<int> ans;
    
public:

    vector<int> rightSideView(TreeNode* root) {
        if(root==NULL) return {};
        queue<TreeNode*> q;
        q.push(root);
        
        while(!q.empty()){
            int s=q.size();
            vector<int> vec;
            while(s--){
                TreeNode* curNode=q.front();
                q.pop();
                if(curNode->right!=NULL) q.push(curNode->right);
                if(curNode->left!=NULL) q.push(curNode->left);
                vec.push_back(curNode->val);
            }
            ans.push_back(vec[0]);
        }

        return ans;
    }
};