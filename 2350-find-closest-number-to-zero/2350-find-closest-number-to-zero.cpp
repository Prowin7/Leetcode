class Solution {
public:
    int findClosestNumber(vector<int>& nums) {
        int ans = nums[0];
        for (int i = 1; i < nums.size(); i++) {
            int a = abs(nums[i]);
            int b = abs(ans);
            if (a < b) {
                ans = nums[i];
            } else if (a == b) {
                ans = max(ans, nums[i]); // prefer positive if same abs
            }
        }
        return ans;
    }
};
