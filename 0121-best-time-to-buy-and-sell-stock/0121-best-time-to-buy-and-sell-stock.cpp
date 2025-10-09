class Solution {
public:
    int maxProfit(vector<int>& nums) {
        int n = nums.size();
        int buy = nums[0];
        int sell = nums[1];
        int profit = 0;
        
        int i=0,j=1;
        for(int i=1;i<n;i++){
            sell=nums[i];
            profit=max(sell-buy,profit);
            buy=min(buy,nums[i]);
        }
        return profit;
    }

};