class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if (!root) return ans;   // handle empty tree

        queue<TreeNode*> q;
        q.push(root);
        q.push(NULL);

        int i = 0;
        ans.push_back(vector<int>()); // create vector for level 0

        while (!q.empty()) {
            TreeNode* curNode = q.front();
            q.pop();

            if (curNode == NULL) {
                if (q.empty()) {
                    break;
                } else {
                    q.push(NULL);
                    i++;
                    ans.push_back(vector<int>()); // create new vector for next level
                }
            } else {
                ans[i].push_back(curNode->val);

                if (curNode->left) q.push(curNode->left);
                if (curNode->right) q.push(curNode->right);
            }
        }

        return ans;
    }
};
