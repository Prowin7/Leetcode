class Solution {
    void backtrack(int ind,int k,int n,vector<int>&cur){
        if(cur.size()==k){
            ans.push_back(cur);
            return ;
        }
        for(int i=ind;i<=n;i++){
            cur.push_back(i);
            backtrack(i+1,k,n,cur);
            cur.pop_back();
        }
    }
public:
    vector<vector<int>> ans;
    vector<vector<int>> combine(int n, int k) {
        vector<int> cur;
        backtrack(1,k,n,cur);
        return ans;
    }
};