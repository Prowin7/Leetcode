class Solution {
public:
    int maxDistinctElements(vector<int>& nums, int k) {
        int n = nums.size();
        sort(nums.begin(),nums.end());
        int cnt = 0;
        int prev = INT_MIN;
        for (int i = 0; i < n; i++) {
            int low = nums[i] - k;
            int high = nums[i] + k;
            int choose = max(low, prev + 1);
             if (choose <= high) {
                cnt++;
                prev = choose;
            }
        }
        return cnt;
    }
};