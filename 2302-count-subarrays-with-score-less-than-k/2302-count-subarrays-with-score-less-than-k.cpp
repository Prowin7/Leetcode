class Solution {
public:
    long long countSubarrays(vector<int>& nums, long long k) {
        int n=nums.size();
        int left=0,right=0;
        long long sum=0,score=0,cnt=0;
        while(right<n){
            sum+=nums[right];
           
            
           
            while(sum*(right-left+1)>=k){
                
                
                sum-=nums[left];
                left++;
                
            }
            cnt+=(right-left+1);
             right++;
        }
        return cnt;
    }
};