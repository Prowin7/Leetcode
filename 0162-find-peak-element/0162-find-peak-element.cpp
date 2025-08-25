class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int lo = 0, hi = nums.size() - 1;
        while (hi - lo > 1) {
            int mid = lo + (hi - lo) / 2;
            
            // Check bounds first
            if (mid + 1 < nums.size() && nums[mid] < nums[mid + 1]) {
                lo = mid + 1; // slope going up, move right
            } else {
                hi = mid;     // slope going down, move left
            }
        }
        // Final comparison between remaining elements
        return (nums[lo] < nums[hi]) ? hi : lo;
    }
};
