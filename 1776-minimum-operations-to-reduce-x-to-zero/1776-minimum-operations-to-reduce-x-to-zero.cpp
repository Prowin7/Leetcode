class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int n = nums.size();

        int total = 0;
        for (auto it : nums)
            total += it;
        int target = total - x;
        if (target < 0)
            return -1;
        if (target == 0)
            return n;
        int i = 0, j = 0;
        int sum = 0;
        int maxLen = -1;
        while (j < n) {
            sum += nums[j];
            while (sum > target) {
                sum -= nums[i];
                i++;
            }
            if (sum == target) {
                maxLen = max(maxLen, j - i + 1);
            }
            j++;
        }
        if(maxLen==-1) return -1;
        return n - maxLen;
    }
};