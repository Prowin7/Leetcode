class Solution {
public:
    int binary_search(vector<int>& prefix, int target) {
        int lo = -1;                
        int hi = prefix.size();       
        
        while (hi - lo > 1) {
            int mid = lo + (hi - lo) / 2;
            
            if (prefix[mid] <= target)  
                lo = mid;              
            else
                hi = mid;              // move left
        }
        
        return lo+1;
    }
    
    vector<int> answerQueries(vector<int>& nums, vector<int>& queries) {
        sort(nums.begin(), nums.end());
        
        // Build prefix sum
        for (int i = 1; i < nums.size(); i++)
            nums[i] += nums[i - 1];
        
        vector<int> ans;
        for (int q : queries) {
            ans.push_back(binary_search(nums, q));
        }
        
        return ans;
    }
};
