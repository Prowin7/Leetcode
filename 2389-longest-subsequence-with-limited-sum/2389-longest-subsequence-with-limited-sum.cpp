class Solution {
    int search(vector<int>& nums, int target){
        int n = nums.size();
        int lo = 0;
        int hi = n-1;
        while(lo<=hi){
            int  mid = lo+(hi-lo)/2;
            if(nums[mid]<=target) lo=mid+1;
           
            else hi = mid-1;
        }
        return lo;
    }
public:
    vector<int> answerQueries(vector<int>& nums, vector<int>& queries) {
        vector<int> ans(queries.size(),0);
        sort(nums.begin(), nums.end());
        for(int i=1;i<nums.size();i++){
            nums[i] += nums[i-1];
        }
        for(int i=0;i<queries.size();i++){
            ans[i] = search(nums,queries[i]);

        }
        return ans;
    }
};