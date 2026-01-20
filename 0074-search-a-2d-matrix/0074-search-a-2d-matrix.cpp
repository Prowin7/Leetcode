class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix.size();
        int m = matrix[0].size();

        int lo = -1;
        int hi = n * m;

        while (hi - lo > 1) {
            int mid = (hi + lo) / 2;
            int row = mid / m;
            int col = mid % m;

            if (matrix[row][col] <= target)
                lo = mid;
            else
                hi = mid;
        }

        if (lo == -1) return false;
        int row = lo / m;
        int col = lo % m;

        return matrix[row][col] == target;
    }
};
