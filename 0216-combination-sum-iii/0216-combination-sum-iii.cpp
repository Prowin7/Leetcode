class Solution {
public:
void func(int start,int sum,int s,int target,vector<int> & vec,vector<vector<int>>& ans){
    if(vec.size()==s){
        if(sum==target)
            ans.push_back(vec);
        return;
    }
    if(sum>target||vec.size()>s||start>9) return;

    vec.push_back(start);
    func(start+1,sum+start,s,target,vec,ans);
    vec.pop_back();
    func(start+1,sum,s,target,vec,ans);
    
}
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> ans;
        vector<int> vec;
        func(1,0,k,n,vec,ans);
        return ans;
    }
};