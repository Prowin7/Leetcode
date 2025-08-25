class Solution {
    // Find pivot (index of smallest element)
    int pivot(vector<int>& nums) {
        int lo = 0, hi = nums.size() - 1;
        while (hi - lo > 1) {
            int mid = lo + (hi - lo) / 2;
            if (nums[mid] > nums[hi]) lo = mid;
            else hi = mid;
        }
        return (nums[hi] < nums[lo] ? hi : lo);
    }

    // Binary search in range [lo, hi]
    int binarySearch(int lo, int hi, vector<int>& nums, int target) {
        if (lo > hi) return -1; // empty segment
        while (hi - lo > 1) {
            int mid = lo + (hi - lo) / 2;
            if (nums[mid] == target) return mid;
            else if (nums[mid] < target) lo = mid + 1;
            else hi = mid - 1;
        }
        // Check remaining elements safely
        if (lo >= 0 && lo < nums.size() && nums[lo] == target) return lo;
        if (hi >= 0 && hi < nums.size() && nums[hi] == target) return hi;
        return -1;
    }

public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        if (n == 0) return -1;
        if (n == 1) return nums[0] == target ? 0 : -1;

        int pivotInd = pivot(nums);

        int ind = binarySearch(0, pivotInd - 1, nums, target);
        if (ind != -1) return ind;

        ind = binarySearch(pivotInd, n - 1, nums, target);
        return ind;
    }
};
