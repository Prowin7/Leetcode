class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        if (n == 0) return;          // nothing to rotate

        k %= n;                      // handles cases where k ≥ n
        if (k == 0) return;          // already in the correct position

        reverse(nums.begin(), nums.end());          // step 1
        reverse(nums.begin(), nums.begin() + k);    // step 2
        reverse(nums.begin() + k, nums.end());      // step 3
    }
};
