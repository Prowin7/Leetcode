class Solution {
    int atmost(vector<int>&nums,int goal){
        int n=nums.size();
        int i=0,j=0,sum=0,cnt=0;
        while(j<n){
            goal-=nums[j];
            while(goal<0&&i<=j){
                goal+=nums[i];
                i++;
            }
            cnt+=(j-i)+1;
            j++;
        }
        return cnt;
    }
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        return atmost(nums,goal)-atmost(nums,goal-1); 
        // exact goal = atmostSum(goal)-atmostSum(goal-1)
    }
};