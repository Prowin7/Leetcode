class Solution {
    int lowerBound(vector<int>& nums, int target) {
        int lo = 0, hi = nums.size() - 1;
        while (hi - lo > 1) {
            int mid = lo + (hi - lo) / 2;
            if (nums[mid] < target)
                lo = mid + 1;
            else
                hi = mid;
        }
        // Final checks
        if (nums[lo] >= target) return lo;
        if (nums[hi] >= target) return hi;
        return nums.size(); // not found
    }

    int upperBound(vector<int>& nums, int target) {
        int lo = 0, hi = nums.size() - 1;
        while (hi - lo > 1) {
            int mid = lo + (hi - lo) / 2;
            if (nums[mid] <= target)
                lo = mid + 1;
            else
                hi = mid;
        }
        // Final checks
        if (nums[lo] > target) return lo;
        if (nums[hi] > target) return hi;
        return nums.size(); // not found
    }

public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int n = nums.size();
        if (n == 0) return {-1, -1};

        int first = lowerBound(nums, target);
        int last = upperBound(nums, target) - 1;

        if (first < n && last < n && nums[first] == target)
            return {first, last};
        return {-1, -1};
    }
};
