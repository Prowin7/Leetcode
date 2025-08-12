class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int n = nums.size();
        int i = 0; // slow pointer
        int j = 0; // fast pointer

        while (j < n) {
            if (nums[j] != 0) {
                swap(nums[i], nums[j]);
                i++;
            }
            j++;
        }
    }
};
