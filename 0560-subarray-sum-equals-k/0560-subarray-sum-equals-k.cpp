class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n=nums.size();
        unordered_map<int,int> prefix;
        int sum=0;
        int cnt=0;
        prefix[0]=1;
        for(int i=0;i<n;i++){
            sum+=nums[i];
            
            if(prefix.find(sum-k)!=prefix.end()){
                cnt+=prefix[sum-k];
            }
            prefix[sum]++;
        }
        return cnt;
    }
};